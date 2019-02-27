#ifndef QDOUBLESLIDER_H
#define QDOUBLESLIDER_H
#include <QSlider>

class QDoubleSlider : public QSlider
{
    Q_OBJECT

public:
    QDoubleSlider(QWidget *parent, Qt::Orientation orientation, float value, int min = -100, int max = 100);
    double getDoubleValue();
    void setDoubleValue(int value);
signals:
    void doubleValueChanged(double value);

public slots:
    void notifyValueChanged(int value);

private:
    int coefficient = 100;
};

#endif // QDOUBLESLIDER_H
