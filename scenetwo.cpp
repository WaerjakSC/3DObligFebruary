#include "scenetwo.h"

Scenetwo::Scenetwo()
{
    // Create separate gameobjects of each item, turning Scenetwo into a level class instead
    //    floor = new GameObject(drawFloor());
    //    house = new GameObject(drawHouse());
    //    table = new GameObject(drawTable());
    //    door = new GameObject(drawDoor());
}
// Change to a function of 2 variables!
std::vector<Vertex> Scenetwo::drawFloor()
{
    std::vector<Vertex> vertices;
    vertices.push_back(Vertex{-1, -0.8, 1, 0, 0.3, 0.5});
    vertices.push_back(Vertex{-1, -0.8, -1, 0, 0.3, 0.5});
    vertices.push_back(Vertex{1, -0.8, -1, 0, 0.3, 0.5});

    vertices.push_back(Vertex{-1, -0.8, 1, 0, 0.3, 0.5});
    vertices.push_back(Vertex{1, -0.8, 1, 0, 0.3, 0.5});
    vertices.push_back(Vertex{1, -0.8, -1, 0, 0.3, 0.5});

    return vertices;
}
std::vector<Vertex> Scenetwo::drawDoor()
{
    std::vector<Vertex> vertices;
    vertices.push_back(Vertex{-0.1, -0.4, -0.8, 0.1, 0, 0.1});
    vertices.push_back(Vertex{-0.1, -0.8, -0.8, 0.1, 0, 0.1});
    vertices.push_back(Vertex{0.1, -0.8, -0.8, 0.1, 0, 0.1});

    vertices.push_back(Vertex{0.1, -0.4, -0.8, 0.1, 0, 0.1});
    vertices.push_back(Vertex{-0.1, -0.4, -0.8, 0.1, 0, 0.1});
    vertices.push_back(Vertex{0.1, -0.8, -0.8, 0.1, 0, 0.1});

    return vertices;
}

