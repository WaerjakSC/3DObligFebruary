#include "octahedronball.h"
#include "collisionpacket.h"
#include "game.h"
#include "gameobject.h"
#include "plane.h"
#include <iostream>
#include <sstream>
//! \param n - the recursion level (default is 0 which makes the original Octahedron)
//!
//! The number of (duplicated) vertices are calculated based on the parameter n - the recursion level.
//! Initially we have 8 triangles, each with 3 vertices.
//! A subdivision consists of
//! - compute the midpoint of each edge in a triangel
//! - add these midpoint as vertices
//! - make three new edges by connecting new vertices
//! - preserve orientation
//! - move the three new points on the unit ball's surface by normalizing. Remember the vertex vector
//! is also a normal to the ball's surface.
//! The formula for the number of vertices is
//! m_nVertices = 3 * 8 * 4^n
//! where
//! - 3 comes from the number of vertices in a triangle,
//! - 8 comes from the original number of triangles in a regular Octahedron
//! - n is the recursion level (number of repeated subdivisions)
//!
OctahedronBall::OctahedronBall(int n, float radius, Game *game)
    : /*GameObject(mVertices, Vec3(0, radius, 0), Vec3(1, 1, 1)),*/
      m_rekursjoner(n), m_indeks(0), gameInst(game), mRadius(radius)
{
    mVertices.reserve(3 * 8 * pow(4, m_rekursjoner));
    oktaederUnitBall();
    collisionPackage = new CollisionPacket;
    thisObject = new GameObject(triArray, "Ball", Vec3(0, radius, 0), Vec3(radius, radius, radius));
}

// Parametre inn: xyz koordinatene til et triangle v1, v2, v3 ccw
// Bevarer orienteringen av hjørnene
//!
//! \brief OctahedronBall::lagTriangel()
//! \param v1 - position on the unit ball for vertex 1
//! \param v2 - position on the unit ball for vertex 2
//! \param v3 - position on the unit ball for vertex 3
//!
//! lagTriangel() creates vertex data for a triangle's 3 vertices. This is done in the
//! final step of recursion.
//!

Vec3 OctahedronBall::velocity() const
{
    return mVelocity;
}

// added a radius modifier, super messy though, should probably do it in a different way
void OctahedronBall::lagTriangel(const Vec3 &v1, const Vec3 &v2, const Vec3 &v3)
{
    Vertex vert1{};
    Vertex vert2{};
    Vertex vert3{};

    vert1.set_xyz(v1.getX() * mRadius, v1.getY() * mRadius, v1.getZ() * mRadius);    // koordinater v.x = v1.x, v.y=v1.y, v.z=v1.z
    vert1.set_normal(v1.getX() * mRadius, v1.getY() * mRadius, v1.getZ() * mRadius); // rgb
                                                                                     // v.set_st(0.0f, 0.0f);            // kan utelates
    vert2.set_xyz(v2.getX() * mRadius, v2.getY() * mRadius, v2.getZ() * mRadius);
    vert2.set_normal(v2.getX() * mRadius, v2.getY() * mRadius, v2.getZ() * mRadius);
    // v.set_st(1.0f, 0.0f);
    vert3.set_xyz(v3.getX() * mRadius, v3.getY() * mRadius, v3.getZ() * mRadius);
    vert3.set_normal(v3.getX() * mRadius, v3.getY() * mRadius, v3.getZ() * mRadius);
    // v.set_st(0.5f, 1.0f);
    std::tuple<Vertex, Vertex, Vertex> Triangles;
    Triangles = std::make_tuple(vert1, vert2, vert3);
    triArray.push_back(Triangles);
}

// Rekursiv subdivisjon av triangel
//!
//! \brief OctahedronBall::subDivide() recursive subdivision of a triangel
//! \param a coordinates for vertex a
//! \param b coordinates for vertex b
//! \param c coordinates for vertex c
//! \param n level of recursion
//!
//! The function tests
//! (if n>0)
//! - three new edge midpoints are computed and normalized,
//! - four new calls to subDivide() is done - one for each new triangle, preserving orientation
//! and with decreased parameter n
//! else
//! - call lagTriangel(a, b, c)
//!
void OctahedronBall::subDivide(const Vec3 &a, const Vec3 &b, const Vec3 &c, int n)
{
    if (n > 0)
    {
        Vec3 v1 = a + b;
        v1.normalize();
        Vec3 v2 = a + c;
        v2.normalize();
        Vec3 v3 = c + b;
        v3.normalize();
        subDivide(a, v1, v2, n - 1);
        subDivide(c, v2, v3, n - 1);
        subDivide(b, v3, v1, n - 1);
        subDivide(v3, v2, v1, n - 1);
    }
    else
    {
        lagTriangel(a, b, c);
    }
}

//!
//! \brief OctahedronBall::oktaederUnitBall() creates 8 unit ball vertices and call subDivide()
//!
//! If the parameter n of the constructor OctahedronBall() is zero, the result will be the
//! original octahedron consisting of 8 triangles with duplicated vertices.
//!
void OctahedronBall::oktaederUnitBall()
{
    Vec3 v0{0, 0, 1};
    Vec3 v1{1, 0, 0};
    Vec3 v2{0, 1, 0};
    Vec3 v3{-1, 0, 0};
    Vec3 v4{0, -1, 0};
    Vec3 v5{0, 0, -1};

    subDivide(v0, v1, v2, m_rekursjoner);
    subDivide(v0, v2, v3, m_rekursjoner);
    subDivide(v0, v3, v4, m_rekursjoner);
    subDivide(v0, v4, v1, m_rekursjoner);
    subDivide(v5, v2, v1, m_rekursjoner);
    subDivide(v5, v3, v2, m_rekursjoner);
    subDivide(v5, v4, v3, m_rekursjoner);
    subDivide(v5, v1, v4, m_rekursjoner);
}

