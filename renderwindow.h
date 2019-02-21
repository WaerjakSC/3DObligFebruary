#ifndef RENDERWINDOW_H
#define RENDERWINDOW_H

#include "camera.h"
#include "interactiveobject.h"
#include "octahedronball.h"
#include "sceneone.h"
#include "trianglesurface.h"
#include "vertex.h"
#include "xyz.h"
#include <QElapsedTimer>
#include <QOpenGLFunctions_4_1_Core>
#include <QTimer>
#include <QWindow>
#include <vector>

class QOpenGLContext;
class Shader;
class MainWindow;

/// This inherits from QWindow to get access to the Qt functionality and
/// OpenGL surface.
/// We also inherit from QOpenGLFunctions, to get access to the OpenGL functions
/// This is the same as using glad and glw from general OpenGL tutorials
class RenderWindow : public QWindow, protected QOpenGLFunctions_4_1_Core
{
    Q_OBJECT
public:
    RenderWindow(const QSurfaceFormat &format, MainWindow *mainWindow);
    ~RenderWindow() override;

    QOpenGLContext *context() { return mContext; }

    Camera *getCamera();
    void exposeEvent(QExposeEvent *) override;

    //    void error(const QString &msg);

private slots:
    void render();

private:
    void init();
    std::vector<Vertex> m_Vertices;

    float w, h;
    QOpenGLContext *mContext;
    bool mInitialized;

    Shader *mShaderProgram;
    GLint mMatrixUniform;
    GLint mPMatrixUniform;
    GLint mVMatrixUniform;

    GLuint mVAO;
    GLuint mVBO;

    float FOV{45.f}; // Field Of View. Need to recalculate projection matrix whenever this changes.
    jl::Camera *mCamera;
    Sceneone *sceneOne;
    OctahedronBall *ball;

    void setFOV(float FOV = 60.f);

    QTimer *mRenderTimer;     //timer that drives the gameloop
    QElapsedTimer mTimeStart; //time variable that reads the actual FPS

    MainWindow *mMainWindow; //points back to MainWindow to be able to put info in StatusBar

    class QOpenGLDebugLogger *mOpenGLDebugLogger{nullptr};

    void checkForGLerrors();

    void calculateFramerate();

    void startOpenGLDebugger();

protected:
    //The QWindow that we inherit from has these functions to capture
    // mouse and keyboard. Uncomment to use
    //
    //    void mousePressEvent(QMouseEvent *event) override{}
    //    void mouseMoveEvent(QMouseEvent *event) override{}
    void keyPressEvent(QKeyEvent *event) override;
    //    void keyReleaseEvent(QKeyEvent *event) override{}
    //    void wheelEvent(QWheelEvent *event) override{}
};

#endif // RENDERWINDOW_H
