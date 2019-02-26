#include "sceneone.h"
#include "trianglesurface.h"
#include <tuple>

Sceneone::Sceneone()
{
    //    objects.push_back(new GameObject(drawPlane(), "Floor"));
    objects.push_back(new GameObject(drawRightWall(), "Right Wall"));
    objects.push_back(new GameObject(drawLeftWall(), "Left Wall"));
    objects.push_back(new GameObject(drawBackWall(), "Back Wall"));
    objects.push_back(new GameObject(drawFrontWall(), "Front Wall"));
}

Sceneone::~Sceneone()
{
    for (GameObject *object : objects)
        delete object;
}

void Sceneone::init(GLint matrixUniform)
{
    for (GameObject *object : objects)
        object->init(matrixUniform);
}

void Sceneone::draw()
{
    for (GameObject *object : objects)
        object->draw();
}

TriangleArray Sceneone::getSceneTriangles() const
{
    return sceneTriangles;
}

TriangleArray Sceneone::drawPlane()
{
    // Plane
    TriangleArray triangleArr;
    std::tuple<Vertex, Vertex, Vertex> Triangle;
    Vertex vert1 = Vertex{-0.8, 0, 0.8, 0.5, 1, 1};
    Vertex vert2 = Vertex{-0.8, 0, -0.8, 0.5, 1, 1};
    Vertex vert3 = Vertex{0.8, 0, -0.8, 0.5, 1, 1};
    Triangle = std::make_tuple(vert1, vert2, vert3);

    triangleArr.push_back(Triangle);

    vert1 = Vertex{-0.8, 0, 0.8, 0.5, 1, 1};
    vert2 = Vertex{0.8, 0, 0.8, 0.5, 1, 1};
    vert3 = Vertex{0.8, 0, -0.8, 0.5, 1, 1};
    Triangle = std::make_tuple(vert1, vert2, vert3);

    triangleArr.push_back(Triangle);
    return triangleArr;
}

TriangleArray Sceneone::drawRightWall()
{
    // Right Wall
    TriangleArray triangleArr;
    std::tuple<Vertex, Vertex, Vertex> Triangle;
    Vertex vert1 = Vertex{0.8, 0, 0.8, 1, 1, 0};
    Vertex vert2 = Vertex{0.8, 0.4, 0.8, 1, 0, 1};
    Vertex vert3 = Vertex{0.8, 0, -0.8, 0, 1, 1};
    Triangle = std::make_tuple(vert1, vert2, vert3);

    triangleArr.push_back(Triangle);

    vert1 = Vertex{0.8, 0.4, 0.8, 1, 1, 0};
    vert2 = Vertex{0.8, 0.4, -0.8, 1, 0, 1};
    vert3 = Vertex{0.8, 0, -0.8, 0, 1, 1};
    Triangle = std::make_tuple(vert1, vert2, vert3);

    triangleArr.push_back(Triangle);
    return triangleArr;
}

TriangleArray Sceneone::drawLeftWall()
{
    // Left Wall
    TriangleArray triangleArr;
    std::tuple<Vertex, Vertex, Vertex> Triangle;
    Vertex vert1 = Vertex{-0.8, 0, 0.8, 1, 0, 1};
    Vertex vert2 = Vertex{-0.8, 0.4, 0.8, 1, 1, 0};
    Vertex vert3 = Vertex{-0.8, 0, -0.8, 0, 1, 1};
    Triangle = std::make_tuple(vert1, vert2, vert3);

    triangleArr.push_back(Triangle);

    vert1 = Vertex{-0.8, 0.4, 0.8, 1, 0, 1};
    vert2 = Vertex{-0.8, 0.4, -0.8, 1, 1, 0};
    vert3 = Vertex{-0.8, 0, -0.8, 0, 1, 1};
    Triangle = std::make_tuple(vert1, vert2, vert3);

    triangleArr.push_back(Triangle);
    return triangleArr;
}

TriangleArray Sceneone::drawBackWall()
{
    TriangleArray triangleArr;
    std::tuple<Vertex, Vertex, Vertex> Triangle;
    // Back Wall
    Vertex vert1 = Vertex{0.8, 0, 0.8, 0, 0, 1};
    Vertex vert2 = Vertex{0.8, 0.4, 0.8, 0, 0, 1};
    Vertex vert3 = Vertex{-0.8, 0, 0.8, 0, 0, 1};
    Triangle = std::make_tuple(vert1, vert2, vert3);

    triangleArr.push_back(Triangle);

    vert1 = Vertex{0.8, 0.4, 0.8, 0, 0, 1};
    vert2 = Vertex{-0.8, 0.4, 0.8, 0, 0, 1};
    vert3 = Vertex{-0.8, 0, 0.8, 0, 0, 1};
    Triangle = std::make_tuple(vert1, vert2, vert3);

    triangleArr.push_back(Triangle);
    return triangleArr;
}

TriangleArray Sceneone::drawFrontWall()
{
    TriangleArray triangleArr;
    std::tuple<Vertex, Vertex, Vertex> Triangle;
    // Front Wall
    Vertex vert1 = Vertex{-0.8, 0, 0.8, 1, 0, 0};
    Vertex vert2 = Vertex{-0.8, 0.4, 0.8, 1, 0, 0};
    Vertex vert3 = Vertex{-0.8, 0, -0.8, 1, 0, 0};
    Triangle = std::make_tuple(vert1, vert2, vert3);
    triangleArr.push_back(Triangle);

    vert1 = Vertex{-0.8, 0.4, 0.8, 1, 0, 0};
    vert2 = Vertex{-0.8, 0.4, -0.8, 1, 0, 0};
    vert3 = Vertex{-0.8, 0, -0.8, 1, 0, 0};
    Triangle = std::make_tuple(vert1, vert2, vert3);
    triangleArr.push_back(Triangle);
    return triangleArr;
}
