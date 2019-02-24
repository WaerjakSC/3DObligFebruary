#ifndef GAME_H
#define GAME_H

#include "gameobject.h"
#include "levels.h"

class Sceneone;
class OctahedronBall;
class CollisionPacket;
class Collision;
class Game
{
public:
    Game();
    bool CheckCollisions(CollisionPacket *collisionPackage);

    void Tick();
    void init(GLint matrixUniform);
    OctahedronBall *getPawn();

    void switchLevels();

private:
    OctahedronBall *ball;

    Collision *collision;
    std::vector<GameObject *> levels;
    std::vector<GameObject *> gameObjects;
    void DoCollisions();
    int currentLevel{0};

    // OpenGL stuff
    GLint mMatrixUniform{0};
    jl::Matrix4x4 mMatrix;
};

#endif // GAME_H
