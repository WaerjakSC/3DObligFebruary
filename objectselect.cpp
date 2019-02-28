#include "objectselect.h"
#include "camera.h"
#include "game.h"
#include "gameobject.h"
#include "matrix4x4.h"
#include "vector3d.h"
ObjectSelect::ObjectSelect(QWidget *parent, Camera *mCam, Game *game)
    : QGroupBox(parent), m_Camera(mCam), gamePtr(game)
{
    setAlignment(Qt::AlignCenter);
    QHBoxLayout *grid = new QHBoxLayout;
    objectList = populateList(game->getGameObjects());
    grid->addWidget(createLocGroup(Qt::Orientation::Horizontal));
    grid->addWidget(createRotGroup(Qt::Orientation::Horizontal));
    grid->addWidget(createScaleGroup(Qt::Orientation::Horizontal));
    grid->addWidget(createTransformLayout());
    grid->addWidget(objectList);

    // Connect all the sliders to the labels, converting them from int to double in the process (see qdoubleslider.h)
    for (int i = 0; i < 3; i++)
    {
        // Connect sliders to the numbers underneath
        connect(locSliders.at(i), SIGNAL(doubleValueChanged(double)), locNum.at(i), SLOT(setNum(double)));
        connect(rotSliders.at(i), SIGNAL(doubleValueChanged(double)), rotNum.at(i), SLOT(setNum(double)));
        connect(scaleSliders.at(i), SIGNAL(doubleValueChanged(double)), scaleNum.at(i), SLOT(setNum(double)));

        // Set up the connections between the gameobject and sliders
        connect(locSliders.at(i), SIGNAL(doubleValueChanged(double)), this, SLOT(setPosition()));
        //        connect(scaleSliders.at(i), SIGNAL(doubleValueChanged(double)), this, SLOT(setScale()));
        //        connect(rotSliders.at(i), SIGNAL(doubleValueChanged(double)), this, SLOT(setRotation()));
    }
    for (GameObject *object : gamePtr->getGameObjects())
        connect(object, SIGNAL(updatedTransforms()), this, SLOT(updateTransformLabels()));

    connect(objectList, SIGNAL(currentIndexChanged(QString)), this, SLOT(updateWidget()));
    connect(gamePtr, SIGNAL(levelChanged(std::vector<GameObject *>)), this, SLOT(rePopulateList(std::vector<GameObject *>)));
    setMaximumHeight(170);
    //    setMaximumWidth(600);
    setMinimumSize(600, 180);
    setLayout(grid);
}
void ObjectSelect::updateLocNums(double value)
{
    GameObject *object = getIndexObject();
    for (int i = 0; i < 3; i++)
    {
        locNum.at(i)->setNum(value / object->scale().at(i));
    }
}
QGroupBox *ObjectSelect::createLocGroup(Qt::Orientation orientation)
{
    QGroupBox *groupBox = new QGroupBox(tr("Location:"));
    groupBox->setAlignment(Qt::AlignCenter); // Align the title to center
    // Initialize the sliders and labels with the correct default values from the main camera.
    for (int i = 0; i < 3; i++)
    {
        locSliders.push_back(new QDoubleSlider(groupBox, orientation, getIndexObject()->position().at(i)));
        locSliders.at(i)->setFocusPolicy(Qt::StrongFocus);
        locSliders.at(i)->setTickPosition(QSlider::TicksBothSides);
        locNum.push_back(new QLabel(QString::number(locSliders.at(i)->getDoubleValue())));
        locNum.at(i)->setAlignment(Qt::AlignCenter);
    }
    locXYZ.push_back(new QLabel(tr("X: ")));
    locXYZ.push_back(new QLabel(tr("Y: ")));
    locXYZ.push_back(new QLabel(tr("Z: ")));
    QVBoxLayout *vbox = new QVBoxLayout;
    std::vector<QHBoxLayout *> hbox;
    for (int i = 0; i < 3; i++)
    {
        hbox.push_back(new QHBoxLayout);
        hbox.at(i)->addWidget(locXYZ.at(i));
        hbox.at(i)->addWidget(locSliders.at(i));
        vbox->addLayout(hbox.at(i));
        vbox->addWidget(locNum.at(i));
    }
    vbox->addStretch(1);
    groupBox->setLayout(vbox);
    return groupBox;
}
QGroupBox *ObjectSelect::createRotGroup(Qt::Orientation orientation)
{
    QGroupBox *groupBox = new QGroupBox(tr("Rotation:"));
    groupBox->setAlignment(Qt::AlignCenter); // Align the title to center
    // Initialize the sliders and labels with the correct default values from the main camera.
    for (int i = 0; i < 3; i++)
    {
        rotSliders.push_back(new QDoubleSlider(groupBox, orientation, getIndexObject()->GetEulerRotation().at(i), -3600, 3600));
        rotSliders.at(i)->setFocusPolicy(Qt::StrongFocus);
        rotSliders.at(i)->setTickPosition(QSlider::TicksBothSides);
        rotNum.push_back(new QLabel(QString::number(rotSliders.at(i)->getDoubleValue())));
        rotNum.at(i)->setAlignment(Qt::AlignCenter);
    }
    rotXYZ.push_back(new QLabel(tr("X: ")));
    rotXYZ.push_back(new QLabel(tr("Y: ")));
    rotXYZ.push_back(new QLabel(tr("Z: ")));
    QVBoxLayout *vbox = new QVBoxLayout;
    std::vector<QHBoxLayout *> hbox;
    for (int i = 0; i < 3; i++)
    {
        hbox.push_back(new QHBoxLayout);
        hbox.at(i)->addWidget(rotXYZ.at(i));
        hbox.at(i)->addWidget(rotSliders.at(i));
        vbox->addLayout(hbox.at(i));
        vbox->addWidget(rotNum.at(i));
    }
    vbox->addStretch(1);
    groupBox->setLayout(vbox);
    return groupBox;
}
QGroupBox *ObjectSelect::createScaleGroup(Qt::Orientation orientation)
{
    QGroupBox *groupBox = new QGroupBox(tr("Scale:"));
    groupBox->setAlignment(Qt::AlignCenter); // Align the title to center
    // Initialize the sliders and labels with the correct default values from the main camera.
    for (int i = 0; i < 3; i++)
    {
        scaleSliders.push_back(new QDoubleSlider(groupBox, orientation, getIndexObject()->scale().at(i)));
        scaleSliders.at(i)->setFocusPolicy(Qt::StrongFocus);
        scaleSliders.at(i)->setTickPosition(QSlider::TicksBothSides);
        scaleNum.push_back(new QLabel(QString::number(scaleSliders.at(i)->getDoubleValue())));
        scaleNum.at(i)->setAlignment(Qt::AlignCenter);
    }
    scaleXYZ.push_back(new QLabel(tr("X: ")));
    scaleXYZ.push_back(new QLabel(tr("Y: ")));
    scaleXYZ.push_back(new QLabel(tr("Z: ")));
    QVBoxLayout *vbox = new QVBoxLayout;
    std::vector<QHBoxLayout *> hbox;
    for (int i = 0; i < 3; i++)
    {
        hbox.push_back(new QHBoxLayout);
        hbox.at(i)->addWidget(scaleXYZ.at(i));
        hbox.at(i)->addWidget(scaleSliders.at(i));
        vbox->addLayout(hbox.at(i));
        vbox->addWidget(scaleNum.at(i));
    }
    vbox->addStretch(1);
    groupBox->setLayout(vbox);
    return groupBox;
}
GameObject *ObjectSelect::getIndexObject()
{
    for (GameObject *object : gamePtr->getGameObjects())
    {
        // Finds the first object with name equal to the current name in the combobox
        // Not very reliable if you allow same names for different items.
        if (object->getName() == objectList->currentText())
            return object;
    }
    qDebug() << "No object with that name found, something is very wrong.";
    return nullptr;
}
QComboBox *ObjectSelect::populateList(std::vector<GameObject *> objects)
{
    QComboBox *box = new QComboBox;
    int index{0};
    for (GameObject *object : objects)
    {
        box->insertItem(index, object->getName());
        index++;
    }
    return box;
}
void ObjectSelect::rePopulateList(std::vector<GameObject *> objects)
{
    int index{0};
    // Temporarily disconnect the indexchanged signal so it doesn't try to update with a non-existing object.
    disconnect(objectList, SIGNAL(currentIndexChanged(QString)), this, SLOT(updateWidget()));
    objectList->clear(); // Clear the combobox
    // Re-populate it
    for (GameObject *object : objects)
    {
        objectList->insertItem(index, object->getName());
        index++;
    }
    // Connect it to the signal again:
    connect(objectList, SIGNAL(currentIndexChanged(QString)), this, SLOT(updateWidget()));
}

