#include "mainwindow.h"
#include "objectselect.h"
#include "renderwindow.h"
#include "slidergroup.h"
#include "ui_mainwindow.h"
#include "vector3d.h"
#include <QDebug>
#include <QGridLayout>
#include <QSurfaceFormat>
#include <QTabWidget>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    init();
}

MainWindow::~MainWindow()
{
    delete mRenderWindow;
    delete ui;
}

void MainWindow::init()
{
    //This will contain the setup of the OpenGL surface we will render into
    QSurfaceFormat format;

    //OpenGL v 4.1 - (Ole Flatens Mac does not support higher than this...)
    //you can try other versions, but then have to update RenderWindow and Shader
    //to inherit from other than QOpenGLFunctions_4_1_Core
    format.setVersion(4, 1);
    //Using the main profile for OpenGL - no legacy code permitted
    format.setProfile(QSurfaceFormat::CoreProfile);
    //A QSurface can be other types that OpenGL
    format.setRenderableType(QSurfaceFormat::OpenGL);

    //This should activate OpenGL debug Context used in RenderWindow::startOpenGLDebugger().
    //This line (and the startOpenGLDebugger() and checkForGLerrors() in RenderWindow class)
    //can be deleted, but it is nice to have OpenGL debug info!
    format.setOption(QSurfaceFormat::DebugContext);

    // The renderer will need a depth buffer - (not requiered to set in glfw-tutorials)
    format.setDepthBufferSize(24);

    //Just prints out what OpenGL format we will get
    // - this can be deleted
    qDebug() << "Requesting surface format: " << format;

    //We have a format for the OpenGL window, so let's make it:
    mRenderWindow = new RenderWindow(format, this);

    //Check if renderwindow did initialize, else prints error and quit
    if (!mRenderWindow->context())
    {
        qDebug() << "Failed to create context. Can not continue. Quits application!";
        delete mRenderWindow;
        return;
    }

    //The OpenGL RenderWindow got made, so continuing the setup:
    //We put the RenderWindow inside a QWidget so we can put in into a
    //layout that is made in the .ui-file
    mRenderWindowContainer = QWidget::createWindowContainer(mRenderWindow);

    QWidget *firstTab = new QWidget;
    QHBoxLayout *topBox = new QHBoxLayout; // Horizontal Box to contain LookAt sliders and grid
    firstTab->setLayout(topBox);

    // Creating the slider setup
    SliderGroup *sliders = new SliderGroup(Qt::Orientation::Horizontal, "LookAt", 0, mRenderWindow->getCamera());
    topBox->addWidget(sliders, Qt::AlignTop);
    QGroupBox *grid = createMatrix(mRenderWindow->getCamera()); // Grid to contain LookAt matrix
    topBox->addWidget(grid);

    QWidget *secondTab = new QWidget;
    QHBoxLayout *topBox2 = new QHBoxLayout;
    secondTab->setLayout(topBox2);
    // Creating the object selection tab
    ObjectSelect *objectselect = new ObjectSelect(nullptr, mRenderWindow->getCamera(), mRenderWindow->getGameInstance());
    topBox2->addWidget(objectselect);

    QTabWidget *tabs = new QTabWidget;
    tabs->addTab(firstTab, QString("LookAt"));
    tabs->addTab(secondTab, QString("Object Select"));
    ui->OpenGLLayout->addWidget(tabs);

    // Update the lookAt grid with new values each time the camera is moved
    connect(mRenderWindow->getCamera(), SIGNAL(lookAtChanged()), this, SLOT(updateLabelMatrix()));

    //OpenGLLayout is made in the .ui-file!
    ui->OpenGLLayout->addWidget(mRenderWindowContainer, Qt::AlignBottom);

    //sets the keyboard input focus to the RenderWindow when program starts
    // - can be deleted, but then you have to click inside the renderwindow to get the focus
    mRenderWindowContainer->setFocus();
}

QGroupBox *MainWindow::createMatrix(Camera *cam)
{
    QGridLayout *gridBox = new QGridLayout;
    QGroupBox *hbox = new QGroupBox(tr("LookAt Matrix"));
    hbox->setAlignment(Qt::AlignCenter);
    gridBox->setAlignment(Qt::AlignCenter);

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            float vM = cam->getLookMatrix().at(j, i);
            matrixLabels.push_back(new QLabel(QString::number(vM, 'f', 3)));
            matrixLabels.at(j + i * 4)->setFrameStyle(QFrame::Box | QFrame::Plain);
            gridBox->addWidget(matrixLabels.at(j + (i * 4)), i, j);
        }
        gridBox->setColumnMinimumWidth(i, 55);
    }
    gridBox->setContentsMargins(10, 10, 10, 10);
    gridBox->setSpacing(13);
    hbox->setMaximumHeight(170);

    hbox->setLayout(gridBox);
    return hbox;
}
void MainWindow::updateLabelMatrix()
{
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            // Update the labels with 3 decimal precision.
            matrixLabels.at(j + (i * 4))->setText(QString::number(mRenderWindow->getCamera()->getLookMatrix().at(j, i), 'f', 3));
        }
    }
}
