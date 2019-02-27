#include "qdoubleslider.h"

QDoubleSlider::QDoubleSlider(QWidget *parent, Qt::Orientation orientation, float value, int min, int max) : QSlider(orientation, parent)
{
    connect(this, SIGNAL(valueChanged(int)),
            this, SLOT(notifyValueChanged(int)));
    setMinimum(min);
    setMaximum(max);
    setValue(value * 10);
}

double QDoubleSlider::getDoubleValue()
{

    if (value() > 0 || value() < 0)
    {
        return value() / 10.0;
    }
    else
        return 0;
}

void QDoubleSlider::setDoubleValue(int value)
{
    setValue(value * 10);
}

void QDoubleSlider::notifyValueChanged(int value)
{
    double doubleValue = value / 10.0;
    emit doubleValueChanged(doubleValue);
}
