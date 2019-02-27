#ifndef OBJECTSELECT_H
#define OBJECTSELECT_H

#include "camera.h"
#include "qdoubleslider.h"
#include <QComboBox>
#include <QGridLayout>
#include <QGroupBox>
#include <QLabel>
#include <QSlider>
#include <QWidget>

class Game;
class Camera;
class ObjectSelect : public QGroupBox
{
    Q_OBJECT
public:
    explicit ObjectSelect(QWidget *parent = nullptr, Camera *mCam = nullptr, Game *game = nullptr);

    QGroupBox *createMatrix(Camera *cam);
    QGroupBox *createLocGroup(Qt::Orientation orientation);
    GameObject *getIndexObject();
    QGroupBox *createRotGroup(Qt::Orientation orientation);
    QGroupBox *createScaleGroup(Qt::Orientation orientation);
signals:
    void valueChanged(int value);

public slots:
    //    void setPosition();
    //    void setRotation();
    //    void setScale();
    void updateWidget();
    void setPosition();
    void setScale();
    void setRotation();
    void setAll();

private:
    Camera *m_Camera;
    Game *gamePtr;
    QComboBox *objectList;
    QComboBox *populateList(std::vector<GameObject *> objects);

    std::vector<QDoubleSlider *> locSliders;
    std::vector<QLabel *> locNum;
    std::vector<QLabel *> locXYZ;

    std::vector<QDoubleSlider *> rotSliders;
    std::vector<QLabel *> rotNum;
    std::vector<QLabel *> rotXYZ;

    std::vector<QDoubleSlider *> scaleSliders;
    std::vector<QLabel *> scaleNum;
    std::vector<QLabel *> scaleXYZ;
};

#endif // OBJECTSELECT_H
