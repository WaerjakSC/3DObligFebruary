#ifndef QDOUBLESLIDER_H
#define QDOUBLESLIDER_H
#include <QSlider>

class QDoubleSlider : public QSlider
{
    Q_OBJECT

public:
    QDoubleSlider(QWidget *parent, Qt::Orientation orientation, float value);
    double getDoubleValue();
signals:
    void doubleValueChanged(double value);

public slots:
    void notifyValueChanged(int value);

private:
    int coefficient = 100;
};

#endif // QDOUBLESLIDER_H
