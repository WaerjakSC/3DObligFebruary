#include "objectselect.h"
#include "camera.h"
#include "game.h"
#include "gameobject.h"
ObjectSelect::ObjectSelect(QWidget *parent, jl::Camera *mCam, Game *game)
    : QGroupBox(parent), m_Camera(mCam), gamePtr(game)
{
    setAlignment(Qt::AlignCenter);
    QHBoxLayout *grid = new QHBoxLayout;
    grid->addWidget(createManipGroup(Qt::Orientation::Horizontal));
}

//QGroupBox *ObjectSelect::createMatrix(jl::Camera *cam)
//{
//    QGridLayout *gridBox = new QGridLayout;
//    QGroupBox *hbox = new QGroupBox(tr("LookAt Matrix"));
//    hbox->setAlignment(Qt::AlignCenter);
//    gridBox->setAlignment(Qt::AlignCenter);

//    for (int i = 0; i < 4; i++)
//    {
//        for (int j = 0; j < 4; j++)
//        {
//            float vM = cam->getLookMatrix().at(j, i);
//            matrixLabels.push_back(new QLabel(QString::number(vM, 'f', 3)));
//            matrixLabels.at(j + i * 4)->setFrameStyle(QFrame::Box | QFrame::Plain);
//            gridBox->addWidget(matrixLabels.at(j + (i * 4)), i, j);
//        }
//        gridBox->setColumnMinimumWidth(i, 55);
//    }
//    gridBox->setContentsMargins(10, 10, 10, 10);
//    gridBox->setSpacing(13);
//    hbox->setMaximumHeight(170);

//    hbox->setLayout(gridBox);
//    return hbox;
//}
QGroupBox *ObjectSelect::createManipGroup(Qt::Orientation orientation)
{
    QGroupBox *groupBox = new QGroupBox(tr("Location:"));
    groupBox->setAlignment(Qt::AlignCenter); // Align the title to center
    // Initialize the sliders and labels with the correct default values from the main camera.
    for (int i = 0; i < 3; i++)
    {
        locSliders.push_back(new QDoubleSlider(groupBox, orientation, m_Camera->getPosition().at(i)));
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

QComboBox ObjectSelect::populateList(std::vector<GameObject *> objects)
{
    QComboBox *box = new QComboBox;
    int index{0};
    for (GameObject *object : objects)
    {
        box->insertItem(index, object->getName());
        index++;
    }
    connect(box, SIGNAL(currentIndexChanged(QString)), gamePtr, SLOT());
}