void ObjectSelect::updateWidget()
{
    GameObject *object = getIndexObject();

    for (int i = 0; i < 3; i++)
    {
        // Don't try to set anything while it's changing to a new object.
        disconnect(locSliders.at(i), SIGNAL(doubleValueChanged(double)), this, SLOT(setPosition()));
        disconnect(scaleSliders.at(i), SIGNAL(doubleValueChanged(double)), this, SLOT(setScale()));
        disconnect(rotSliders.at(i), SIGNAL(doubleValueChanged(double)), this, SLOT(setRotation()));
        // Update the sliders
        locSliders.at(i)->setDoubleValue(object->position().at(i));
        rotSliders.at(i)->setDoubleValue(object->GetEulerRotation().at(i));
        scaleSliders.at(i)->setDoubleValue(object->scale().at(i));

        // Update the labels
        locNum.at(i)->setNum(object->position().at(i));
        rotNum.at(i)->setNum(object->GetEulerRotation().at(i));
        scaleNum.at(i)->setNum(object->scale().at(i));

        // Set up the connections between the gameobject and sliders
        connect(locSliders.at(i), SIGNAL(doubleValueChanged(double)), this, SLOT(setPosition()));
        //        connect(scaleSliders.at(i), SIGNAL(doubleValueChanged(double)), this, SLOT(setScale()));
        //        connect(rotSliders.at(i), SIGNAL(doubleValueChanged(double)), this, SLOT(setRotation()));
    }
    updateTransformLabels();
}

