#include "collision.h"
#include "plane.h"
#include <QDebug>
#include <algorithm>
#include <cmath>
Collision::Collision()
{
}
/**
 * @brief Collision::checkPointInTriangle checks if a point is inside a triangle or not.
 * @param point The point being checked against
 * @param pointA Point A of the triangle
 * @param pointB Point B of the triangle
 * @param pointC Point C of the triangle
 * @return
 */
//bool Collision::checkPointInTriangle(const Vec3 &point, const Vec3 &pointA, const Vec3 &pointB, const Vec3 &pointC)
//{
//    Vec3 e10 = pointB - pointA;
//    Vec3 e20 = pointC - pointA;

//    float a = e10 * e10;
//    float b = e10 * e20;
//    float c = e20 * e20;
//    float ac_bb = (a * c) - (b * b);

//    Vec3 vp(point.getX() - pointA.getX(), point.getY() - pointA.getY(), point.getZ() - pointA.getZ());

//    float d = vp * e10;
//    float e = vp * e20;
//    float x = (d * c) - (e * b);
//    float y = (e * a) - (d * b);
//    float z = x + y - ac_bb;

//    return ((in(z) & ~(in(x) | in(y))) & 0x80000000);
//}

//void Collision::checkTriangle(CollisionPacket *colPackage, const Vec3 &p1, const Vec3 &p2, const Vec3 &p3)
//{
//    // Make the plane containing this triangle
//    PLANE trianglePlane(p1, p2, p3);

//    // Is triangle front-facing to the velocity vector?
//    // We only check front-facing triangles
//    if (trianglePlane.isFrontFacingTo(colPackage->normalizedVelocity))
//    {
//        // Get interval of plane intersection
//        double t0, t1;
//        bool embeddedInPlane = false;

//        // Calculate the signed distance from sphere
//        // position to triangle plane
//        double signedDistToTrianglePlane = trianglePlane.signedDistanceTo(colPackage->basePoint);

//        // cache this as we're going to use it a few times below:
//        float normalDotVelocity = trianglePlane.normal * colPackage->velocity;

//        // If sphere is travelling parallell to the plane:
//        if (normalDotVelocity == 0.0f)
//        {
//            if (fabs(signedDistToTrianglePlane) >= 1.0f)
//            {
//                // Sphere is not embedded in plane.
//                // No collision possible.
//                return;
//            }
//            else
//            {
//                // sphere is embedded in plane.
//                // It intersects in the whole range [0..1]
//                embeddedInPlane = true;
//                t0 = 0.0;
//                t1 = 1.0;
//            }
//        }
//        else
//        {
//            // N dot D is not 0. Calculate intersection interval:
//            t0 = (-1.0 - signedDistToTrianglePlane) / normalDotVelocity;
//            t1 = (1.0 - signedDistToTrianglePlane) / normalDotVelocity;

//            // Swap so t0 < t1
//            if (t0 > t1)
//            {
//                double temp = t1;
//                t1 = t0;
//                t0 = temp;
//            }

//            // Check that at least one result is within range:
//            if (t0 > 1.0f || t1 < 0.0f)
//            {
//                // Both values are outside values [0,1]
//                // No collision possible:
//                return;
//            }

//            // Clamp to [0,1]
//            if (t0 < 0.0)
//                t0 = 0.0;
//            if (t1 < 0.0)
//                t1 = 0.0;
//            if (t0 > 1.0)
//                t0 = 1.0;
//            if (t1 > 1.0)
//                t1 = 1.0;
//        }

//        // Now we should have two time values t0 and t1
//        // Between which the swept sphere intersects with the
//        // triangle plane.
//        // If any collision is to occur it must happen within this interval.
//        Vec3 collisionPoint;
//        bool foundCollision = false;
//        float t = 1.0;

