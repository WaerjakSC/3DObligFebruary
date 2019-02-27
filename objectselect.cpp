#include "objectselect.h"
#include "camera.h"
#include "game.h"
#include "gameobject.h"
ObjectSelect::ObjectSelect(QWidget *parent, Camera *mCam, Game *game)
    : QGroupBox(parent), m_Camera(mCam), gamePtr(game)
{
    setAlignment(Qt::AlignCenter);
    QHBoxLayout *grid = new QHBoxLayout;
    objectList = populateList(game->getGameObjects());
    grid->addWidget(createLocGroup(Qt::Orientation::Horizontal));
    grid->addWidget(createRotGroup(Qt::Orientation::Horizontal));
    grid->addWidget(createScaleGroup(Qt::Orientation::Horizontal));
    grid->addWidget(objectList);

    // Connect all the sliders to the labels, converting them from int to double in the process (see qdoubleslider.h)
    for (int i = 0; i < 3; i++)
    {
        // Connect sliders to the numbers underneath
        connect(locSliders.at(i), SIGNAL(doubleValueChanged(double)), locNum.at(i), SLOT(setNum(double)));
        connect(rotSliders.at(i), SIGNAL(doubleValueChanged(double)), rotNum.at(i), SLOT(setNum(double)));
        connect(scaleSliders.at(i), SIGNAL(doubleValueChanged(double)), scaleNum.at(i), SLOT(setNum(double)));

        //        // Set up the connections between the camera class and sliders
        //        connect(locSliders.at(i), SIGNAL(doubleValueChanged(double)), this, SLOT(setPosition()));
        //        connect(rotSliders.at(i), SIGNAL(doubleValueChanged(double)), this, SLOT(setTarget()));
        //        connect(scaleSliders.at(i), SIGNAL(doubleValueChanged(double)), this, SLOT(setUp()));
    }

    connect(objectList, SIGNAL(currentIndexChanged(QString)), this, SLOT(updateWidget()));
    setMaximumHeight(170);
    //    setMaximumWidth(600);
    setMinimumSize(600, 180);
    setLayout(grid);

    // Index changed -> update all sliders and labels with new object information
    // SIGNAL(changedCurrentIndex(QString), this, updateWidget()
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
void ObjectSelect::updateWidget()
{
    GameObject *object = getIndexObject();
    for (int i = 0; i < 3; i++)
    {
        // Update the sliders
        locSliders.at(i)->setDoubleValue(object->position().at(i));
        rotSliders.at(i)->setDoubleValue(object->GetEulerRotation().at(i));
        scaleSliders.at(i)->setDoubleValue(object->scale().at(i));

        // Update the labels
        locNum.at(i)->setNum(object->position().at(i));
        rotNum.at(i)->setNum(object->GetEulerRotation().at(i));
        scaleNum.at(i)->setNum(object->scale().at(i));
    }
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
