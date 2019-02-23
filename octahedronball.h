#ifndef OCTAHEDRONBALL_H
#define OCTAHEDRONBALL_H

#include "gameobject.h"
#include "vector3d.h"
#include "visualobject.h"
#include <QOpenGLFunctions_4_1_Core>

using namespace jl;
class Vertex;

typedef Vector3D Vec3;

class OctahedronBall : public GameObject
{
private:
    int m_rekursjoner;
    int m_indeks; // brukes i rekursjon, til å bygge m_vertices
    Vec3 mVelocity;
    Vec3 mFront = Vec3(0, 0, -1), mUp = Vec3(0, 1, 0);
    float mRadius;

    void lagTriangel(const Vec3 &v1, const Vec3 &v2, const Vec3 &v3);
    void subDivide(const Vec3 &a, const Vec3 &b, const Vec3 &c, int n);
    void oktaederUnitBall();

public:
    OctahedronBall(int n = 3, float radius = 1);
    void init(GLint matrixUniform);
    void draw();

    void addForward(float speed);
    void strafe(float speed);
    Vec3 velocity() const;
    void move(const Vec3 &velocity);
    float radius() const;
};
#endif
