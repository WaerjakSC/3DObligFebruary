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
    ball = new OctahedronBall(3, 0.2, this);
    // Move these plus the gameObjects vector into the levels class once we get more objects.
    levels.push_back(new Sceneone);
    sceneOne = new Sceneone;
    levels.push_back(new Scenetwo);
    collision = new Collision;
}
void Game::CheckCollisions(CollisionPacket *collisionPackage)
{
    // Currently checks all the triangles of sceneOne against
    // the current position of the player...
    eSpaceTriangle = sceneOne->getSceneTriangles();

    // Convert the triangle points into ellipsoid space (aka the character collider's local space)
    for (unsigned int i = 0; i < eSpaceTriangle.size() - 1; i++)
    {
        eSpaceTriangle.at(i).at(0) = eSpaceTriangle.at(i).at(0) / collisionPackage->eRadius.at(0);
        eSpaceTriangle.at(i).at(1) = eSpaceTriangle.at(i).at(1) / collisionPackage->eRadius.at(1);
        eSpaceTriangle.at(i).at(2) = eSpaceTriangle.at(i).at(2) / collisionPackage->eRadius.at(2);
    }
    for (int i = 0; i < 10; i++)
    {
        collision->checkTriangle(collisionPackage, eSpaceTriangle.at(i * 3),
                                 eSpaceTriangle.at((i * 3) + 1), eSpaceTriangle.at((i * 3) + 2));
    }
}

void Game::init(GLint matrixUniform)
{
    mMatrixUniform = matrixUniform;

    ball->init(mMatrixUniform);
    for (GameObject *object : gameObjects)
        object->init(mMatrixUniform);
    //    for (GameObject *level : levels)
    //    {
    //        level->init(mMatrixUniform);
    //    }
    sceneOne->init(mMatrixUniform);
}

void Game::Tick()
{
    for (GameObject *object : gameObjects)
        object->draw();
    ball->draw();
    //    levels[currentLevel]->draw();
    sceneOne->draw();

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
 */
void Game::switchLevels()
{
    currentLevel++;
    if (currentLevel == levels.size())
        currentLevel = 0;
    // Do extra stuff here to reset the ball etc.
}