std::vector<Vertex> Scenetwo::drawHouse()
{
    std::vector<Vertex> vertices;
    // Left Wall
    vertices.push_back(Vertex{-0.8, -0.8, 0.8, 1, 0.5, 0.5});
    vertices.push_back(Vertex{-0.8, 0.1, 0.8, 1, 0.5, 0.5});
    vertices.push_back(Vertex{-0.8, -0.8, -0.8, 1, 0.5, 0.5});

    vertices.push_back(Vertex{-0.8, 0.1, 0.8, 1, 0.5, 0.5});
    vertices.push_back(Vertex{-0.8, 0.1, -0.8, 1, 0.5, 0.5});
    vertices.push_back(Vertex{-0.8, -0.8, -0.8, 1, 0.5, 0.5});

    // Right Wall
    vertices.push_back(Vertex{0.8, -0.8, 0.8, 1, 0.5, 0.5});
    vertices.push_back(Vertex{0.8, 0.1, 0.8, 1, 0.5, 0.5});
    vertices.push_back(Vertex{0.8, -0.8, -0.8, 1, 0.5, 0.5});

    vertices.push_back(Vertex{0.8, 0.1, 0.8, 1, 0.5, 0.5});
    vertices.push_back(Vertex{0.8, 0.1, -0.8, 1, 0.5, 0.5});
    vertices.push_back(Vertex{0.8, -0.8, -0.8, 1, 0.5, 0.5});

    // Back Wall
    vertices.push_back(Vertex{0.8, -0.8, 0.8, 1, 0.5, 0.5});
    vertices.push_back(Vertex{0.8, 0.1, 0.8, 1, 0.5, 0.5});
    vertices.push_back(Vertex{-0.8, -0.8, 0.8, 1, 0.5, 0.5});

    vertices.push_back(Vertex{0.8, 0.1, 0.8, 1, 0.5, 0.5});
    vertices.push_back(Vertex{-0.8, 0.1, 0.8, 1, 0.5, 0.5});
    vertices.push_back(Vertex{-0.8, -0.8, 0.8, 1, 0.5, 0.5});

    // Front Wall 1
    vertices.push_back(Vertex{-0.8, -0.8, -0.8, 1, 0.5, 0.5});
    vertices.push_back(Vertex{-0.8, 0.1, -0.8, 1, 0.5, 0.5});
    vertices.push_back(Vertex{-0.1, -0.8, -0.8, 1, 0.5, 0.5});

    vertices.push_back(Vertex{-0.8, 0.1, -0.8, 1, 0.5, 0.5});
    vertices.push_back(Vertex{-0.1, 0.1, -0.8, 1, 0.5, 0.5});
    vertices.push_back(Vertex{-0.1, -0.8, -0.8, 1, 0.5, 0.5});

    // Front Wall 2
    vertices.push_back(Vertex{0.8, -0.8, -0.8, 1, 0.5, 0.5});
    vertices.push_back(Vertex{0.8, 0.1, -0.8, 1, 0.5, 0.5});
    vertices.push_back(Vertex{0.1, -0.8, -0.8, 1, 0.5, 0.5});

    vertices.push_back(Vertex{0.8, 0.1, -0.8, 1, 0.5, 0.5});
    vertices.push_back(Vertex{0.1, 0.1, -0.8, 1, 0.5, 0.5});
    vertices.push_back(Vertex{0.1, -0.8, -0.8, 1, 0.5, 0.5});

    // Front wall upper
    vertices.push_back(Vertex{-0.1, 0.1, -0.8, 1, 0.5, 0.5});
    vertices.push_back(Vertex{-0.1, -0.4, -0.8, 1, 0.5, 0.5});
    vertices.push_back(Vertex{0.1, -0.4, -0.8, 1, 0.5, 0.5});

    vertices.push_back(Vertex{0.1, 0.1, -0.8, 1, 0.5, 0.5});
    vertices.push_back(Vertex{-0.1, 0.1, -0.8, 1, 0.5, 0.5});
    vertices.push_back(Vertex{0.1, -0.4, -0.8, 1, 0.5, 0.5});

    // Upper front wall
    vertices.push_back(Vertex{-0.8, 0.1, -0.8, 1, 0.5, 0.5});
    vertices.push_back(Vertex{0, 0.1, -0.8, 1, 0.5, 0.5});
    vertices.push_back(Vertex{0, 0.9, -0.8, 1, 0.5, 0.5});

    vertices.push_back(Vertex{0.8, 0.1, -0.8, 1, 0.5, 0.5});
    vertices.push_back(Vertex{0, 0.1, -0.8, 1, 0.5, 0.5});
    vertices.push_back(Vertex{0, 0.9, -0.8, 1, 0.5, 0.5});

    // Upper back wall
    vertices.push_back(Vertex{-0.8, 0.1, 0.8, 1, 0.5, 0.5});
    vertices.push_back(Vertex{0, 0.1, 0.8, 1, 0.5, 0.5});
    vertices.push_back(Vertex{0, 0.9, 0.8, 1, 0.5, 0.5});

    vertices.push_back(Vertex{0.8, 0.1, 0.8, 1, 0.5, 0.5});
    vertices.push_back(Vertex{0, 0.1, 0.8, 1, 0.5, 0.5});
    vertices.push_back(Vertex{0, 0.9, 0.8, 1, 0.5, 0.5});

    // Left Roof
    vertices.push_back(Vertex{-0.9, 0, 0.9, 0.1, 0.1, 0.1});
    vertices.push_back(Vertex{-0.9, 0, -0.9, 0.1, 0.1, 0.1});
    vertices.push_back(Vertex{0, 0.9, -0.9, 0.1, 0.1, 0.1});

    vertices.push_back(Vertex{-0.9, 0, 0.9, 0.1, 0.1, 0.1});
    vertices.push_back(Vertex{0, 0.9, 0.9, 0.1, 0.1, 0.1});
    vertices.push_back(Vertex{0, 0.9, -0.9, 0.1, 0.1, 0.1});

    // Right Roof
    vertices.push_back(Vertex{0.9, 0, 0.9, 0.1, 0.1, 0.1});
    vertices.push_back(Vertex{0.9, 0, -0.9, 0.1, 0.1, 0.1});
    vertices.push_back(Vertex{0, 0.9, -0.9, 0.1, 0.1, 0.1});

    vertices.push_back(Vertex{0.9, 0, 0.9, 0.1, 0.1, 0.1});
    vertices.push_back(Vertex{0, 0.9, 0.9, 0.1, 0.1, 0.1});
    vertices.push_back(Vertex{0, 0.9, -0.9, 0.1, 0.1, 0.1});

    return vertices;
}

