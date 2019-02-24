#ifndef COLLISION_H
#define COLLISION_H
#include "collisionpacket.h"
#include "jmath.h"
#include "vector3d.h"
typedef unsigned int uint32;
typedef jl::Vector3D Vec3;
#define in(a) ((uint32 &)a)

class Collision
{
public:
    Collision();
    bool checkPointInTriangle(const Vec3 &point, const Vec3 &pointA, const Vec3 &pointB, const Vec3 &pointC);
    void checkTriangle(CollisionPacket *colPackage, const Vec3 &p1, const Vec3 &p2, const Vec3 &p3);
};

#endif // COLLISION_H
