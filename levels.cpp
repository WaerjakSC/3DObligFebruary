#include "levels.h"
#include "sceneone.h"
#include "scenetwo.h"

Levels::Levels()
{
    sceneOne = new Sceneone;
    sceneTwo = new Scenetwo;
}
void Levels::init(GLint matrixUniform)
{
    mMatrixUniform = matrixUniform;
    sceneOne->init(mMatrixUniform);
    sceneTwo->init(mMatrixUniform);
}
