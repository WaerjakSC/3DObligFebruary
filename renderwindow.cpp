#include "renderwindow.h"
#include "camera.h"
#include "gameobject.h"
#include "mainwindow.h"
#include "shader.h"
#include <QDebug>
#include <QKeyEvent>
#include <QMatrix4x4>
#include <QOpenGLContext>
#include <QOpenGLDebugLogger>
#include <QOpenGLFunctions>
#include <QStatusBar>
#include <QTimer>

RenderWindow::RenderWindow(const QSurfaceFormat &format, MainWindow *mainWindow)
    : mContext(nullptr), mInitialized(false), mMainWindow(mainWindow)

{
    //This is sent to QWindow:
    setSurfaceType(QWindow::OpenGLSurface);
    setFormat(format);
    //Make the OpenGL context
    mContext = new QOpenGLContext(this);
    //Give the context the wanted OpenGL format (v4.1 Core)
    mContext->setFormat(requestedFormat());
    if (!mContext->create())
    {
        delete mContext;
        mContext = nullptr;
        qDebug() << "Context could not be made - quitting this application";
    }

    mCamera = new Camera(Vector3D(0, 2, -2));
    ball = new OctahedronBall(3);
    sceneOne = new Sceneone;
    sceneTwo = new Scenetwo;
    object = new GameObject;

    //Make the gameloop timer:
    mRenderTimer = new QTimer(this);
}

RenderWindow::~RenderWindow()
{
    //cleans up the GPU memory
    glDeleteVertexArrays(1, &mVAO);
    glDeleteBuffers(1, &mVBO);
}

Camera *RenderWindow::getCamera()
{
    if (mCamera != nullptr)
    {
        return mCamera;
    }
    else
        return 0;
}

/// Sets up the general OpenGL stuff and the buffers needed to render a triangle
void RenderWindow::init()
{
    connect(mRenderTimer, SIGNAL(timeout()), this, SLOT(render()));
    if (!mContext->makeCurrent(this))
    {
        qDebug() << "makeCurrent() failed";
        return;
    }
    if (!mInitialized)
        mInitialized = true;

    initializeOpenGLFunctions();
    startOpenGLDebugger();

    glEnable(GL_DEPTH_TEST);              //enables depth sorting - must use
    glClearColor(0.4f, 0.4f, 0.4f, 1.0f); //color used in glClear GL_COLOR_BUFFER_BIT

    // Make sure these two files are in the main folder, or update this if you move them
    mShaderProgram = new Shader("plainvertex.vert",
                                "plainfragment.frag");

    //Vertex Array Object - VAO
    glGenVertexArrays(1, &mVAO);
    glBindVertexArray(mVAO);

    //enable the matrixUniform
    // NB: enable in shader and in render() function also to use matrix
    mMatrixUniform = glGetUniformLocation(mShaderProgram->getProgram(), "matrix");
    mPMatrixUniform = glGetUniformLocation(mShaderProgram->getProgram(), "pmatrix");
    mVMatrixUniform = glGetUniformLocation(mShaderProgram->getProgram(), "vmatrix");

    glBindVertexArray(0);

    // Initialize all the objects in the scene
    mCamera->init(mVMatrixUniform, mPMatrixUniform, mShaderProgram);
    ball->init(mMatrixUniform);
    //    sceneOne->init(mMatrixUniform);
    //    sceneTwo->init(mMatrixUniform);
    object->init(mMatrixUniform);

    // Sets the FOV.
    setFOV(FOV);

    glUniformMatrix4fv(mPMatrixUniform, 1, GL_FALSE, mCamera->GetPMatrix()->constData());
}

///Called each frame - doing the rendering
void RenderWindow::render()
{
    mTimeStart.restart(); //restart FPS clock
    mContext->makeCurrent(this);

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glUseProgram(mShaderProgram->getProgram());

    mCamera->render();
    //    ball->draw();
    //    sceneOne->draw();
    //    sceneTwo->draw();
    object->draw();
    calculateFramerate();
    mContext->swapBuffers(this);
}