void OctahedronBall::ResetPos()
{
    thisObject->resetPosition();
}

void OctahedronBall::MoveTo(Vector3D velocity)
{
    //    Vec3 newVel = velocity - thisObject->position();
    thisObject->move(velocity);
}

//!
//! \brief OctahedronBall::initVertexBufferObjects() calls glGenBuffers(), glBindBuffer() and glBufferdata()
//! for using later use of glDrawArrays()
//!
void OctahedronBall::init(GLint matrixUniform)
{
    thisObject->init(matrixUniform);
    // Any additional changes under or above GameObject::init
}
void OctahedronBall::draw()
{
    thisObject->draw();
}

Vec3 OctahedronBall::position()
{
    return thisObject->position();
}

void OctahedronBall::addForward(float speed)
{
    mVelocity = mFront * speed;
    MoveTo(mVelocity);
}

void OctahedronBall::strafe(float speed)
{
    mVelocity = (mFront ^ mUp) * speed;
    MoveTo(mVelocity);
}
float OctahedronBall::radius() const
{
    return mRadius;
}

// Deprecated collision functions below:
/**
 * @brief OctahedronBall::collideAndSlide Run this every time you move
 * with desired velocity gained from MoveForward/Strafe
 * @param vel
 * @param gravity
 */
//void OctahedronBall::collideAndSlide(const Vec3 &vel /*, const Vec3 &gravity*/)
//{
//    // Do collision detection:
//    collisionPackage->R3Position = thisObject->position();
//    collisionPackage->R3Velocity = vel;

//    // Calculate position and velocity in eSpace
//    Vec3 eSpacePosition;
//    Vec3 eSpaceVelocity;
//    // Using a change of basis wherein eRadius is the radius of the ellipsoid
//    // The simplified formula for multiplying each vector V with eRadius is
//    // (1/x,  1/y, 1/z) * V
//    // Or V / (x,y,z)
//    for (int i = 0; i < 3; i++)
//    {
//        eSpacePosition.at(i) = collisionPackage->R3Position.at(i) / collisionPackage->eRadius.at(i);
//        eSpaceVelocity.at(i) = collisionPackage->R3Velocity.at(i) / collisionPackage->eRadius.at(i);
//    }

//    // Iterate until we have our final position.
//    collisionRecursionDepth = 0;

//    Vec3 finalPosition = collideWithWorld(eSpacePosition, eSpaceVelocity);
//    for (int i = 0; i < 3; i++)
//    {
//        finalPosition.at(i) = finalPosition.at(i) * collisionPackage->eRadius.at(i);
//    }
//    // Do the final movement here
//    MoveTo(finalPosition);
//}

//Vec3 OctahedronBall::collideWithWorld(const Vec3 &pos, const Vec3 &vel)
//{
//    float unitScale = unitsPerMeter / 100.0f;
//    float veryCloseDistance = 0.005 * unitScale;

//    // do we need to worry?
//    if (collisionRecursionDepth > 5)
//        return pos;
//    // OK, we need to worry:
//    collisionPackage->velocity = vel;
//    collisionPackage->normalizedVelocity = vel;
//    collisionPackage->normalizedVelocity.normalize();
//    collisionPackage->basePoint = pos;
//    collisionPackage->foundCollision = false;

//    // Check for collision (calls the collision routines)
//    gameInst->CheckCollisions(collisionPackage);

//    if (!collisionPackage->foundCollision)
//    {
//        return pos + vel;
//    }

//    // *** Collision occurred ***

//    // The original destination point
//    Vec3 destinationPoint = pos + vel;
//    Vec3 newBasePoint = pos;

//    // only update if we are not already very close
//    // and if so we only move very close to intersection... not to the exact spot.
//    if (collisionPackage->nearestDistance >= veryCloseDistance)
//    {
//        Vec3 V = vel;
//        V.setLength(collisionPackage->nearestDistance - veryCloseDistance);
//        // Adjust polygon intersection point (so sliding
//        // plane will be unaffected by the fact that we move slightly less than collision tells us)
//        V.normalize();
//        collisionPackage->intersectionPoint = collisionPackage->intersectionPoint - (V * veryCloseDistance);
//    }
//    // Determine the sliding plane
//    Vec3 slidePlaneOrigin = collisionPackage->intersectionPoint;
//    Vec3 slidePlaneNormal = newBasePoint - collisionPackage->intersectionPoint;
//    slidePlaneNormal.normalize();
//    PLANE slidingPlane(slidePlaneOrigin, slidePlaneNormal);

//    Vec3 newDestinationPoint = destinationPoint -
//                               slidePlaneNormal *
//                                   slidingPlane.signedDistanceTo(destinationPoint);

//    // Generate the slide vector, which will become our new velocity vector for the next iteration
//    Vec3 newVelocityVector = newDestinationPoint - collisionPackage->intersectionPoint;

//    // Recurse:

//    // Don't recurse if the new velocity is very small
//    if (newVelocityVector.length() < veryCloseDistance)
//    {
//        return newBasePoint;
//    }
//    collisionRecursionDepth++;
//    return collideWithWorld(newBasePoint, newVelocityVector);
//}
