#ifndef COLLISIONPACKET_H
#define COLLISIONPACKET_H
#include "vector3d.h"

typedef jl::Vector3D Vec3;
class CollisionPacket
{
public:
    CollisionPacket();
    Vec3 eRadius = Vec3(0.1, 0.1, 0.1);

    // Information about the move being requested: (in R3)
    Vec3 R3Velocity;
    Vec3 R3Position;

    // Information about the move being requested: (in eSpace)
    Vec3 velocity;
    Vec3 normalizedVelocity;
    Vec3 basePoint;

    // Hit information
    bool foundCollision;
    double nearestDistance;
    Vec3 intersectionPoint;
};

#endif // COLLISIONPACKET_H
