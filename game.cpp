#include "game.h"
#include "collision.h"
#include "collisionpacket.h"
#include "gameobject.h"
#include "levels.h"
#include "octahedronball.h"
#include "sceneone.h"
#include "scenetwo.h"

Game::Game()
{
    ball = new OctahedronBall(3, 0.4, this);
    // Move these plus the gameObjects vector into the levels class once we get more objects.
    sceneOne = new Sceneone;
    sceneTwo = new Scenetwo;

    collision = new Collision;
}
void Game::CheckCollisions(CollisionPacket *collisionPackage)
{
    // Currently checks all the triangles of sceneOne against
    // the current position of the player...
    for (GameObject *object : sceneOne->objects)
    {
        // getTriangles() returns the object's array of triangles.
        eSpaceTriangle = object->getTriangles();
        // Convert the triangle points into ellipsoid space (aka the character collider's local space)
        for (unsigned int i = 0; i < eSpaceTriangle.size(); i++)
        {
            for (unsigned int j = 0; j < 3; j++)
            {
                //                eSpaceTriangle.at(i).at(j) = object->getModelMatrix() * eSpaceTriangle.at(i).at(j);

                eSpaceTriangle.at(i).at(j) = Vec3(eSpaceTriangle.at(i).at(j).at(0) / collisionPackage->eRadius.at(0),
                                                  eSpaceTriangle.at(i).at(j).at(1) / collisionPackage->eRadius.at(1),
                                                  eSpaceTriangle.at(i).at(j).at(2) / collisionPackage->eRadius.at(2));
            }
        }
        //        for (unsigned int i = 0; i < eSpaceTriangle.size() - 1; i++)
        //        {
        //            // first at() selects a tuple from a vector of three points (Vec3).
        //            // second at() selects one of those points
        //            collision->checkTriangle(collisionPackage, eSpaceTriangle.at(i).at(0),
        //                                     eSpaceTriangle.at(i).at(1), eSpaceTriangle.at(i).at(2));
        //        }
    }
}

void Game::init(GLint matrixUniform)
{
    mMatrixUniform = matrixUniform;

    ball->init(mMatrixUniform);
    sceneOne->init(mMatrixUniform);
    sceneTwo->init(mMatrixUniform);
}

void Game::Tick()
{

    ball->draw();
    if (currentLevel == 0)
        sceneOne->draw();
    else
        sceneTwo->draw();

    // Should probably call collideAndSlide from here or ball's own draw function, and update velocity dynamically
    // So that you can implement continuous motion and friction, i.e. moving and taking a split second to stop,
    // Or being moved by something and rolling a distance.
}

OctahedronBall *Game::getPawn()
{
    return ball;
}
/**
 * @brief Game::switchLevels switches between the two levels.
 * Should also reset the ball and any other objects, preferably with two separate level instances
 * Don't switch back to the 1st level, you will not find your ball :D
 */
void Game::switchLevels()
{
    ball->ResetPos();
    if (currentLevel == 1)
    {
        currentLevel = 0;
    }
    else
    {
        ball->MoveTo(Vec3(0, -2.8, 2));
        currentLevel++;
    }

    // Do extra stuff here to reset the ball etc.
}

int Game::getCurrentLevel() const
{
    return currentLevel;
}
