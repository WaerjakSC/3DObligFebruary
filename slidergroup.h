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
    SliderGroup(Qt::Orientation orientation, const QString &title,
                QWidget *parent = 0, Camera *cam = 0);

signals:
    void valueChanged(int value);

public slots:
    //    void setValue(int value);
    //    void setMinimum(int value);
    //    void setMaximum(int value);

    void setPosition();
    void setTarget();
    void setUp();
    void updateLabelMatrix();

private:
    const int MIN_VALUE = -100;
    const int MAX_VALUE = 100;

    Vector3d eye, at, up;

    Camera *m_Camera;

    std::vector<QLabel *> matrixLabels;

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
