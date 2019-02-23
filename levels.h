#ifndef LEVELS_H
#define LEVELS_H
#include "gameobject.h"
#include "visualobject.h"
class Sceneone;
class Scenetwo;
class Levels
{
public:
    Levels();
    void init(GLint matrixUniform);
    void draw();
    std::vector<GameObject *> objects;

private:
    Sceneone *sceneOne;
    Scenetwo *sceneTwo;

    GLint mMatrixUniform{0};
};

#endif // LEVELS_H
