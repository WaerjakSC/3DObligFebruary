#include "qdoubleslider.h"

QDoubleSlider::QDoubleSlider(QWidget *parent, Qt::Orientation orientation, float value) : QSlider(orientation, parent)
{
    connect(this, SIGNAL(valueChanged(int)),
            this, SLOT(notifyValueChanged(int)));
    setMinimum(-100);
    setMaximum(100);
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

void QDoubleSlider::notifyValueChanged(int value)
{
    double doubleValue = value / 10.0;
    emit doubleValueChanged(doubleValue);
}
