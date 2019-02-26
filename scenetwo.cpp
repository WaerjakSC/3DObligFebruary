#include "scenetwo.h"

Scenetwo::Scenetwo()
{
    // Create separate gameobjects of each item, turning Scenetwo into a level class instead
    objects.push_back(new GameObject(drawFloor(), "Floor", Vec3(0, -2.3, 0), Vec3(4, 1, 4)));
    objects.push_back(new GameObject(drawHouse(), "House", Vec3(), Vec3(4, 4, 4)));
    objects.push_back(new GameObject(drawTable(), "Table", Vec3(0, -0.25, 0), Vec3(3, 3, 3)));
    door = new GameObject(drawDoor(), "Door");
}

Scenetwo::~Scenetwo()
{
    for (GameObject *object : objects)
        delete object;
}
TriangleArray Scenetwo::getSceneTriangles() const
{
    return sceneTriangles;
}
// Change to a function of 2 variables!
TriangleArray Scenetwo::drawFloor()
{
    TriangleArray triangleArr;
    std::tuple<Vertex, Vertex, Vertex> Triangle;
    Vertex vert1 = Vertex{-1, -0.8, 1, 0, 0.3, 0.5};
    Vertex vert2 = Vertex{-1, -0.8, -1, 0, 0.3, 0.5};
    Vertex vert3 = Vertex{1, -0.8, -1, 0, 0.3, 0.5};
    Triangle = std::make_tuple(vert1, vert2, vert3);

    triangleArr.push_back(Triangle);
    vert1 = Vertex{-1, -0.8, 1, 0, 0.3, 0.5};
    vert2 = Vertex{1, -0.8, 1, 0, 0.3, 0.5};
    vert3 = Vertex{1, -0.8, -1, 0, 0.3, 0.5};
    Triangle = std::make_tuple(vert1, vert2, vert3);

    triangleArr.push_back(Triangle);
    return triangleArr;
}
TriangleArray Scenetwo::drawDoor()
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