//        // First we check for the easy case - collision inside the triangle.
//        // If this happens it must be at time t0 as this is when the sphere
//        // rests on the front side of the triangle plan.
//        // This can only happen if the sphere is not embedded in the triangle plane.
//        if (!embeddedInPlane)
//        {
//            Vec3 planeIntersectionPoint = (colPackage->basePoint - trianglePlane.normal) +
//                                          colPackage->velocity * t0;
//            if (checkPointInTriangle(planeIntersectionPoint, p1, p2, p3))
//            {
//                foundCollision = true;
//                t = t0;
//                collisionPoint = planeIntersectionPoint;
//            }
//        }
//        // If we haven't found a collision already we'll have to sweep sphere
//        // against points and edges of the triangle.
//        // Note: A collision inside the triangle (the check above)
//        // will always hapen before a vertex or edge collision!
//        // This is why we can skip the swept test if the above gives a collision.
//        if (foundCollision == false)
//        {
//            Vec3 velocity = colPackage->velocity;
//            Vec3 base = colPackage->basePoint;
//            float velocitySquaredLength = velocity.squaredlLength();
//            float a, b, c; // Params for equation
//            float newT;

//            // For each vertex or edge a quadratic equation has to be solved.
//            // We parameterize this equation as a * t^2 + b * t + c = 0
//            // Below we calculate the parameters a, b and c for each test.

//            // Check against points:
//            a = velocitySquaredLength;

//            // P1
//            b = 2.0 * (velocity * (base - p1));
//            c = (p1 - base) * (p1 - base) - 1.0;
//            if (JMath::getLowestRoot(a, b, c, t, &newT))
//            {
//                t = newT;
//                foundCollision = true;
//                collisionPoint = p1;
//            }
//            // P2
//            b = 2.0 * (velocity * (base - p2));
//            c = (p2 - base) * (p2 - base) - 1.0;
//            if (JMath::getLowestRoot(a, b, c, t, &newT))
//            {
//                t = newT;
//                foundCollision = true;
//                collisionPoint = p2;
//            }
//            // P3
//            b = 2.0 * (velocity * (base - p3));
//            c = (p3 - base) * (p3 - base) - 1.0;
//            if (JMath::getLowestRoot(a, b, c, t, &newT))
//            {
//                t = newT;
//                foundCollision = true;
//                collisionPoint = p3;
//            }

//            // Check against edges:

//            // p1 -> p2:
//            Vec3 edge = p2 - p1;
//            Vec3 baseToVertex = p1 - base;
//            float edgeSquaredLength = edge.squaredlLength();
//            float edgeDotVelocity = edge * velocity;
//            float edgeDotBaseToVertex = edge * baseToVertex;

//            // Calculate parameters for equation
//            a = edgeSquaredLength * -velocitySquaredLength +
//                edgeDotVelocity * edgeDotVelocity;
//            b = edgeSquaredLength * ((velocity * baseToVertex) * 2) -
//                2.0 * edgeDotVelocity * edgeDotBaseToVertex;
//            c = edgeSquaredLength * (1 - baseToVertex.squaredlLength()) +
//                edgeDotBaseToVertex * edgeDotBaseToVertex;

//            // Does the swept sphere collide against infinite edge?
//            if (JMath::getLowestRoot(a, b, c, t, &newT))
//            {
//                // Check if intersection is within line segment:
//                float f = (edgeDotVelocity * newT - edgeDotBaseToVertex) /
//                          edgeSquaredLength;
//                if (f >= 0.0 && f <= 1.0)
//                {
//                    // Intersection took place within segment.
//                    t = newT;
//                    foundCollision = true;
//                    collisionPoint = p1 + (edge * f);
//                }
//            }
//            // p2 -> p3:
//            edge = p3 - p2;
//            baseToVertex = p2 - base;
//            edgeSquaredLength = edge.squaredlLength();
//            edgeDotVelocity = edge * velocity;
//            edgeDotBaseToVertex = edge * baseToVertex;

