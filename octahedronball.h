#ifndef OCTAHEDRONBALL_H
#define OCTAHEDRONBALL_H

#include "gameobject.h"
#include "vector3d.h"
#include "visualobject.h"
#include <QOpenGLFunctions_4_1_Core>

using namespace jl;
class Vertex;
class CollisionPacket;
class Game;
typedef Vector3D Vec3;

class OctahedronBall : public GameObject
{
private:
    int m_rekursjoner;
    int m_indeks; // brukes i rekursjon, til å bygge m_vertices
    Game *gameInst;
    Vec3 mVelocity;
    Vec3 mFront = Vec3(0, 0, -1), mUp = Vec3(0, 1, 0);
    float mRadius;
    CollisionPacket *collisionPackage;
    int collisionRecursionDepth;
    const float unitsPerMeter = 100.0f;
    void lagTriangel(const Vec3 &v1, const Vec3 &v2, const Vec3 &v3);
    void subDivide(const Vec3 &a, const Vec3 &b, const Vec3 &c, int n);
    void oktaederUnitBall();

public:
    OctahedronBall(int n = 3, float radius = 1, Game *game = nullptr);
    void init(GLint matrixUniform);
    void draw();

    void collideAndSlide(const Vec3 &vel, const Vec3 &gravity);
    Vec3 collideWithWorld(const Vec3 &pos, const Vec3 &vel);
    void addForward(float speed);
    void strafe(float speed);
    Vec3 velocity() const;
    void move(const Vec3 &velocity);
    float radius() const;
};
#endif
