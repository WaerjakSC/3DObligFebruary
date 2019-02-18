#include "cube.h"
#include "shader.h"
#include "vector3d.h"
#include "vertex.h"
#include <QImage>
#include <QOpenGLTexture>

unsigned int Cube::makeId()
{
    static unsigned int SId{0};
    return ++SId;
}

Cube::Cube()
{
    mVertices.push_back(Vertex{-0.5f, -0.5f, 0.5f, 1.f, 0.f, 0.f});
    mVertices.push_back(Vertex{0.5f, -0.5f, 0.5f, 0.f, 1.f, 0.f});
    mVertices.push_back(Vertex{0.5f, 0.5f, 0.5f, 0.f, 0.f, 1.f});
    mVertices.push_back(Vertex{-0.5f, 0.5f, 0.5f, 1.f, 1.f, 0.f});

    mVertices.push_back(Vertex{0.5f, -0.5f, 0.5f, 1.f, 0.f, 0.f});
    mVertices.push_back(Vertex{0.5f, -0.5f, -0.5f, 0.f, 1.f, 0.f});
    mVertices.push_back(Vertex{0.5f, 0.5f, -0.5f, 0.f, 0.f, 1.f});
    mVertices.push_back(Vertex{0.5f, 0.5f, 0.5f, 1.f, 1.f, 0.f});

    mVertices.push_back(Vertex{0.5f, -0.5f, -0.5f, 0.f, 1.f, 0.f});
    mVertices.push_back(Vertex{-0.5f, -0.5f, -0.5f, 1.f, 0.f, 0.f});
    mVertices.push_back(Vertex{-0.5f, 0.5f, -0.5f, 1.f, 1.f, 0.f});
    mVertices.push_back(Vertex{0.5f, 0.5f, -0.5f, 0.f, 0.f, 1.f});

    mVertices.push_back(Vertex{-0.5f, -0.5f, -0.5f, 0.f, 1.f, 0.f});
    mVertices.push_back(Vertex{-0.5f, -0.5f, 0.5f, 1.f, 0.f, 0.f});
    mVertices.push_back(Vertex{-0.5f, 0.5f, 0.5f, 1.f, 1.f, 0.f});
    mVertices.push_back(Vertex{-0.5f, 0.5f, -0.5f, 0.f, 0.f, 1.f});

    mVertices.push_back(Vertex{-0.5f, 0.5f, 0.5f, 1.f, 0.f, 0.f});
    mVertices.push_back(Vertex{0.5f, 0.5f, 0.5f, 0.f, 1.f, 0.f});
    mVertices.push_back(Vertex{0.5f, 0.5f, -0.5f, 0.f, 0.f, 1.f});
    mVertices.push_back(Vertex{-0.5f, 0.5f, -0.5f, 1.f, 1.f, 0.f});

    mVertices.push_back(Vertex{0.5f, -0.5f, 0.5f, 0.f, 1.f, 0.f});
    mVertices.push_back(Vertex{-0.5f, -0.5f, 0.5f, 1.f, 0.f, 0.f});
    mVertices.push_back(Vertex{-0.5f, -0.5f, -0.5f, 1.f, 1.f, 0.f});
    mVertices.push_back(Vertex{0.5f, -0.5f, -0.5f, 0.f, 0.f, 1.f});

    mTriangles.push_back({0, 1, 2});
    mTriangles.push_back({2, 3, 0});

    mTriangles.push_back({4, 5, 6});
    mTriangles.push_back({6, 7, 4});

    mTriangles.push_back({8, 9, 10});
    mTriangles.push_back({10, 11, 8});

    mTriangles.push_back({12, 13, 14});
    mTriangles.push_back({14, 15, 12});

    mTriangles.push_back({16, 17, 18});
    mTriangles.push_back({18, 19, 16});

    mTriangles.push_back({20, 21, 22});
    mTriangles.push_back({22, 23, 20});
}

Cube::~Cube()
{
    glDeleteBuffers(1, &mVAO);
    glDeleteBuffers(1, &mVBO);
    glDeleteBuffers(1, &mEBO);
}

void Cube::init(GLint matrixUniform)
{
    mMatrixUniform = matrixUniform;

    initializeOpenGLFunctions();

    //Vertex Array Object - VAO
    glGenVertexArrays(1, &mVAO);
    glBindVertexArray(mVAO);

    //Vertex Buffer Object to hold vertices - VBO
    glGenBuffers(1, &mVBO);
    glBindBuffer(GL_ARRAY_BUFFER, mVBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(Vertex) * mVertices.size(), mVertices.data(), GL_STATIC_DRAW);

    // Element Buffer Object to hold indices - EBO
    glGenBuffers(1, &mEBO);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, mEBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(triangle) * mTriangles.size(), mTriangles.data(), GL_STATIC_DRAW);

    // 1rst attribute buffer : vertices
    glBindBuffer(GL_ARRAY_BUFFER, mVBO);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid *)0);
    glEnableVertexAttribArray(0);

    // 2nd attribute buffer : colors
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_TRUE, sizeof(Vertex), (GLvoid *)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);

    // 3rd attribute buffer : uv
    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid *)(6 * sizeof(float)));
    glEnableVertexAttribArray(2);

    //enable the matrixUniform
    // mMatrixUniform = glGetUniformLocation( matrixUniform, "matrix" );

    glBindVertexArray(0);
}

void Cube::draw()
{
    glBindVertexArray(mVAO);
    glUniformMatrix4fv(mMatrixUniform, 1, GL_FALSE, mMatrix.constData());
    glDrawElements(GL_TRIANGLES, 3 * mTriangles.size(), GL_UNSIGNED_INT, 0);
}