void ObjectSelect::setAll()
{
    setPosition();

    //    setRotation();

    //    setScale();
}
void ObjectSelect::setPosition()
{
    GameObject *object = getIndexObject();
    Vector3D newPos;

    Matrix4x4 scaleMat(1);
    Matrix4x4 rot(1);
    Matrix4x4 trans(1);

    scaleMat.scale(object->scale());
    rot.rotate(Vector3D(1, 0, 0), object->GetEulerRotation().getX());
    rot.rotate(Vector3D(0, 1, 0), object->GetEulerRotation().getY());
    rot.rotate(Vector3D(0, 0, 1), object->GetEulerRotation().getZ());

    newPos.setX((locSliders.at(0)->getDoubleValue() / object->scale().at(0)) /* / 10*/);
    newPos.setY((locSliders.at(1)->getDoubleValue() / object->scale().at(1)) /* / 10*/);
    newPos.setZ((locSliders.at(2)->getDoubleValue() / object->scale().at(2)) /* / 10*/);
    trans.translate(newPos);
    Matrix4x4 transformation = scaleMat * rot * trans;

    object->setPosition(transformation);
}

void ObjectSelect::setScale()
{
    GameObject *object = getIndexObject();
    Vector3D newScale;

    object->resetScale();
    newScale.setX(scaleSliders.at(0)->getDoubleValue());
    newScale.setY(scaleSliders.at(1)->getDoubleValue());
    newScale.setZ(scaleSliders.at(2)->getDoubleValue());

    object->scale(newScale);
}

