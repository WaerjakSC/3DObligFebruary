#ifndef SCENETWO_H
#define SCENETWO_H

#include "visualobject.h"

class Scenetwo : public VisualObject
{
public:
    Scenetwo();

    void init(GLint matrixUniform) override;
    void draw() override;
};

#endif // SCENETWO_H
