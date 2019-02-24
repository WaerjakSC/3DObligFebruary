#include "plane.h"

PLANE::PLANE(const Vec3 &origin, const Vec3 &normal)
{
    this->normal = normal;
    this->origin = origin;
    equation[0] = normal.getX();
    equation[1] = normal.getY();
    equation[2] = normal.getZ();
    equation[3] = -(normal.getX() * origin.getX() +
                    normal.getY() * origin.getY() +
                    normal.getZ() * origin.getZ());
}
// Construct from triangle
PLANE::PLANE(const Vec3 &p1, const Vec3 &p2, const Vec3 &p3)
{
    normal = (p2 - p1) ^ (p3 - p1);
    normal.normalize();
    origin = p1;
    equation[0] = normal.getX();
    equation[1] = normal.getY();
    equation[2] = normal.getZ();
    equation[3] = -(normal.getX() * origin.getX() +
                    normal.getY() * origin.getY() +
                    normal.getZ() * origin.getZ());
}

bool PLANE::isFrontFacingTo(const Vec3 &direction) const
{
    double dot = normal * direction;
    return (dot <= 0);
}

double PLANE::signedDistanceTo(const Vec3 &point) const
{
    // Dot product of point and normal + equation[3]
    return ((point * normal) + equation[3]);
}
