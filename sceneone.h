#ifndef SCENEONE_H
#define SCENEONE_H

#include "visualobject.h"

class Sceneone : public VisualObject
{
public:
    Sceneone();

    void init(GLint matrixUniform) override;
    void draw() override;
};
#endif // SCENEONE_H
