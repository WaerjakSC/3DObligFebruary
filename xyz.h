#ifndef XYZ_H
#define XYZ_H

#include "vertex.h"
#include "visualobject.h"
#include <QMatrix4x4>
#include <QOpenGLFunctions_4_1_Core>
#include <vector>

class XYZ : public VisualObject
{
private:
public:
    XYZ();
    ~XYZ() override;
    void init(GLint matrixUniform) override;
    void draw() override;
};

#endif // XYZ_H
