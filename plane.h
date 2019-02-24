#ifndef PLANE_H
#define PLANE_H
#include "vector3d.h"

typedef jl::Vector3D Vec3;

class PLANE
{
public:
    float equation[4];
    Vec3 origin;
    Vec3 normal;

    PLANE(const Vec3 &origin, const Vec3 &normal);
    PLANE(const Vec3 &p1, const Vec3 &p2, const Vec3 &p3);

    bool isFrontFacingTo(const Vec3 &direction) const;
    double signedDistanceTo(const Vec3 &point) const;
};

#endif // PLANE_H