TriangleArray Scenetwo::drawHouse()
{
    TriangleArray triangleArr;
    std::tuple<Vertex, Vertex, Vertex> Triangle;
    // Left Wall
    Vertex vert1 = Vertex{-0.8, -0.8, 0.8, 1, 0.5, 0.5};
    Vertex vert2 = Vertex{-0.8, 0.1, 0.8, 1, 0.5, 0.5};
    Vertex vert3 = Vertex{-0.8, -0.8, -0.8, 1, 0.5, 0.5};
    Triangle = std::make_tuple(vert1, vert2, vert3);

    triangleArr.push_back(Triangle);
    vert1 = Vertex{-0.8, 0.1, 0.8, 1, 0.5, 0.5};
    vert2 = Vertex{-0.8, 0.1, -0.8, 1, 0.5, 0.5};
    vert3 = Vertex{-0.8, -0.8, -0.8, 1, 0.5, 0.5};
    Triangle = std::make_tuple(vert1, vert2, vert3);

    triangleArr.push_back(Triangle);
    // Right Wall
    vert1 = Vertex{0.8, -0.8, 0.8, 1, 0.5, 0.5};
    vert2 = Vertex{0.8, 0.1, 0.8, 1, 0.5, 0.5};
    vert3 = Vertex{0.8, -0.8, -0.8, 1, 0.5, 0.5};
    Triangle = std::make_tuple(vert1, vert2, vert3);

    triangleArr.push_back(Triangle);
    vert1 = Vertex{0.8, 0.1, 0.8, 1, 0.5, 0.5};
    vert2 = Vertex{0.8, 0.1, -0.8, 1, 0.5, 0.5};
    vert3 = Vertex{0.8, -0.8, -0.8, 1, 0.5, 0.5};
    Triangle = std::make_tuple(vert1, vert2, vert3);

    triangleArr.push_back(Triangle);
    // Back Wall
    vert1 = Vertex{0.8, -0.8, 0.8, 1, 0.5, 0.5};
    vert2 = Vertex{0.8, 0.1, 0.8, 1, 0.5, 0.5};
    vert3 = Vertex{-0.8, -0.8, 0.8, 1, 0.5, 0.5};
    Triangle = std::make_tuple(vert1, vert2, vert3);

    triangleArr.push_back(Triangle);
    vert1 = Vertex{0.8, 0.1, 0.8, 1, 0.5, 0.5};
    vert2 = Vertex{-0.8, 0.1, 0.8, 1, 0.5, 0.5};
    vert3 = Vertex{-0.8, -0.8, 0.8, 1, 0.5, 0.5};
    Triangle = std::make_tuple(vert1, vert2, vert3);

    triangleArr.push_back(Triangle);
    // Front Wall 1
    vert1 = Vertex{-0.8, -0.8, -0.8, 1, 0.5, 0.5};
    vert2 = Vertex{-0.8, 0.1, -0.8, 1, 0.5, 0.5};
    vert3 = Vertex{-0.1, -0.8, -0.8, 1, 0.5, 0.5};
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
    // Upper back wall
    vert1 = Vertex{-0.8, 0.1, 0.8, 1, 0.5, 0.5};
    vert2 = Vertex{0, 0.1, 0.8, 1, 0.5, 0.5};
    vert3 = Vertex{0, 0.9, 0.8, 1, 0.5, 0.5};
    Triangle = std::make_tuple(vert1, vert2, vert3);

    triangleArr.push_back(Triangle);
    vert1 = Vertex{0.8, 0.1, 0.8, 1, 0.5, 0.5};
    vert2 = Vertex{0, 0.1, 0.8, 1, 0.5, 0.5};
    vert3 = Vertex{0, 0.9, 0.8, 1, 0.5, 0.5};
    Triangle = std::make_tuple(vert1, vert2, vert3);

    triangleArr.push_back(Triangle);
    // Left Roof
    vert1 = Vertex{-0.9, 0, 0.9, 0.1, 0.1, 0.1};
    vert2 = Vertex{-0.9, 0, -0.9, 0.1, 0.1, 0.1};
    vert3 = Vertex{0, 0.9, -0.9, 0.1, 0.1, 0.1};
    Triangle = std::make_tuple(vert1, vert2, vert3);

    triangleArr.push_back(Triangle);
    vert1 = Vertex{-0.9, 0, 0.9, 0.1, 0.1, 0.1};
    vert2 = Vertex{0, 0.9, 0.9, 0.1, 0.1, 0.1};
    vert3 = Vertex{0, 0.9, -0.9, 0.1, 0.1, 0.1};
    Triangle = std::make_tuple(vert1, vert2, vert3);

    triangleArr.push_back(Triangle);
    // Right Roof
    vert1 = Vertex{0.9, 0, 0.9, 0.1, 0.1, 0.1};
    vert2 = Vertex{0.9, 0, -0.9, 0.1, 0.1, 0.1};
    vert3 = Vertex{0, 0.9, -0.9, 0.1, 0.1, 0.1};
    Triangle = std::make_tuple(vert1, vert2, vert3);

    triangleArr.push_back(Triangle);
    vert1 = Vertex{0.9, 0, 0.9, 0.1, 0.1, 0.1};
    vert2 = Vertex{0, 0.9, 0.9, 0.1, 0.1, 0.1};
    vert3 = Vertex{0, 0.9, -0.9, 0.1, 0.1, 0.1};
    Triangle = std::make_tuple(vert1, vert2, vert3);

    triangleArr.push_back(Triangle);
    return triangleArr;
}

