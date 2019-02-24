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
    ball = new OctahedronBall(3, 0.2);
    // Move these plus the gameObjects vector into the levels class once we get more objects.
    levels.push_back(new Sceneone);
    levels.push_back(new Scenetwo);
    collision = new Collision;
}
bool Game::CheckCollisions(CollisionPacket *collisionPackage)
{
    collision->checkTriangle(collisionPackage);
}

void Game::init(GLint matrixUniform)
{
    mMatrixUniform = matrixUniform;

    ball->init(mMatrixUniform);
    for (GameObject *object : gameObjects)
        object->init(mMatrixUniform);
    for (GameObject *level : levels)
    {
        level->init(mMatrixUniform);
    }
}

void Game::Tick()
{
    for (GameObject *object : gameObjects)
        object->draw();
    ball->draw();
    levels[currentLevel]->draw();
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
