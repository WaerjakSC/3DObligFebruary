#include "slidergroup.h"
#include "vector3d.h"
#include <QBoxLayout>
#include <QGridLayout>
#include <QPushButton>
#include <QSlider>
SliderGroup::SliderGroup(Qt::Orientation orientation, const QString &title, QWidget *parent, Camera *cam) : QGroupBox(title, parent)
{
    setAlignment(Qt::AlignCenter);
    QHBoxLayout *grid = new QHBoxLayout;
    m_Camera = cam;
    grid->addWidget(createEyeGroup(orientation));
    grid->addWidget(createAtGroup(orientation));
    grid->addWidget(createUpGroup(orientation));
    //    grid->addWidget(createMatrix());

    // Connect all the sliders to the labels, converting them from int to double in the process (see qdoubleslider.h)
    for (int i = 0; i < 3; i++)
    {
        // Connect sliders to the numbers underneath
        connect(eyeSliders.at(i), SIGNAL(doubleValueChanged(double)), eyeNum.at(i), SLOT(setNum(double)));
        connect(atSliders.at(i), SIGNAL(doubleValueChanged(double)), atNum.at(i), SLOT(setNum(double)));
        connect(upSliders.at(i), SIGNAL(doubleValueChanged(double)), upNum.at(i), SLOT(setNum(double)));

        // Set up the connections between the camera class and sliders
        connect(eyeSliders.at(i), SIGNAL(doubleValueChanged(double)), this, SLOT(setPosition()));
        connect(atSliders.at(i), SIGNAL(doubleValueChanged(double)), this, SLOT(setTarget()));
        connect(upSliders.at(i), SIGNAL(doubleValueChanged(double)), this, SLOT(setUp()));
    }
    setMaximumHeight(170);
    //    setMaximumWidth(600);
    setMinimumSize(600, 180);
    setLayout(grid);
    connect(cam, SIGNAL(posChanged(Vec3)), this, SLOT(setPosSliders(Vec3)));
    connect(cam, SIGNAL(tarChanged(Vec3)), this, SLOT(setTarSliders(Vec3)));
    connect(cam, SIGNAL(upChanged(Vec3)), this, SLOT(setUpSliders(Vec3)));
}
QGroupBox *SliderGroup::createEyeGroup(Qt::Orientation orientation)
{
    QGroupBox *groupBox = new QGroupBox(tr("Eye:"));
    groupBox->setAlignment(Qt::AlignCenter); // Align the title to center
    // Initialize the sliders and labels with the correct default values from the main camera.
    for (int i = 0; i < 3; i++)
    {
        eyeSliders.push_back(new QDoubleSlider(groupBox, orientation, m_Camera->getPosition().at(i)));
        eyeSliders.at(i)->setFocusPolicy(Qt::StrongFocus);
        eyeSliders.at(i)->setTickPosition(QSlider::TicksBothSides);
        eyeNum.push_back(new QLabel(QString::number(eyeSliders.at(i)->getDoubleValue())));
        eyeNum.at(i)->setAlignment(Qt::AlignCenter);
    }
    eyeXYZ.push_back(new QLabel(tr("X: ")));
    eyeXYZ.push_back(new QLabel(tr("Y: ")));
    eyeXYZ.push_back(new QLabel(tr("Z: ")));
    QVBoxLayout *vbox = new QVBoxLayout;
    std::vector<QHBoxLayout *> hbox;
    for (int i = 0; i < 3; i++)
    {
        hbox.push_back(new QHBoxLayout);
        hbox.at(i)->addWidget(eyeXYZ.at(i));
        hbox.at(i)->addWidget(eyeSliders.at(i));
        vbox->addLayout(hbox.at(i));
        vbox->addWidget(eyeNum.at(i));
    }
    vbox->addStretch(1);
    groupBox->setLayout(vbox);
    return groupBox;
}

