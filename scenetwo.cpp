#include "scenetwo.h"
#include "matrix4x4.h"
#include <cmath>

namespace jl
{

Scenetwo::Scenetwo()
{
    drawFloor();
    //drawHouse();
    drawTable();
    drawDoor();
}

// Change to a function of 2 variables!
void Scenetwo::drawFloor()
{

    mVertices.push_back(Vertex{-1, -0.8, 1, 0, 0.3, 0.5});
    mVertices.push_back(Vertex{-1, -0.8, -1, 0, 0.3, 0.5});
    mVertices.push_back(Vertex{1, -0.8, -1, 0, 0.3, 0.5});

    mVertices.push_back(Vertex{-1, -0.8, 1, 0, 0.3, 0.5});
    mVertices.push_back(Vertex{1, -0.8, 1, 0, 0.3, 0.5});
    mVertices.push_back(Vertex{1, -0.8, -1, 0, 0.3, 0.5});


}

void Scenetwo::drawHouse()
{
    // Left Wall
    mVertices.push_back(Vertex{-0.8, -0.8, 0.8, 1, 0.5, 0.5});
    mVertices.push_back(Vertex{-0.8, 0.1, 0.8, 1, 0.5, 0.5});
    mVertices.push_back(Vertex{-0.8, -0.8, -0.8, 1, 0.5, 0.5});

    mVertices.push_back(Vertex{-0.8, 0.1, 0.8, 1, 0.5, 0.5});
    mVertices.push_back(Vertex{-0.8, 0.1, -0.8, 1, 0.5, 0.5});
    mVertices.push_back(Vertex{-0.8, -0.8, -0.8, 1, 0.5, 0.5});

    // Right Wall
    mVertices.push_back(Vertex{0.8, -0.8, 0.8, 1, 0.5, 0.5});
    mVertices.push_back(Vertex{0.8, 0.1, 0.8, 1, 0.5, 0.5});
    mVertices.push_back(Vertex{0.8, -0.8, -0.8, 1, 0.5, 0.5});

    mVertices.push_back(Vertex{0.8, 0.1, 0.8, 1, 0.5, 0.5});
    mVertices.push_back(Vertex{0.8, 0.1, -0.8, 1, 0.5, 0.5});
    mVertices.push_back(Vertex{0.8, -0.8, -0.8, 1, 0.5, 0.5});

    // Back Wall
    mVertices.push_back(Vertex{0.8, -0.8, 0.8, 1, 0.5, 0.5});
    mVertices.push_back(Vertex{0.8, 0.1, 0.8, 1, 0.5, 0.5});
    mVertices.push_back(Vertex{-0.8, -0.8, 0.8, 1, 0.5, 0.5});

    mVertices.push_back(Vertex{0.8, 0.1, 0.8, 1, 0.5, 0.5});
    mVertices.push_back(Vertex{-0.8, 0.1, 0.8, 1, 0.5, 0.5});
    mVertices.push_back(Vertex{-0.8, -0.8, 0.8, 1, 0.5, 0.5});

    // Front Wall 1
    mVertices.push_back(Vertex{-0.8, -0.8, -0.8, 1, 0.5, 0.5});
    mVertices.push_back(Vertex{-0.8, 0.1, -0.8, 1, 0.5, 0.5});
    mVertices.push_back(Vertex{-0.1, -0.8, -0.8, 1, 0.5, 0.5});

    mVertices.push_back(Vertex{-0.8, 0.1, -0.8, 1, 0.5, 0.5});
    mVertices.push_back(Vertex{-0.1, 0.1, -0.8, 1, 0.5, 0.5});
    mVertices.push_back(Vertex{-0.1, -0.8, -0.8, 1, 0.5, 0.5});

    // Front Wall 2
    mVertices.push_back(Vertex{0.8, -0.8, -0.8, 1, 0.5, 0.5});
    mVertices.push_back(Vertex{0.8, 0.1, -0.8, 1, 0.5, 0.5});
    mVertices.push_back(Vertex{0.1, -0.8, -0.8, 1, 0.5, 0.5});

    mVertices.push_back(Vertex{0.8, 0.1, -0.8, 1, 0.5, 0.5});
    mVertices.push_back(Vertex{0.1, 0.1 , -0.8, 1, 0.5, 0.5});
    mVertices.push_back(Vertex{0.1, -0.8, -0.8, 1, 0.5, 0.5});

    // Front wall upper
    mVertices.push_back(Vertex{-0.1, 0.1, -0.8, 1, 0.5, 0.5});
    mVertices.push_back(Vertex{-0.1, -0.4, -0.8, 1, 0.5, 0.5});
    mVertices.push_back(Vertex{0.1, -0.4, -0.8, 1, 0.5, 0.5});

    mVertices.push_back(Vertex{0.1, 0.1, -0.8, 1, 0.5, 0.5});
    mVertices.push_back(Vertex{-0.1, 0.1, -0.8, 1, 0.5, 0.5});
    mVertices.push_back(Vertex{0.1, -0.4, -0.8, 1, 0.5, 0.5});

    // Upper front wall
    mVertices.push_back(Vertex{-0.8, 0.1, -0.8, 1, 0.5, 0.5});
    mVertices.push_back(Vertex{0, 0.1, -0.8, 1, 0.5, 0.5});
    mVertices.push_back(Vertex{0, 0.9, -0.8, 1, 0.5, 0.5});

    mVertices.push_back(Vertex{0.8, 0.1, -0.8, 1, 0.5, 0.5});
    mVertices.push_back(Vertex{0, 0.1, -0.8, 1, 0.5, 0.5});
    mVertices.push_back(Vertex{0, 0.9, -0.8, 1, 0.5, 0.5});

    // Upper back wall
    mVertices.push_back(Vertex{-0.8, 0.1, 0.8, 1, 0.5, 0.5});
    mVertices.push_back(Vertex{0, 0.1, 0.8, 1, 0.5, 0.5});
    mVertices.push_back(Vertex{0, 0.9, 0.8, 1, 0.5, 0.5});

    mVertices.push_back(Vertex{0.8, 0.1, 0.8, 1, 0.5, 0.5});
    mVertices.push_back(Vertex{0, 0.1, 0.8, 1, 0.5, 0.5});
    mVertices.push_back(Vertex{0, 0.9, 0.8, 1, 0.5, 0.5});

    // Left Roof
    mVertices.push_back(Vertex{-0.9, 0, 0.9, 0.1, 0.1, 0.1});
    mVertices.push_back(Vertex{-0.9, 0, -0.9, 0.1, 0.1, 0.1});
    mVertices.push_back(Vertex{0, 0.9, -0.9, 0.1, 0.1, 0.1});

    mVertices.push_back(Vertex{-0.9, 0, 0.9, 0.1, 0.1, 0.1});
    mVertices.push_back(Vertex{0, 0.9, 0.9, 0.1, 0.1, 0.1});
    mVertices.push_back(Vertex{0, 0.9, -0.9, 0.1, 0.1, 0.1});

    // Right Roof
    mVertices.push_back(Vertex{0.9, 0, 0.9, 0.1, 0.1, 0.1});
    mVertices.push_back(Vertex{0.9, 0, -0.9, 0.1, 0.1, 0.1});
    mVertices.push_back(Vertex{0, 0.9, -0.9, 0.1, 0.1, 0.1});

    mVertices.push_back(Vertex{0.9, 0, 0.9, 0.1, 0.1, 0.1});
    mVertices.push_back(Vertex{0, 0.9, 0.9, 0.1, 0.1, 0.1});
    mVertices.push_back(Vertex{0, 0.9, -0.9, 0.1, 0.1, 0.1});

}


void Scenetwo::drawTable()
{
    // Top plate
    mVertices.push_back(Vertex{-0.1, -0.6, -0.1, 0.1, 0, 0.1});
    mVertices.push_back(Vertex{0.1, -0.6, 0.1, 0.1, 0, 0.1});
    mVertices.push_back(Vertex{-0.1, -0.6, 0.1, 0.1, 0, 0.1});

    mVertices.push_back(Vertex{-0.1, -0.6, -0.1, 0.1, 0, 0.1});
    mVertices.push_back(Vertex{0.1, -0.6, 0.1, 0.1, 0, 0.1});
    mVertices.push_back(Vertex{0.1, -0.6, -0.1, 0.1, 0, 0.1});

    // Bottom left leg (-x/-z)
    mVertices.push_back(Vertex{-0.1, -0.6, -0.1, 0.1, 0, 0.1});
    mVertices.push_back(Vertex{-0.1, -0.6, -0.09, 0.1, 0, 0.1});
    mVertices.push_back(Vertex{-0.1, -0.8, -0.1, 0.1, 0, 0.1});

    mVertices.push_back(Vertex{-0.1, -0.6, -0.09, 0.1, 0, 0.1});
    mVertices.push_back(Vertex{-0.1, -0.8, -0.09, 0.1, 0, 0.1});
    mVertices.push_back(Vertex{-0.1, -0.8, -0.1, 0.1, 0, 0.1});

    mVertices.push_back(Vertex{-0.1, -0.6, -0.1, 0.1, 0, 0.1});
    mVertices.push_back(Vertex{-0.09, -0.6, -0.1, 0.1, 0, 0.1});
    mVertices.push_back(Vertex{-0.1, -0.8, -0.1, 0.1, 0, 0.1});

    mVertices.push_back(Vertex{-0.09, -0.6, -0.1, 0.1, 0, 0.1});
    mVertices.push_back(Vertex{-0.09, -0.8, -0.1, 0.1, 0, 0.1});
    mVertices.push_back(Vertex{-0.1, -0.8, -0.1, 0.1, 0, 0.1});

    mVertices.push_back(Vertex{-0.09, -0.6, -0.09, 0.1, 0, 0.1});
    mVertices.push_back(Vertex{-0.1, -0.6, -0.09, 0.1, 0, 0.1});
    mVertices.push_back(Vertex{-0.09, -0.8, -0.09, 0.1, 0, 0.1});

    mVertices.push_back(Vertex{-0.1, -0.6, -0.09, 0.1, 0, 0.1});
    mVertices.push_back(Vertex{-0.1, -0.8, -0.09, 0.1, 0, 0.1});
    mVertices.push_back(Vertex{-0.09, -0.8, -0.09, 0.1, 0, 0.1});

    mVertices.push_back(Vertex{-0.09, -0.6, -0.09, 0.1, 0, 0.1});
    mVertices.push_back(Vertex{-0.09, -0.6, -0.1, 0.1, 0, 0.1});
    mVertices.push_back(Vertex{-0.09, -0.8, -0.09, 0.1, 0, 0.1});

    mVertices.push_back(Vertex{-0.09, -0.6, -0.1, 0.1, 0, 0.1});
    mVertices.push_back(Vertex{-0.09, -0.8, -0.1, 0.1, 0, 0.1});
    mVertices.push_back(Vertex{-0.09, -0.8, -0.09, 0.1, 0, 0.1});

    // Bottom Right leg (+x/-z)
    mVertices.push_back(Vertex{0.1, -0.6, -0.1, 0.1, 0, 0.1});
    mVertices.push_back(Vertex{0.1, -0.6, -0.09, 0.1, 0, 0.1});
    mVertices.push_back(Vertex{0.1, -0.8, -0.1, 0.1, 0, 0.1});

    mVertices.push_back(Vertex{0.1, -0.6, -0.09, 0.1, 0, 0.1});
    mVertices.push_back(Vertex{0.1, -0.8, -0.09, 0.1, 0, 0.1});
    mVertices.push_back(Vertex{0.1, -0.8, -0.1, 0.1, 0, 0.1});

    mVertices.push_back(Vertex{0.1, -0.6, -0.1, 0.1, 0, 0.1});
    mVertices.push_back(Vertex{0.09, -0.6, -0.1, 0.1, 0, 0.1});
    mVertices.push_back(Vertex{0.1, -0.8, -0.1, 0.1, 0, 0.1});

    mVertices.push_back(Vertex{0.09, -0.6, -0.1, 0.1, 0, 0.1});
    mVertices.push_back(Vertex{0.09, -0.8, -0.1, 0.1, 0, 0.1});
    mVertices.push_back(Vertex{0.1, -0.8, -0.1, 0.1, 0, 0.1});

    mVertices.push_back(Vertex{0.09, -0.6, -0.09, 0.1, 0, 0.1});
    mVertices.push_back(Vertex{0.1, -0.6, -0.09, 0.1, 0, 0.1});
    mVertices.push_back(Vertex{0.09, -0.8, -0.09, 0.1, 0, 0.1});

    mVertices.push_back(Vertex{0.1, -0.6, -0.09, 0.1, 0, 0.1});
    mVertices.push_back(Vertex{0.1, -0.8, -0.09, 0.1, 0, 0.1});
    mVertices.push_back(Vertex{0.09, -0.8, -0.09, 0.1, 0, 0.1});

    mVertices.push_back(Vertex{0.09, -0.6, -0.09, 0.1, 0, 0.1});
    mVertices.push_back(Vertex{0.09, -0.6, -0.1, 0.1, 0, 0.1});
    mVertices.push_back(Vertex{0.09, -0.8, -0.09, 0.1, 0, 0.1});

    mVertices.push_back(Vertex{0.09, -0.6, -0.1, 0.1, 0, 0.1});
    mVertices.push_back(Vertex{0.09, -0.8, -0.1, 0.1, 0, 0.1});
    mVertices.push_back(Vertex{0.09, -0.8, -0.09, 0.1, 0, 0.1});

    // Top left leg (-x/+z)
    mVertices.push_back(Vertex{-0.1, -0.6, 0.1, 0.1, 0, 0.1});
    mVertices.push_back(Vertex{-0.1, -0.6, 0.09, 0.1, 0, 0.1});
    mVertices.push_back(Vertex{-0.1, -0.8, 0.1, 0.1, 0, 0.1});

    mVertices.push_back(Vertex{-0.1, -0.6, 0.09, 0.1, 0, 0.1});
    mVertices.push_back(Vertex{-0.1, -0.8, 0.09, 0.1, 0, 0.1});
    mVertices.push_back(Vertex{-0.1, -0.8, 0.1, 0.1, 0, 0.1});

    mVertices.push_back(Vertex{-0.1, -0.6, 0.1, 0.1, 0, 0.1});
    mVertices.push_back(Vertex{-0.09, -0.6, 0.1, 0.1, 0, 0.1});
    mVertices.push_back(Vertex{-0.1, -0.8, 0.1, 0.1, 0, 0.1});

    mVertices.push_back(Vertex{-0.09, -0.6, 0.1, 0.1, 0, 0.1});
    mVertices.push_back(Vertex{-0.09, -0.8, 0.1, 0.1, 0, 0.1});
    mVertices.push_back(Vertex{-0.1, -0.8, 0.1, 0.1, 0, 0.1});

    mVertices.push_back(Vertex{-0.09, -0.6, 0.09, 0.1, 0, 0.1});
    mVertices.push_back(Vertex{-0.1, -0.6, 0.09, 0.1, 0, 0.1});
    mVertices.push_back(Vertex{-0.09, -0.8, 0.09, 0.1, 0, 0.1});

    mVertices.push_back(Vertex{-0.1, -0.6, 0.09, 0.1, 0, 0.1});
    mVertices.push_back(Vertex{-0.1, -0.8, 0.09, 0.1, 0, 0.1});
    mVertices.push_back(Vertex{-0.09, -0.8, 0.09, 0.1, 0, 0.1});

    mVertices.push_back(Vertex{-0.09, -0.6, 0.09, 0.1, 0, 0.1});
    mVertices.push_back(Vertex{-0.09, -0.6, 0.1, 0.1, 0, 0.1});
    mVertices.push_back(Vertex{-0.09, -0.8, 0.09, 0.1, 0, 0.1});

    mVertices.push_back(Vertex{-0.09, -0.6, 0.1, 0.1, 0, 0.1});
    mVertices.push_back(Vertex{-0.09, -0.8, 0.1, 0.1, 0, 0.1});
    mVertices.push_back(Vertex{-0.09, -0.8, 0.09, 0.1, 0, 0.1});

    // Top right leg (+x/+z)
    mVertices.push_back(Vertex{0.1, -0.6, 0.1, 0.1, 0, 0.1});
    mVertices.push_back(Vertex{0.1, -0.6, 0.09, 0.1, 0, 0.1});
    mVertices.push_back(Vertex{0.1, -0.8, 0.1, 0.1, 0, 0.1});

    mVertices.push_back(Vertex{0.1, -0.6, 0.09, 0.1, 0, 0.1});
    mVertices.push_back(Vertex{0.1, -0.8, 0.09, 0.1, 0, 0.1});
    mVertices.push_back(Vertex{0.1, -0.8, 0.1, 0.1, 0, 0.1});

    mVertices.push_back(Vertex{0.1, -0.6, 0.1, 0.1, 0, 0.1});
    mVertices.push_back(Vertex{0.09, -0.6, 0.1, 0.1, 0, 0.1});
    mVertices.push_back(Vertex{0.1, -0.8, 0.1, 0.1, 0, 0.1});

    mVertices.push_back(Vertex{0.09, -0.6, 0.1, 0.1, 0, 0.1});
    mVertices.push_back(Vertex{0.09, -0.8, 0.1, 0.1, 0, 0.1});
    mVertices.push_back(Vertex{0.1, -0.8, 0.1, 0.1, 0, 0.1});

    mVertices.push_back(Vertex{0.09, -0.6, 0.09, 0.1, 0, 0.1});
    mVertices.push_back(Vertex{0.1, -0.6, 0.09, 0.1, 0, 0.1});
    mVertices.push_back(Vertex{0.09, -0.8, 0.09, 0.1, 0, 0.1});

    mVertices.push_back(Vertex{0.1, -0.6, 0.09, 0.1, 0, 0.1});
    mVertices.push_back(Vertex{0.1, -0.8, 0.09, 0.1, 0, 0.1});
    mVertices.push_back(Vertex{0.09, -0.8, 0.09, 0.1, 0, 0.1});

    mVertices.push_back(Vertex{0.09, -0.6, 0.09, 0.1, 0, 0.1});
    mVertices.push_back(Vertex{0.09, -0.6, 0.1, 0.1, 0, 0.1});
    mVertices.push_back(Vertex{0.09, -0.8, 0.09, 0.1, 0, 0.1});

    mVertices.push_back(Vertex{0.09, -0.6, 0.1, 0.1, 0, 0.1});
    mVertices.push_back(Vertex{0.09, -0.8, 0.1, 0.1, 0, 0.1});
    mVertices.push_back(Vertex{0.09, -0.8, 0.09, 0.1, 0, 0.1});
}

void Scenetwo::openDoor()
{
    if(doorOpen == false)
    {
        dmOne.matrix[0][1] = -0.4;
        dmOne.matrix[0][1] = -0.8;
        dmOne.matrix[0][1] = -0.8;
        dmTwo.matrix[0][1] = -0.4;
        dmTwo.matrix[0][1] = -0.4;
        dmTwo.matrix[0][1] = -0.8;
        doorOpen = true;
    }
    else if(doorOpen == true)
    {
        dmOne.matrix[0][1] = 0;
        dmOne.matrix[0][1] = -0.4;
        dmOne.matrix[0][1] = -0.4;
        dmTwo.matrix[0][1] = 0;
        dmTwo.matrix[0][1] = 0;
        dmTwo.matrix[0][1] = -0.4;
        doorOpen = false;
    }
}

void Scenetwo::drawDoor()
{
    mVertices.push_back(Vertex{dmOne.matrix[0][0], dmOne.matrix[0][1], dmOne.matrix[0][2], 0.1, 0, 0.1});
    mVertices.push_back(Vertex{dmOne.matrix[1][0], dmOne.matrix[1][1], dmOne.matrix[1][2], 0.1, 0, 0.1});
    mVertices.push_back(Vertex{dmOne.matrix[2][0], dmOne.matrix[2][1], dmOne.matrix[2][2], 0.1, 0, 0.1});

    mVertices.push_back(Vertex{dmTwo.matrix[0][0], dmTwo.matrix[0][1], dmTwo.matrix[0][2], 0.1, 0, 0.1});
    mVertices.push_back(Vertex{dmTwo.matrix[1][0], dmTwo.matrix[1][1], dmTwo.matrix[1][2], 0.1, 0, 0.1});
    mVertices.push_back(Vertex{dmTwo.matrix[2][0], dmTwo.matrix[2][1], dmTwo.matrix[2][2], 0.1, 0, 0.1});
}

/*
void Scenetwo::isDoorOpen(unsigned char key)
{
    switch(key)
    {
    case 'e':
    case 'E':
        doorOpen = true;
        break;

    }
}

void Scenetwo::drawDoor()
{
    if (doorOpen == false)
    {
        xPos1 = -0.1;
        xPos2 = 0.1;

        zPos1 = -0.8;
        zPos2 = -0.8;
    }
    else if (doorOpen == true)
    {
        xPos1 = -0.1;
        xPos2 = -0.1;

        zPos1 = -0.6;
        zPos2 = -0.8;
    }

    mVertices.push_back(Vertex{xPos1, -0.4, zPos1, 0.1, 0, 0.1});
    mVertices.push_back(Vertex{xPos1, -0.8, zPos1, 0.1, 0, 0.1});
    mVertices.push_back(Vertex{xPos2, -0.8, zPos2, 0.1, 0, 0.1});

    mVertices.push_back(Vertex{xPos2, -0.4, zPos2, 0.1, 0, 0.1});
    mVertices.push_back(Vertex{xPos1, -0.4, zPos1, 0.1, 0, 0.1});
    mVertices.push_back(Vertex{xPos2, -0.8, zPos2, 0.1, 0, 0.1});
}*/

void Scenetwo::init(GLint matrixUniform)
{
    mMatrixUniform = matrixUniform;

    initializeOpenGLFunctions();

    //Vertex Array Object - VAO
    glGenVertexArrays(1, &mVAO);
    glBindVertexArray(mVAO);

    //Vertex Buffer Object to hold vertices - VBO
    glGenBuffers(1, &mVBO);
    glBindBuffer(GL_ARRAY_BUFFER, mVBO);

    glBufferData(GL_ARRAY_BUFFER, mVertices.size() * sizeof(Vertex), mVertices.data(), GL_STATIC_DRAW);

    // 1rst attribute buffer : vertices
    glBindBuffer(GL_ARRAY_BUFFER, mVBO);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid *)0);
    glEnableVertexAttribArray(0);

    // 2nd attribute buffer : colors
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid *)(3 * sizeof(GLfloat)));
    glEnableVertexAttribArray(1);

    //enable the matrixUniform
    // mMatrixUniform = glGetUniformLocation( matrixUniform, "matrix" );

    glBindVertexArray(0);
}

void Scenetwo::draw()
{
    glBindVertexArray(mVAO);
    glUniformMatrix4fv(mMatrixUniform, 1, GL_FALSE, mMatrix.constData());
    glDrawArrays(GL_TRIANGLES, 0, mVertices.size());
}

} // end namespace.
