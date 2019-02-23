#include "game.h"
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
}
bool Game::CheckCollisions(const OctahedronBall &first, const GameObject &second)
{
    Vec3 center(first.position().getX() + first.radius(), 0, first.position().getZ() + first.radius());
    Vec3 otherCenter(Vec3(0, 0, 1) /* + second.radius()*/);
    Vec3 distance = center - otherCenter;

    return distance.length() < first.radius();
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
    DoCollisions();
}

OctahedronBall *Game::getPawn()
{
    return ball;
}

void Game::switchLevels()
{
    currentLevel++;
    if (currentLevel == levels.size())
        currentLevel = 0;
    // Do extra stuff here to reset the ball etc.
}

void Game::DoCollisions()
{
    for (GameObject *level : levels) // just checking against the main scene atm
        if (CheckCollisions(*ball, *level))
        {
            qDebug() << "Collision";
            // Very rudimentary collision detection/resolution
            ball->move(ball->velocity() * -0.5); // Move the ball in the opposite direction it just moved from
        }
}
