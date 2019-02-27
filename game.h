#ifndef GAME_H
#define GAME_H

#include "gameobject.h"
#include "levels.h"
#include "vector3d.h"
#include <QTimer>

class Sceneone;
class OctahedronBall;
class CollisionPacket;
class Collision;
typedef jl::Vector3D Vec3;
/**
 * @brief The Game class is the game instance used for level switching
 * and initialization of scenes.
 */
class Game : public QObject
{
    Q_OBJECT
public:
    Game();
    void CheckCollisions(CollisionPacket *collisionPackage);

    void Tick();
    void init(GLint matrixUniform);
    OctahedronBall *getPawn();
    TriangleArray eSpaceTriangle;
    Sceneone *sceneOne;
    Scenetwo *sceneTwo;
    void switchLevels();

    int getCurrentLevel() const;
public slots:

private:
    OctahedronBall *ball;

    Collision *collision;
    std::vector<GameObject *> gameObjects;
    int currentLevel{0};

    // OpenGL stuff
    GLint mMatrixUniform{0};
    jl::Matrix4x4 mMatrix;
};

#endif // GAME_H
