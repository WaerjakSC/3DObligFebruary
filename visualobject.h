#ifndef VISUALOBJECT_H
#define VISUALOBJECT_H

#include "vertex.h"
#include "matrix4x4.h"
#include <QMatrix4x4>
#include <QOpenGLFunctions_4_1_Core>
#include <vector>

class VisualObject : public QOpenGLFunctions_4_1_Core
{
public:
    VisualObject();
    ~VisualObject();
    virtual void init(GLint matrixUniform) = 0;
    virtual void draw() = 0;

    void readFile(std::string filnavn);
    void writeFile(std::string filename);

protected:
    std::vector<Vertex> mVertices;
    GLuint mVAO{0};
    GLuint mVBO{0};
    GLint mMatrixUniform{0};
    jl::Matrix4x4 mMatrix;
};

#endif // VISUALOBJECT_H