QGroupBox *SliderGroup::createAtGroup(Qt::Orientation orientation)
{
    QGroupBox *groupBox = new QGroupBox(tr("At:"));
    groupBox->setAlignment(Qt::AlignCenter);
    // Initialize the sliders and labels with the correct default values from the main camera.
    for (int i = 0; i < 3; i++)
    {
        atSliders.push_back(new QDoubleSlider(groupBox, orientation, m_Camera->getTarget().at(i)));
        atSliders.at(i)->setFocusPolicy(Qt::StrongFocus);
        atSliders.at(i)->setTickPosition(QSlider::TicksBothSides);
        atNum.push_back(new QLabel(QString::number(atSliders.at(i)->getDoubleValue())));
        atNum.at(i)->setAlignment(Qt::AlignCenter);
    }
    atXYZ.push_back(new QLabel(tr("X: ")));
    atXYZ.push_back(new QLabel(tr("Y: ")));
    atXYZ.push_back(new QLabel(tr("Z: ")));
    QVBoxLayout *vbox = new QVBoxLayout;
    std::vector<QHBoxLayout *> hbox;
    for (int i = 0; i < 3; i++)
    {
        hbox.push_back(new QHBoxLayout);
        hbox.at(i)->addWidget(atXYZ.at(i));
        hbox.at(i)->addWidget(atSliders.at(i));
        vbox->addLayout(hbox.at(i));
        vbox->addWidget(atNum.at(i));
    }
    vbox->addStretch(1);
    groupBox->setLayout(vbox);
    return groupBox;
}

QGroupBox *SliderGroup::createUpGroup(Qt::Orientation orientation)
{
    QGroupBox *groupBox = new QGroupBox(tr("Up:"));
    groupBox->setAlignment(Qt::AlignCenter);

    // Initialize the sliders and labels with the correct default values from the main camera.
    for (int i = 0; i < 3; i++)
    {
        upSliders.push_back(new QDoubleSlider(groupBox, orientation, m_Camera->getUp().at(i)));
        upSliders.at(i)->setFocusPolicy(Qt::StrongFocus);
        upSliders.at(i)->setTickPosition(QSlider::TicksBothSides);
        upSliders.at(i)->setMaximum(10);
        upSliders.at(i)->setMinimum(-10);
        upNum.push_back(new QLabel(QString::number(upSliders.at(i)->getDoubleValue())));
        upNum.at(i)->setAlignment(Qt::AlignCenter);
    }
    upXYZ.push_back(new QLabel(tr("X: ")));
    upXYZ.push_back(new QLabel(tr("Y: ")));
    upXYZ.push_back(new QLabel(tr("Z: ")));
    QVBoxLayout *vbox = new QVBoxLayout;
    std::vector<QHBoxLayout *> hbox;
    for (int i = 0; i < 3; i++)
    {
        hbox.push_back(new QHBoxLayout);
        hbox.at(i)->addWidget(upXYZ.at(i));
        hbox.at(i)->addWidget(upSliders.at(i));
        vbox->addLayout(hbox.at(i));
        vbox->addWidget(upNum.at(i));
    }
    vbox->addStretch(10);
    groupBox->setLayout(vbox);
    return groupBox;
}

void SliderGroup::setPosition()
{
    m_Camera->setPosition(eyeSliders.at(0)->getDoubleValue(), 0);
    m_Camera->setPosition(eyeSliders.at(1)->getDoubleValue(), 1);
    m_Camera->setPosition(eyeSliders.at(2)->getDoubleValue(), 2);
}

void SliderGroup::setTarget()
{
    m_Camera->setTarget(atSliders.at(0)->getDoubleValue(), 0);
    m_Camera->setTarget(atSliders.at(1)->getDoubleValue(), 1);
    m_Camera->setTarget(atSliders.at(2)->getDoubleValue(), 2);
}

void SliderGroup::setUp()
{
    m_Camera->setUp(upSliders.at(0)->getDoubleValue(), 0);
    m_Camera->setUp(upSliders.at(1)->getDoubleValue(), 1);
    m_Camera->setUp(upSliders.at(2)->getDoubleValue(), 2);
}
void SliderGroup::setPosSliders(Vec3 newValue)
{
    eyeSliders.at(0)->setValue(newValue.getX() * 10);
    eyeSliders.at(1)->setValue(newValue.getY() * 10);
    eyeSliders.at(2)->setValue(newValue.getZ() * 10);
}

void SliderGroup::setTarSliders(Vec3 newValue)
{
    atSliders.at(0)->setValue(newValue.getX() * 10);
    atSliders.at(1)->setValue(newValue.getY() * 10);
    atSliders.at(2)->setValue(newValue.getZ() * 10);
}

void SliderGroup::setUpSliders(Vec3 newValue)
{
    upSliders.at(0)->setValue(newValue.getX() * 10);
    upSliders.at(1)->setValue(newValue.getY() * 10);
    upSliders.at(2)->setValue(newValue.getZ() * 10);
}