std::vector<Vertex> Scenetwo::drawTable()
{
    std::vector<Vertex> vertices;
    // Top plate
    vertices.push_back(Vertex{-0.1, -0.6, -0.1, 0.1, 0, 0.1});
    vertices.push_back(Vertex{0.1, -0.6, 0.1, 0.1, 0, 0.1});
    vertices.push_back(Vertex{-0.1, -0.6, 0.1, 0.1, 0, 0.1});

    vertices.push_back(Vertex{-0.1, -0.6, -0.1, 0.1, 0, 0.1});
    vertices.push_back(Vertex{0.1, -0.6, 0.1, 0.1, 0, 0.1});
    vertices.push_back(Vertex{0.1, -0.6, -0.1, 0.1, 0, 0.1});

    // Bottom left leg (-x/-z)
    vertices.push_back(Vertex{-0.1, -0.6, -0.1, 0.1, 0, 0.1});
    vertices.push_back(Vertex{-0.1, -0.6, -0.09, 0.1, 0, 0.1});
    vertices.push_back(Vertex{-0.1, -0.8, -0.1, 0.1, 0, 0.1});

    vertices.push_back(Vertex{-0.1, -0.6, -0.09, 0.1, 0, 0.1});
    vertices.push_back(Vertex{-0.1, -0.8, -0.09, 0.1, 0, 0.1});
    vertices.push_back(Vertex{-0.1, -0.8, -0.1, 0.1, 0, 0.1});

    vertices.push_back(Vertex{-0.1, -0.6, -0.1, 0.1, 0, 0.1});
    vertices.push_back(Vertex{-0.09, -0.6, -0.1, 0.1, 0, 0.1});
    vertices.push_back(Vertex{-0.1, -0.8, -0.1, 0.1, 0, 0.1});

    vertices.push_back(Vertex{-0.09, -0.6, -0.1, 0.1, 0, 0.1});
    vertices.push_back(Vertex{-0.09, -0.8, -0.1, 0.1, 0, 0.1});
    vertices.push_back(Vertex{-0.1, -0.8, -0.1, 0.1, 0, 0.1});

    vertices.push_back(Vertex{-0.09, -0.6, -0.09, 0.1, 0, 0.1});
    vertices.push_back(Vertex{-0.1, -0.6, -0.09, 0.1, 0, 0.1});
    vertices.push_back(Vertex{-0.09, -0.8, -0.09, 0.1, 0, 0.1});

    vertices.push_back(Vertex{-0.1, -0.6, -0.09, 0.1, 0, 0.1});
    vertices.push_back(Vertex{-0.1, -0.8, -0.09, 0.1, 0, 0.1});
    vertices.push_back(Vertex{-0.09, -0.8, -0.09, 0.1, 0, 0.1});

    vertices.push_back(Vertex{-0.09, -0.6, -0.09, 0.1, 0, 0.1});
    vertices.push_back(Vertex{-0.09, -0.6, -0.1, 0.1, 0, 0.1});
    vertices.push_back(Vertex{-0.09, -0.8, -0.09, 0.1, 0, 0.1});

    vertices.push_back(Vertex{-0.09, -0.6, -0.1, 0.1, 0, 0.1});
    vertices.push_back(Vertex{-0.09, -0.8, -0.1, 0.1, 0, 0.1});
    vertices.push_back(Vertex{-0.09, -0.8, -0.09, 0.1, 0, 0.1});

    // Bottom Right leg (+x/-z)
    vertices.push_back(Vertex{0.1, -0.6, -0.1, 0.1, 0, 0.1});
    vertices.push_back(Vertex{0.1, -0.6, -0.09, 0.1, 0, 0.1});
    vertices.push_back(Vertex{0.1, -0.8, -0.1, 0.1, 0, 0.1});

    vertices.push_back(Vertex{0.1, -0.6, -0.09, 0.1, 0, 0.1});
    vertices.push_back(Vertex{0.1, -0.8, -0.09, 0.1, 0, 0.1});
    vertices.push_back(Vertex{0.1, -0.8, -0.1, 0.1, 0, 0.1});

    vertices.push_back(Vertex{0.1, -0.6, -0.1, 0.1, 0, 0.1});
    vertices.push_back(Vertex{0.09, -0.6, -0.1, 0.1, 0, 0.1});
    vertices.push_back(Vertex{0.1, -0.8, -0.1, 0.1, 0, 0.1});

    vertices.push_back(Vertex{0.09, -0.6, -0.1, 0.1, 0, 0.1});
    vertices.push_back(Vertex{0.09, -0.8, -0.1, 0.1, 0, 0.1});
    vertices.push_back(Vertex{0.1, -0.8, -0.1, 0.1, 0, 0.1});

    vertices.push_back(Vertex{0.09, -0.6, -0.09, 0.1, 0, 0.1});
    vertices.push_back(Vertex{0.1, -0.6, -0.09, 0.1, 0, 0.1});
    vertices.push_back(Vertex{0.09, -0.8, -0.09, 0.1, 0, 0.1});

    vertices.push_back(Vertex{0.1, -0.6, -0.09, 0.1, 0, 0.1});
    vertices.push_back(Vertex{0.1, -0.8, -0.09, 0.1, 0, 0.1});
    vertices.push_back(Vertex{0.09, -0.8, -0.09, 0.1, 0, 0.1});

    vertices.push_back(Vertex{0.09, -0.6, -0.09, 0.1, 0, 0.1});
    vertices.push_back(Vertex{0.09, -0.6, -0.1, 0.1, 0, 0.1});
    vertices.push_back(Vertex{0.09, -0.8, -0.09, 0.1, 0, 0.1});

    vertices.push_back(Vertex{0.09, -0.6, -0.1, 0.1, 0, 0.1});
    vertices.push_back(Vertex{0.09, -0.8, -0.1, 0.1, 0, 0.1});
    vertices.push_back(Vertex{0.09, -0.8, -0.09, 0.1, 0, 0.1});

    // Top left leg (-x/+z)
    vertices.push_back(Vertex{-0.1, -0.6, 0.1, 0.1, 0, 0.1});
    vertices.push_back(Vertex{-0.1, -0.6, 0.09, 0.1, 0, 0.1});
    vertices.push_back(Vertex{-0.1, -0.8, 0.1, 0.1, 0, 0.1});

    vertices.push_back(Vertex{-0.1, -0.6, 0.09, 0.1, 0, 0.1});
    vertices.push_back(Vertex{-0.1, -0.8, 0.09, 0.1, 0, 0.1});
    vertices.push_back(Vertex{-0.1, -0.8, 0.1, 0.1, 0, 0.1});

    vertices.push_back(Vertex{-0.1, -0.6, 0.1, 0.1, 0, 0.1});
    vertices.push_back(Vertex{-0.09, -0.6, 0.1, 0.1, 0, 0.1});
    vertices.push_back(Vertex{-0.1, -0.8, 0.1, 0.1, 0, 0.1});

    vertices.push_back(Vertex{-0.09, -0.6, 0.1, 0.1, 0, 0.1});
    vertices.push_back(Vertex{-0.09, -0.8, 0.1, 0.1, 0, 0.1});
    vertices.push_back(Vertex{-0.1, -0.8, 0.1, 0.1, 0, 0.1});

    vertices.push_back(Vertex{-0.09, -0.6, 0.09, 0.1, 0, 0.1});
    vertices.push_back(Vertex{-0.1, -0.6, 0.09, 0.1, 0, 0.1});
    vertices.push_back(Vertex{-0.09, -0.8, 0.09, 0.1, 0, 0.1});

    vertices.push_back(Vertex{-0.1, -0.6, 0.09, 0.1, 0, 0.1});
    vertices.push_back(Vertex{-0.1, -0.8, 0.09, 0.1, 0, 0.1});
    vertices.push_back(Vertex{-0.09, -0.8, 0.09, 0.1, 0, 0.1});

    vertices.push_back(Vertex{-0.09, -0.6, 0.09, 0.1, 0, 0.1});
    vertices.push_back(Vertex{-0.09, -0.6, 0.1, 0.1, 0, 0.1});
    vertices.push_back(Vertex{-0.09, -0.8, 0.09, 0.1, 0, 0.1});

    vertices.push_back(Vertex{-0.09, -0.6, 0.1, 0.1, 0, 0.1});
    vertices.push_back(Vertex{-0.09, -0.8, 0.1, 0.1, 0, 0.1});
    vertices.push_back(Vertex{-0.09, -0.8, 0.09, 0.1, 0, 0.1});

    // Top right leg (+x/+z)
    vertices.push_back(Vertex{0.1, -0.6, 0.1, 0.1, 0, 0.1});
    vertices.push_back(Vertex{0.1, -0.6, 0.09, 0.1, 0, 0.1});
    vertices.push_back(Vertex{0.1, -0.8, 0.1, 0.1, 0, 0.1});

    vertices.push_back(Vertex{0.1, -0.6, 0.09, 0.1, 0, 0.1});
    vertices.push_back(Vertex{0.1, -0.8, 0.09, 0.1, 0, 0.1});
    vertices.push_back(Vertex{0.1, -0.8, 0.1, 0.1, 0, 0.1});

    vertices.push_back(Vertex{0.1, -0.6, 0.1, 0.1, 0, 0.1});
    vertices.push_back(Vertex{0.09, -0.6, 0.1, 0.1, 0, 0.1});
    vertices.push_back(Vertex{0.1, -0.8, 0.1, 0.1, 0, 0.1});

    vertices.push_back(Vertex{0.09, -0.6, 0.1, 0.1, 0, 0.1});
    vertices.push_back(Vertex{0.09, -0.8, 0.1, 0.1, 0, 0.1});
    vertices.push_back(Vertex{0.1, -0.8, 0.1, 0.1, 0, 0.1});

    vertices.push_back(Vertex{0.09, -0.6, 0.09, 0.1, 0, 0.1});
    vertices.push_back(Vertex{0.1, -0.6, 0.09, 0.1, 0, 0.1});
    vertices.push_back(Vertex{0.09, -0.8, 0.09, 0.1, 0, 0.1});

    vertices.push_back(Vertex{0.1, -0.6, 0.09, 0.1, 0, 0.1});
    vertices.push_back(Vertex{0.1, -0.8, 0.09, 0.1, 0, 0.1});
    vertices.push_back(Vertex{0.09, -0.8, 0.09, 0.1, 0, 0.1});

    vertices.push_back(Vertex{0.09, -0.6, 0.09, 0.1, 0, 0.1});
    vertices.push_back(Vertex{0.09, -0.6, 0.1, 0.1, 0, 0.1});
    vertices.push_back(Vertex{0.09, -0.8, 0.09, 0.1, 0, 0.1});

    vertices.push_back(Vertex{0.09, -0.6, 0.1, 0.1, 0, 0.1});
    vertices.push_back(Vertex{0.09, -0.8, 0.1, 0.1, 0, 0.1});
    vertices.push_back(Vertex{0.09, -0.8, 0.09, 0.1, 0, 0.1});

    return vertices;
}

void Scenetwo::openDoor()
{
    if (!doorOpen)
    {
        door->move(Vector3D(0, 0.4, 0));
        doorOpen = !doorOpen; // Set doorOpen to true
    }
    else // if doorOpen is true
    {
        door->move(Vector3D(0, -0.4, 0));
        doorOpen = !doorOpen; // Set doorOpen to false
    }
}
// Initialize all the objects in the scene
void Scenetwo::init(GLint matrixUniform)
{
    floor->init(matrixUniform);
    house->init(matrixUniform);
    table->init(matrixUniform);
    door->init(matrixUniform);
}
// Draw all the objects in the scene
void Scenetwo::draw()
{
    floor->draw();
    house->draw();
    table->draw();
    door->draw();
}
