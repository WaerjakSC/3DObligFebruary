#include "sceneone.h"
Sceneone::Sceneone()
{
    plane = new GameObject(drawPlane());
    rWall = new GameObject(drawRightWall());
    lWall = new GameObject(drawLeftWall());
    fWall = new GameObject(drawFrontWall());
    bWall = new GameObject(drawBackWall());
    objects.push_back(plane);
    objects.push_back(rWall);
    objects.push_back(lWall);
    objects.push_back(fWall);
    objects.push_back(bWall);
}

Sceneone::~Sceneone()
{
    delete plane;
    delete rWall;
    delete lWall;
    delete fWall;
    delete bWall;
}

void Sceneone::init(GLint matrixUniform)
{
    plane->init(matrixUniform);
    rWall->init(matrixUniform);
    lWall->init(matrixUniform);
    fWall->init(matrixUniform);
    bWall->init(matrixUniform);
}

void Sceneone::draw()
{
    plane->draw();
    rWall->draw();
    lWall->draw();
    fWall->draw();
    bWall->draw();
}

std::vector<Vector3D> Sceneone::getSceneTriangles() const
{
    return sceneTriangles;
}

std::vector<Vertex> Sceneone::drawPlane()
{
    std::vector<Vertex> vertices;
    // Plane
    vertices.push_back(Vertex{-0.8, 0, 0.8, 0.5, 1, 1});
    vertices.push_back(Vertex{-0.8, 0, -0.8, 0.5, 1, 1});
    vertices.push_back(Vertex{0.8, 0, -0.8, 0.5, 1, 1});

    vertices.push_back(Vertex{-0.8, 0, 0.8, 0.5, 1, 1});
    vertices.push_back(Vertex{0.8, 0, 0.8, 0.5, 1, 1});
    vertices.push_back(Vertex{0.8, 0, -0.8, 0.5, 1, 1});
    return vertices;
}

std::vector<Vertex> Sceneone::drawRightWall()
{
    std::vector<Vertex> vertices;
    // Right Wall
    vertices.push_back(Vertex{0.8, 0, 0.8, 1, 1, 0});
    vertices.push_back(Vertex{0.8, 0.4, 0.8, 1, 0, 1});
    vertices.push_back(Vertex{0.8, 0, -0.8, 0, 1, 1});

    vertices.push_back(Vertex{0.8, 0.4, 0.8, 1, 1, 0});
    vertices.push_back(Vertex{0.8, 0.4, -0.8, 1, 0, 1});
    vertices.push_back(Vertex{0.8, 0, -0.8, 0, 1, 1});
    return vertices;
}

std::vector<Vertex> Sceneone::drawLeftWall()
{
    std::vector<Vertex> vertices;
    // Left Wall
    vertices.push_back(Vertex{-0.8, 0, 0.8, 1, 0, 1});
    vertices.push_back(Vertex{-0.8, 0.4, 0.8, 1, 1, 0});
    vertices.push_back(Vertex{-0.8, 0, -0.8, 0, 1, 1});

    vertices.push_back(Vertex{-0.8, 0.4, 0.8, 1, 0, 1});
    vertices.push_back(Vertex{-0.8, 0.4, -0.8, 1, 1, 0});
    vertices.push_back(Vertex{-0.8, 0, -0.8, 0, 1, 1});
    return vertices;
}

std::vector<Vertex> Sceneone::drawBackWall()
{
    std::vector<Vertex> vertices;
    // Back Wall
    vertices.push_back(Vertex{0.8, 0, 0.8, 0, 0, 1});
    vertices.push_back(Vertex{0.8, 0.4, 0.8, 0, 0, 1});
    vertices.push_back(Vertex{-0.8, 0, 0.8, 0, 0, 1});

    vertices.push_back(Vertex{0.8, 0.4, 0.8, 0, 0, 1});
    vertices.push_back(Vertex{-0.8, 0.4, 0.8, 0, 0, 1});
    vertices.push_back(Vertex{-0.8, 0, 0.8, 0, 0, 1});
    return vertices;
}

std::vector<Vertex> Sceneone::drawFrontWall()
{
    std::vector<Vertex> vertices;
    // Front Wall
    vertices.push_back(Vertex{-0.8, 0, 0.8, 1, 0, 0});
    vertices.push_back(Vertex{-0.8, 0.4, 0.8, 1, 0, 0});
    vertices.push_back(Vertex{-0.8, 0, -0.8, 1, 0, 0});

    vertices.push_back(Vertex{-0.8, 0.4, 0.8, 1, 0, 0});
    vertices.push_back(Vertex{-0.8, 0.4, -0.8, 1, 0, 0});
    vertices.push_back(Vertex{-0.8, 0, -0.8, 1, 0, 0});
    return vertices;
}
