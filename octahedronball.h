#ifndef OCTAHEDRONBALL_H
#define OCTAHEDRONBALL_H

#include "vector3d.h"
#include "visualobject.h"
#include <QOpenGLFunctions_4_1_Core>

using namespace jl;
class Vertex;

//typedef gs2019::Vector3d Vec3;

typedef Vector3D Vec3;

class OctahedronBall : public VisualObject
{
private:
    int m_rekursjoner;
    int m_indeks; // brukes i rekursjon, til å bygge m_vertices
    void lagTriangel(const Vec3 &v1, const Vec3 &v2, const Vec3 &v3);
    void subDivide(const Vec3 &a, const Vec3 &b, const Vec3 &c, int n);
    void oktaederUnitBall();

public:
    OctahedronBall(int n = 3);
    void init(GLint matrixUniform);
    void draw();
    Vec3 mFront = Vec3(0, 0, -1), mUp = Vec3(0, 1, 0);
    Vec3 posVec;

    void addForward(float speed);
    void strafe(float speed);
};
#endif