void RenderWindow::setFOV(float FOV)
{
    if (mCamera != nullptr)
    {
        mCamera->SetPersp(FOV, 4.0 / 3.0, 0.1f, 10.f);
    }
}
//The way this is set up is that we start the clock before doing the draw call,
//and check the time right after it is finished (done in the render function)
//This will approximate what framerate we COULD have.
//The actual frame rate on your monitor is limited by the vsync and is probably 60Hz
void RenderWindow::calculateFramerate()
{
    long nsecElapsed = mTimeStart.nsecsElapsed();
    static int frameCount{0}; //counting actual frames for a quick "timer" for the statusbar

    if (mMainWindow) //if no mainWindow, something is really wrong...
    {
        ++frameCount;
        if (frameCount > 30) //once pr 30 frames = update the message twice pr second (on a 60Hz monitor)
        {
            //showing some statistics in status bar
            mMainWindow->statusBar()->showMessage(" Time pr FrameDraw: " +
                                                  QString::number(nsecElapsed / 1000000.f, 'g', 4) + " ms  |  " +
                                                  "FPS (approximated): " + QString::number(1E9 / nsecElapsed, 'g', 7));
            frameCount = 0; //reset to show a new message in 60 frames
        }
    }
}

/// Uses QOpenGLDebugLogger if this is present
/// Reverts to glGetError() if not
void RenderWindow::checkForGLerrors()
{
    if (mOpenGLDebugLogger)
    {
        const QList<QOpenGLDebugMessage> messages = mOpenGLDebugLogger->loggedMessages();
        for (const QOpenGLDebugMessage &message : messages)
            qDebug() << message;
    }
    else
    {
        GLenum err = GL_NO_ERROR;
        while ((err = glGetError()) != GL_NO_ERROR)
        {
            qDebug() << "glGetError returns " << err;
        }
    }
}

/// Tries to start the extended OpenGL debugger that comes with Qt
void RenderWindow::startOpenGLDebugger()
{
    QOpenGLContext *temp = this->context();
    if (temp)
    {
        QSurfaceFormat format = temp->format();
        if (!format.testOption(QSurfaceFormat::DebugContext))
            qDebug() << "This system can not use QOpenGLDebugLogger, so we revert to glGetError()";

        if (temp->hasExtension(QByteArrayLiteral("GL_KHR_debug")))
        {
            qDebug() << "System can log OpenGL errors!";
            mOpenGLDebugLogger = new QOpenGLDebugLogger(this);
            if (mOpenGLDebugLogger->initialize()) // initializes in the current context
                qDebug() << "Started OpenGL debug logger!";
        }
    }
}

void RenderWindow::keyPressEvent(QKeyEvent *event)
{
    const float SPEED{1.f};

    if (event->key() == Qt::Key_Escape) //Shuts down whole program
    {
        mMainWindow->close();
    }

    switch (event->key())
    {
    case Qt::Key::Key_W:
        ball->addForward(-SPEED);
        break;
    case Qt::Key::Key_S:
        ball->addForward(SPEED);
        break;
    case Qt::Key::Key_A:
        ball->strafe(SPEED);
        break;
    case Qt::Key::Key_D:
        ball->strafe(-SPEED);
        break;
    }
}

void RenderWindow::exposeEvent(QExposeEvent *)
{
    if (!mInitialized)
        init();

    //This is just to support modern screens with "double" pixels
    const qreal retinaScale = devicePixelRatio();
    glViewport(0, 0, static_cast<GLint>(width() * retinaScale), static_cast<GLint>(height() * retinaScale));

    //If the window actually is exposed to the screen we start the main loop
    //isExposed() is a function in QWindow
    if (isExposed())
    {
        //This timer runs the actual MainLoop
        //16 means 16ms = 60 Frames pr second (should be 16.6666666 to be exact..)
        mRenderTimer->start(16);
        mTimeStart.start();
    }
}
