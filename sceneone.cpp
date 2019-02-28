#include "sceneone.h"
#include "trianglesurface.h"
#include <tuple>

Sceneone::Sceneone()
{
    objects.push_back(new GameObject(drawPlane(), "Floor", Vec3(), Vec3(3, 3, 3)));
    objects.push_back(new GameObject(drawRightWall(), "Right Wall", Vec3(1.6, 0, 0), Vec3(1, 2, 3)));
    objects.push_back(new GameObject(drawLeftWall(), "Left Wall", Vec3(-1.6, 0, 0), Vec3(1, 2, 3)));
    objects.push_back(new GameObject(drawBackWall(), "Back Wall", Vec3(0, 0.7, 2), Vec3(2, 2, 2)));
    objects.push_back(new GameObject(drawFrontWall(), "Front Wall", Vec3(3.2, 0, 0), Vec3(3, 2, 1), Vec3(0, 1, 0), 90));
    objects.push_back(new GameObject(drawFrontWall(), "Front Wall 2", Vec3(-1.61, 0, 3.2), Vec3(0.6, 2, 1), Vec3(0, 1, 0), 90));
    objects.push_back(new GameObject(drawFrontWall(), "Front Wall 3", Vec3(-1.61, 0, -4), Vec3(0.5, 2, 1), Vec3(0, 1, 0), 90));
    door = new GameObject(drawDoor(), "Door", Vec3(0, 0.7, 2), Vec3(2, 2, 2));
    objects.push_back(door);
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
void Sceneone::openDoor()
{
    if (!doorOpen)
    {
        door->move(Vector3D(0, 0.4, -0.1));
        doorOpen = !doorOpen; // Set doorOpen to true
    }
    else // if doorOpen is true
    {
        door->move(Vector3D(0, -0.4, 0.1));
        doorOpen = !doorOpen; // Set doorOpen to false
    }
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
    // Front Wall 1
    Vertex vert1 = Vertex{-0.8, -0.8, -0.8, 1, 0.5, 0.5};
    Vertex vert2 = Vertex{-0.8, 0.1, -0.8, 1, 0.5, 0.5};
    Vertex vert3 = Vertex{-0.1, -0.8, -0.8, 1, 0.5, 0.5};
    Triangle = std::make_tuple(vert1, vert2, vert3);

    triangleArr.push_back(Triangle);

    vert1 = Vertex{-0.8, 0.1, -0.8, 1, 0.5, 0.5};
    vert2 = Vertex{-0.1, 0.1, -0.8, 1, 0.5, 0.5};
    vert3 = Vertex{-0.1, -0.8, -0.8, 1, 0.5, 0.5};
    Triangle = std::make_tuple(vert1, vert2, vert3);

    triangleArr.push_back(Triangle);

    // Front Wall 2
    vert1 = Vertex{0.8, -0.8, -0.8, 1, 0.5, 0.5};
    vert2 = Vertex{0.8, 0.1, -0.8, 1, 0.5, 0.5};
    vert3 = Vertex{0.1, -0.8, -0.8, 1, 0.5, 0.5};
    Triangle = std::make_tuple(vert1, vert2, vert3);

    triangleArr.push_back(Triangle);
    vert1 = Vertex{0.8, 0.1, -0.8, 1, 0.5, 0.5};
    vert2 = Vertex{0.1, 0.1, -0.8, 1, 0.5, 0.5};
    vert3 = Vertex{0.1, -0.8, -0.8, 1, 0.5, 0.5};
    Triangle = std::make_tuple(vert1, vert2, vert3);

    triangleArr.push_back(Triangle);
    // Front wall upper
    vert1 = Vertex{-0.1, 0.1, -0.8, 1, 0.5, 0.5};
    vert2 = Vertex{-0.1, -0.4, -0.8, 1, 0.5, 0.5};
    vert3 = Vertex{0.1, -0.4, -0.8, 1, 0.5, 0.5};
    Triangle = std::make_tuple(vert1, vert2, vert3);

    triangleArr.push_back(Triangle);
    vert1 = Vertex{0.1, 0.1, -0.8, 1, 0.5, 0.5};
    vert2 = Vertex{-0.1, 0.1, -0.8, 1, 0.5, 0.5};
    vert3 = Vertex{0.1, -0.4, -0.8, 1, 0.5, 0.5};
    Triangle = std::make_tuple(vert1, vert2, vert3);

    triangleArr.push_back(Triangle);
    // Upper front wall
    vert1 = Vertex{-0.8, 0.1, -0.8, 1, 0.5, 0.5};
    vert2 = Vertex{0, 0.1, -0.8, 1, 0.5, 0.5};
    vert3 = Vertex{0, 0.9, -0.8, 1, 0.5, 0.5};
    Triangle = std::make_tuple(vert1, vert2, vert3);

    triangleArr.push_back(Triangle);
    vert1 = Vertex{0.8, 0.1, -0.8, 1, 0.5, 0.5};
    vert2 = Vertex{0, 0.1, -0.8, 1, 0.5, 0.5};
    vert3 = Vertex{0, 0.9, -0.8, 1, 0.5, 0.5};
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

TriangleArray Sceneone::drawDoor()
{
    TriangleArray triangleArr;
    std::tuple<Vertex, Vertex, Vertex> Triangle;
    Vertex vert1 = Vertex{-0.1, -0.4, -0.8, 0.1, 0, 0.1};
    Vertex vert2 = Vertex{-0.1, -0.8, -0.8, 0.1, 0, 0.1};
    Vertex vert3 = Vertex{0.1, -0.8, -0.8, 0.1, 0, 0.1};
    Triangle = std::make_tuple(vert1, vert2, vert3);

    triangleArr.push_back(Triangle);
    vert1 = Vertex{0.1, -0.4, -0.8, 0.1, 0, 0.1};
    vert2 = Vertex{-0.1, -0.4, -0.8, 0.1, 0, 0.1};
    vert3 = Vertex{0.1, -0.8, -0.8, 0.1, 0, 0.1};
    Triangle = std::make_tuple(vert1, vert2, vert3);

    triangleArr.push_back(Triangle);
    return triangleArr;
}
