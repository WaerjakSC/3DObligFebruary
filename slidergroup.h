#ifndef SLIDERGROUP_H
#define SLIDERGROUP_H
#include "camera.h"
#include "qdoubleslider.h"
#include "vector3d.h"
#include <QDial>
#include <QGroupBox>
#include <QLabel>
#include <QScrollBar>
#include <QSlider>

class SliderGroup : public QGroupBox
{
    Q_OBJECT

public:
    SliderGroup(Qt::Orientation orientation = Qt::Orientation::Horizontal, const QString &title = "",
                QWidget *parent = 0, Camera *cam = 0);

signals:
    void valueChanged(int value);

public slots:
    void setPosSliders(Vec3 newValue);
    void setTarSliders(Vec3 newValue);
    void setUpSliders(Vec3 newValue);

    void setPosition();
    void setTarget();
    void setUp();

private:
    Vector3D eye, at, up;

    Camera *m_Camera;

    std::vector<QDoubleSlider *> eyeSliders;
    std::vector<QLabel *> eyeNum;
    std::vector<QLabel *> eyeXYZ;

    std::vector<QDoubleSlider *> atSliders;
    std::vector<QLabel *> atNum;
    std::vector<QLabel *> atXYZ;

    std::vector<QDoubleSlider *> upSliders;
    std::vector<QLabel *> upNum;
    std::vector<QLabel *> upXYZ;

    QGroupBox *createEyeGroup(Qt::Orientation orientation);
    QGroupBox *createAtGroup(Qt::Orientation orientation);
    QGroupBox *createUpGroup(Qt::Orientation orientation);
    QGroupBox *createMatrix();
};

#endif // SLIDERGROUP_H