void ObjectSelect::setRotation()
{
    GameObject *object = getIndexObject();
    object->resetRotation();
    object->rotate(Vector3D(1, 0, 0), rotSliders.at(0)->getDoubleValue());
    object->rotate(Vector3D(0, 1, 0), rotSliders.at(1)->getDoubleValue());
    object->rotate(Vector3D(0, 0, 1), rotSliders.at(2)->getDoubleValue());
}

QGroupBox *ObjectSelect::createTransformLayout()
{
    QGridLayout *gridBox = new QGridLayout;
    QGroupBox *hbox = new QGroupBox(tr("Transform:"));
    hbox->setAlignment(Qt::AlignCenter);
    gridBox->setAlignment(Qt::AlignCenter);

    std::vector<QLabel *> x;

    std::vector<QLabel *> y;

    std::vector<QLabel *> z;

    transformValues.push_back(new QLabel("Location: "));
    gridBox->addWidget(transformValues.at(0), 0, 0);
    transformValues.at(0)->setFrameStyle(QFrame::NoFrame | QFrame::Plain);

    transformValues.push_back(new QLabel("Rotation: "));
    gridBox->addWidget(transformValues.at(1), 1, 0);
    transformValues.at(1)->setFrameStyle(QFrame::NoFrame | QFrame::Plain);

    transformValues.push_back(new QLabel("Scale: "));
    gridBox->addWidget(transformValues.at(2), 2, 0);
    transformValues.at(2)->setFrameStyle(QFrame::NoFrame | QFrame::Plain);

    for (int i = 0; i < 3; i++)
    {
        x.push_back(new QLabel("X:"));
        x.at(i)->setFrameStyle(QFrame::NoFrame | QFrame::Plain);
        y.push_back(new QLabel("Y:"));
        y.at(i)->setFrameStyle(QFrame::NoFrame | QFrame::Plain);
        z.push_back(new QLabel("Z:"));
        z.at(i)->setFrameStyle(QFrame::NoFrame | QFrame::Plain);
        gridBox->addWidget(x.at(i), i, 1);
        gridBox->addWidget(y.at(i), i, 3);
        gridBox->addWidget(z.at(i), i, 5);
    }
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            float vM;
            switch (i)
            {
            case 0:
                vM = getIndexObject()->position().at(j);
                break;
            case 1:
                vM = getIndexObject()->rotation().at(j);
                break;
            case 2:
                vM = getIndexObject()->scale().at(j);
                break;
            }
            transformValues.push_back(new QLabel(QString::number(vM, 'f', 3)));
            transformValues.at((j + (i * 3) + 3))->setFrameStyle(QFrame::Box | QFrame::Plain);
            gridBox->addWidget(transformValues.at(j + (i * 3) + 3), i, (j * 2) + 2);
        }
    }
    gridBox->setColumnMinimumWidth(2, 55);
    gridBox->setColumnMinimumWidth(4, 55);
    gridBox->setColumnMinimumWidth(6, 55);

    gridBox->setContentsMargins(10, 10, 10, 10);
    gridBox->setSpacing(13);
    hbox->setMaximumHeight(170);

    hbox->setLayout(gridBox);
    return hbox;
}
void ObjectSelect::updateTransformLabels()
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            float vM;
            switch (i)
            {
            case 0:
                vM = getIndexObject()->position().at(j);
                break;
            case 1:
                vM = getIndexObject()->GetEulerRotation().at(j);
                break;
            case 2:
                vM = getIndexObject()->scale().at(j);
                break;
            }
            // Update the labels with 3 decimal precision.
            transformValues.at(j + (i * 3) + 3)->setText(QString::number(vM, 'f', 3));
        }
    }
}