//            // Calculate parameters for equation
//            a = edgeSquaredLength * -velocitySquaredLength +
//                edgeDotVelocity * edgeDotVelocity;
//            b = edgeSquaredLength * ((velocity * baseToVertex) * 2) -
//                2.0 * edgeDotVelocity * edgeDotBaseToVertex;
//            c = edgeSquaredLength * (1 - baseToVertex.squaredlLength()) +
//                edgeDotBaseToVertex * edgeDotBaseToVertex;

//            // Does the swept sphere collide against infinite edge?
//            if (JMath::getLowestRoot(a, b, c, t, &newT))
//            {
//                // Check if intersection is within line segment:
//                float f = (edgeDotVelocity * newT - edgeDotBaseToVertex) /
//                          edgeSquaredLength;
//                if (f >= 0.0 && f <= 1.0)
//                {
//                    // Intersection took place within segment.
//                    t = newT;
//                    foundCollision = true;
//                    collisionPoint = p2 + (edge * f);
//                }
//            }
//            // p3 -> p1:
//            edge = p1 - p3;
//            baseToVertex = p3 - base;
//            edgeSquaredLength = edge.squaredlLength();
//            edgeDotVelocity = edge * velocity;
//            edgeDotBaseToVertex = edge * baseToVertex;

//            // Calculate parameters for equation
//            a = edgeSquaredLength * -velocitySquaredLength +
//                edgeDotVelocity * edgeDotVelocity;
//            b = edgeSquaredLength * ((velocity * baseToVertex) * 2) -
//                2.0 * edgeDotVelocity * edgeDotBaseToVertex;
//            c = edgeSquaredLength * (1 - baseToVertex.squaredlLength()) +
//                edgeDotBaseToVertex * edgeDotBaseToVertex;

//            // Does the swept sphere collide against infinite edge?
//            if (JMath::getLowestRoot(a, b, c, t, &newT))
//            {
//                // Check if intersection is within line segment:
//                float f = (edgeDotVelocity * newT - edgeDotBaseToVertex) /
//                          edgeSquaredLength;
//                if (f >= 0.0 && f <= 1.0)
//                {
//                    // Intersection took place within segment.
//                    t = newT;
//                    foundCollision = true;
//                    collisionPoint = p3 + (edge * f);
//                }
//            }
//        }
//        // Set result:
//        if (foundCollision)
//        {
//            // distance to collision: 't' is time of collision
//            float distToCollision = t * colPackage->velocity.length();

//            // Does the triangle qualify for the closest hit?
//            // It does if it's the first hit or the closest
//            if (!colPackage->foundCollision || distToCollision < colPackage->nearestDistance)
//            {
//                // Collision information necessary for sliding
//                colPackage->nearestDistance = distToCollision;
//                colPackage->intersectionPoint = collisionPoint;
//                colPackage->foundCollision = true;
//            }
//            qDebug() << "Found collision with triangle of these coordinates: P1: (" +
//                            QString::number(p1.getX() * colPackage->eRadius.at(0)) + ", " + QString::number(p1.getY() * colPackage->eRadius.at(1)) +
//                            ", " + QString::number(p1.getZ() * colPackage->eRadius.at(2)) + ") P2: (" +
//                            QString::number(p2.getX() * colPackage->eRadius.at(0)) + ", " + QString::number(p2.getY() * colPackage->eRadius.at(1)) +
//                            ", " + QString::number(p2.getZ() * colPackage->eRadius.at(2)) + ") P3: (" +
//                            QString::number(p3.getX() * colPackage->eRadius.at(0)) + ", " + QString::number(p3.getY() * colPackage->eRadius.at(1)) +
//                            ", " + QString::number(p3.getZ() * colPackage->eRadius.at(2)) + ")";
//            qDebug() << "Collision occurred at: (" +
//                            QString::number(collisionPoint.getX() * colPackage->eRadius.at(0)) +
//                            ", " + QString::number(collisionPoint.getY() * colPackage->eRadius.at(1)) +
//                            ", " + QString::number(collisionPoint.getZ() * colPackage->eRadius.at(2)) + ")";
//        }
//    }
//}