TriangleArray Scenetwo::drawTable()
{
    TriangleArray triangleArr;
    std::tuple<Vertex, Vertex, Vertex> Triangle;
    // Top plate
    Vertex vert1 = Vertex{-0.1, -0.6, -0.1, 0.1, 0, 0.1};
    Vertex vert2 = Vertex{0.1, -0.6, 0.1, 0.1, 0, 0.1};
    Vertex vert3 = Vertex{-0.1, -0.6, 0.1, 0.1, 0, 0.1};
    Triangle = std::make_tuple(vert1, vert2, vert3);

    triangleArr.push_back(Triangle);
    vert1 = Vertex{-0.1, -0.6, -0.1, 0.1, 0, 0.1};
    vert2 = Vertex{0.1, -0.6, 0.1, 0.1, 0, 0.1};
    vert3 = Vertex{0.1, -0.6, -0.1, 0.1, 0, 0.1};
    Triangle = std::make_tuple(vert1, vert2, vert3);

    triangleArr.push_back(Triangle);
    // Bottom left leg (-x/-z)
    vert1 = Vertex{-0.1, -0.6, -0.1, 0.1, 0, 0.1};
    vert2 = Vertex{-0.1, -0.6, -0.09, 0.1, 0, 0.1};
    vert3 = Vertex{-0.1, -0.8, -0.1, 0.1, 0, 0.1};
    Triangle = std::make_tuple(vert1, vert2, vert3);

    triangleArr.push_back(Triangle);
    vert1 = Vertex{-0.1, -0.6, -0.09, 0.1, 0, 0.1};
    vert2 = Vertex{-0.1, -0.8, -0.09, 0.1, 0, 0.1};
    vert3 = Vertex{-0.1, -0.8, -0.1, 0.1, 0, 0.1};
    Triangle = std::make_tuple(vert1, vert2, vert3);

    triangleArr.push_back(Triangle);
    vert1 = Vertex{-0.1, -0.6, -0.1, 0.1, 0, 0.1};
    vert2 = Vertex{-0.09, -0.6, -0.1, 0.1, 0, 0.1};
    vert3 = Vertex{-0.1, -0.8, -0.1, 0.1, 0, 0.1};
    Triangle = std::make_tuple(vert1, vert2, vert3);

    triangleArr.push_back(Triangle);
    vert1 = Vertex{-0.09, -0.6, -0.1, 0.1, 0, 0.1};
    vert2 = Vertex{-0.09, -0.8, -0.1, 0.1, 0, 0.1};
    vert3 = Vertex{-0.1, -0.8, -0.1, 0.1, 0, 0.1};
    Triangle = std::make_tuple(vert1, vert2, vert3);

    triangleArr.push_back(Triangle);
    vert1 = Vertex{-0.09, -0.6, -0.09, 0.1, 0, 0.1};
    vert2 = Vertex{-0.1, -0.6, -0.09, 0.1, 0, 0.1};
    vert3 = Vertex{-0.09, -0.8, -0.09, 0.1, 0, 0.1};
    Triangle = std::make_tuple(vert1, vert2, vert3);

    triangleArr.push_back(Triangle);
    vert1 = Vertex{-0.1, -0.6, -0.09, 0.1, 0, 0.1};
    vert2 = Vertex{-0.1, -0.8, -0.09, 0.1, 0, 0.1};
    vert3 = Vertex{-0.09, -0.8, -0.09, 0.1, 0, 0.1};
    Triangle = std::make_tuple(vert1, vert2, vert3);

    triangleArr.push_back(Triangle);
    vert1 = Vertex{-0.09, -0.6, -0.09, 0.1, 0, 0.1};
    vert2 = Vertex{-0.09, -0.6, -0.1, 0.1, 0, 0.1};
    vert3 = Vertex{-0.09, -0.8, -0.09, 0.1, 0, 0.1};
    Triangle = std::make_tuple(vert1, vert2, vert3);

    triangleArr.push_back(Triangle);
    vert1 = Vertex{-0.09, -0.6, -0.1, 0.1, 0, 0.1};
    vert2 = Vertex{-0.09, -0.8, -0.1, 0.1, 0, 0.1};
    vert3 = Vertex{-0.09, -0.8, -0.09, 0.1, 0, 0.1};
    Triangle = std::make_tuple(vert1, vert2, vert3);

    triangleArr.push_back(Triangle);
    // Bottom Right leg (+x/-z)
    vert1 = Vertex{0.1, -0.6, -0.1, 0.1, 0, 0.1};
    vert2 = Vertex{0.1, -0.6, -0.09, 0.1, 0, 0.1};
    vert3 = Vertex{0.1, -0.8, -0.1, 0.1, 0, 0.1};
    Triangle = std::make_tuple(vert1, vert2, vert3);

    triangleArr.push_back(Triangle);
    vert1 = Vertex{0.1, -0.6, -0.09, 0.1, 0, 0.1};
    vert2 = Vertex{0.1, -0.8, -0.09, 0.1, 0, 0.1};
    vert3 = Vertex{0.1, -0.8, -0.1, 0.1, 0, 0.1};
    Triangle = std::make_tuple(vert1, vert2, vert3);

    triangleArr.push_back(Triangle);
    vert1 = Vertex{0.1, -0.6, -0.1, 0.1, 0, 0.1};
    vert2 = Vertex{0.09, -0.6, -0.1, 0.1, 0, 0.1};
    vert3 = Vertex{0.1, -0.8, -0.1, 0.1, 0, 0.1};
    Triangle = std::make_tuple(vert1, vert2, vert3);

    triangleArr.push_back(Triangle);
    vert1 = Vertex{0.09, -0.6, -0.1, 0.1, 0, 0.1};
    vert2 = Vertex{0.09, -0.8, -0.1, 0.1, 0, 0.1};
    vert3 = Vertex{0.1, -0.8, -0.1, 0.1, 0, 0.1};
    Triangle = std::make_tuple(vert1, vert2, vert3);

    triangleArr.push_back(Triangle);
    vert1 = Vertex{0.09, -0.6, -0.09, 0.1, 0, 0.1};
    vert2 = Vertex{0.1, -0.6, -0.09, 0.1, 0, 0.1};
    vert3 = Vertex{0.09, -0.8, -0.09, 0.1, 0, 0.1};
    Triangle = std::make_tuple(vert1, vert2, vert3);

    triangleArr.push_back(Triangle);
    vert1 = Vertex{0.1, -0.6, -0.09, 0.1, 0, 0.1};
    vert2 = Vertex{0.1, -0.8, -0.09, 0.1, 0, 0.1};
    vert3 = Vertex{0.09, -0.8, -0.09, 0.1, 0, 0.1};
    Triangle = std::make_tuple(vert1, vert2, vert3);

    triangleArr.push_back(Triangle);
    vert1 = Vertex{0.09, -0.6, -0.09, 0.1, 0, 0.1};
    vert2 = Vertex{0.09, -0.6, -0.1, 0.1, 0, 0.1};
    vert3 = Vertex{0.09, -0.8, -0.09, 0.1, 0, 0.1};
    Triangle = std::make_tuple(vert1, vert2, vert3);

    triangleArr.push_back(Triangle);
    vert1 = Vertex{0.09, -0.6, -0.1, 0.1, 0, 0.1};
    vert2 = Vertex{0.09, -0.8, -0.1, 0.1, 0, 0.1};
    vert3 = Vertex{0.09, -0.8, -0.09, 0.1, 0, 0.1};
    Triangle = std::make_tuple(vert1, vert2, vert3);

    triangleArr.push_back(Triangle);
    // Top left leg (-x/+z)
    vert1 = Vertex{-0.1, -0.6, 0.1, 0.1, 0, 0.1};
    vert2 = Vertex{-0.1, -0.6, 0.09, 0.1, 0, 0.1};
    vert3 = Vertex{-0.1, -0.8, 0.1, 0.1, 0, 0.1};
    Triangle = std::make_tuple(vert1, vert2, vert3);

    triangleArr.push_back(Triangle);
    vert1 = Vertex{-0.1, -0.6, 0.09, 0.1, 0, 0.1};
    vert2 = Vertex{-0.1, -0.8, 0.09, 0.1, 0, 0.1};
    vert3 = Vertex{-0.1, -0.8, 0.1, 0.1, 0, 0.1};
    Triangle = std::make_tuple(vert1, vert2, vert3);

    triangleArr.push_back(Triangle);
    vert1 = Vertex{-0.1, -0.6, 0.1, 0.1, 0, 0.1};
    vert2 = Vertex{-0.09, -0.6, 0.1, 0.1, 0, 0.1};
    vert3 = Vertex{-0.1, -0.8, 0.1, 0.1, 0, 0.1};
    Triangle = std::make_tuple(vert1, vert2, vert3);

    triangleArr.push_back(Triangle);
    vert1 = Vertex{-0.09, -0.6, 0.1, 0.1, 0, 0.1};
    vert2 = Vertex{-0.09, -0.8, 0.1, 0.1, 0, 0.1};
    vert3 = Vertex{-0.1, -0.8, 0.1, 0.1, 0, 0.1};
    Triangle = std::make_tuple(vert1, vert2, vert3);

    triangleArr.push_back(Triangle);
    vert1 = Vertex{-0.09, -0.6, 0.09, 0.1, 0, 0.1};
    vert2 = Vertex{-0.1, -0.6, 0.09, 0.1, 0, 0.1};
    vert3 = Vertex{-0.09, -0.8, 0.09, 0.1, 0, 0.1};
    Triangle = std::make_tuple(vert1, vert2, vert3);

    triangleArr.push_back(Triangle);
    vert1 = Vertex{-0.1, -0.6, 0.09, 0.1, 0, 0.1};
    vert2 = Vertex{-0.1, -0.8, 0.09, 0.1, 0, 0.1};
    vert3 = Vertex{-0.09, -0.8, 0.09, 0.1, 0, 0.1};
    Triangle = std::make_tuple(vert1, vert2, vert3);

    triangleArr.push_back(Triangle);
    vert1 = Vertex{-0.09, -0.6, 0.09, 0.1, 0, 0.1};
    vert2 = Vertex{-0.09, -0.6, 0.1, 0.1, 0, 0.1};
    vert3 = Vertex{-0.09, -0.8, 0.09, 0.1, 0, 0.1};
    Triangle = std::make_tuple(vert1, vert2, vert3);

    triangleArr.push_back(Triangle);
    vert1 = Vertex{-0.09, -0.6, 0.1, 0.1, 0, 0.1};
    vert2 = Vertex{-0.09, -0.8, 0.1, 0.1, 0, 0.1};
    vert3 = Vertex{-0.09, -0.8, 0.09, 0.1, 0, 0.1};
    Triangle = std::make_tuple(vert1, vert2, vert3);

    triangleArr.push_back(Triangle);
    // Top right leg (+x/+z)
    vert1 = Vertex{0.1, -0.6, 0.1, 0.1, 0, 0.1};
    vert2 = Vertex{0.1, -0.6, 0.09, 0.1, 0, 0.1};
    vert3 = Vertex{0.1, -0.8, 0.1, 0.1, 0, 0.1};
    Triangle = std::make_tuple(vert1, vert2, vert3);

    triangleArr.push_back(Triangle);
    vert1 = Vertex{0.1, -0.6, 0.09, 0.1, 0, 0.1};
    vert2 = Vertex{0.1, -0.8, 0.09, 0.1, 0, 0.1};
    vert3 = Vertex{0.1, -0.8, 0.1, 0.1, 0, 0.1};
    Triangle = std::make_tuple(vert1, vert2, vert3);

    triangleArr.push_back(Triangle);
    vert1 = Vertex{0.1, -0.6, 0.1, 0.1, 0, 0.1};
    vert2 = Vertex{0.09, -0.6, 0.1, 0.1, 0, 0.1};
    vert3 = Vertex{0.1, -0.8, 0.1, 0.1, 0, 0.1};
    Triangle = std::make_tuple(vert1, vert2, vert3);

    triangleArr.push_back(Triangle);
    vert1 = Vertex{0.09, -0.6, 0.1, 0.1, 0, 0.1};
    vert2 = Vertex{0.09, -0.8, 0.1, 0.1, 0, 0.1};
    vert3 = Vertex{0.1, -0.8, 0.1, 0.1, 0, 0.1};
    Triangle = std::make_tuple(vert1, vert2, vert3);

    triangleArr.push_back(Triangle);
    vert1 = Vertex{0.09, -0.6, 0.09, 0.1, 0, 0.1};
    vert2 = Vertex{0.1, -0.6, 0.09, 0.1, 0, 0.1};
    vert3 = Vertex{0.09, -0.8, 0.09, 0.1, 0, 0.1};
    Triangle = std::make_tuple(vert1, vert2, vert3);

    triangleArr.push_back(Triangle);
    vert1 = Vertex{0.1, -0.6, 0.09, 0.1, 0, 0.1};
    vert2 = Vertex{0.1, -0.8, 0.09, 0.1, 0, 0.1};
    vert3 = Vertex{0.09, -0.8, 0.09, 0.1, 0, 0.1};
    Triangle = std::make_tuple(vert1, vert2, vert3);

    triangleArr.push_back(Triangle);
    vert1 = Vertex{0.09, -0.6, 0.09, 0.1, 0, 0.1};
    vert2 = Vertex{0.09, -0.6, 0.1, 0.1, 0, 0.1};
    vert3 = Vertex{0.09, -0.8, 0.09, 0.1, 0, 0.1};
    Triangle = std::make_tuple(vert1, vert2, vert3);

    triangleArr.push_back(Triangle);
    vert1 = Vertex{0.09, -0.6, 0.1, 0.1, 0, 0.1};
    vert2 = Vertex{0.09, -0.8, 0.1, 0.1, 0, 0.1};
    vert3 = Vertex{0.09, -0.8, 0.09, 0.1, 0, 0.1};
    Triangle = std::make_tuple(vert1, vert2, vert3);

    triangleArr.push_back(Triangle);
    return triangleArr;
}

void Scenetwo::openDoor()
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
// Initialize all the objects in the scene
void Scenetwo::init(GLint matrixUniform)
{
    for (GameObject *object : objects)
        object->init(matrixUniform);
}
// Draw all the objects in the scene
void Scenetwo::draw()
{
    for (GameObject *object : objects)
        object->draw();
}
