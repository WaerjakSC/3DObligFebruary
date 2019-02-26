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

class OctahedronBall
{
private:
    int m_rekursjoner;
    int m_indeks; // brukes i rekursjon, til å bygge m_vertices
    Game *gameInst;
    Vec3 mVelocity, mFront = Vec3(0, 0, -1), mUp = Vec3(0, 1, 0);
    float mRadius;
    CollisionPacket *collisionPackage;
    int collisionRecursionDepth;
    GameObject *thisObject;
    std::vector<Vertex> mVertices;
    TriangleArray triArray;
    const float unitsPerMeter = 0.10f;

    void lagTriangel(const Vec3 &v1, const Vec3 &v2, const Vec3 &v3);
    void subDivide(const Vec3 &a, const Vec3 &b, const Vec3 &c, int n);
    void oktaederUnitBall();
    Vec3 collideWithWorld(const Vec3 &pos, const Vec3 &vel);
    void collideAndSlide(const Vec3 &vel /*, const Vec3 &gravity*/);
    void MoveTo(Vec3 velocity);

public:
    OctahedronBall(int n = 3, float radius = 1, Game *game = nullptr);
    void init(GLint matrixUniform);
    void draw();

    void addForward(float speed);
    void strafe(float speed);
    Vec3 velocity() const;
    float radius() const;
    Vec3 position();
};
#endif
