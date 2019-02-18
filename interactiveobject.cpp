#include "interactiveobject.h"

InteractiveObject::InteractiveObject()
{
}

InteractiveObject::~InteractiveObject()
{
}

void InteractiveObject::init(GLint matrixUniform)
{
    mMatrixUniform = matrixUniform;

    initializeOpenGLFunctions();

    //Vertex Array Object - VAO
    glGenVertexArrays(1, &mVAO);
    glBindVertexArray(mVAO);

    //Vertex Buffer Object to hold vertices - VBO
    glGenBuffers(1, &mVBO);
}
void InteractiveObject::draw()
{
}

void InteractiveObject::move(float x, float y, float z)
{
}
