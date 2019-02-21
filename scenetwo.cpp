#include "scenetwo.h"

Scenetwo::Scenetwo()
{
    // Ground
    mVertices.push_back(Vertex{-1, -0.8, 1, 0, 0.3, 0.5});
    mVertices.push_back(Vertex{-1, -0.8, -1, 0, 0.3, 0.5});
    mVertices.push_back(Vertex{1, -0.8, -1, 0, 0.3, 0.5});

    mVertices.push_back(Vertex{-1, -0.8, 1, 0, 0.3, 0.5});
    mVertices.push_back(Vertex{1, -0.8, 1, 0, 0.3, 0.5});
    mVertices.push_back(Vertex{1, -0.8, -1, 0, 0.3, 0.5});

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

    // Door
    mVertices.push_back(Vertex{-0.1, -0.4, -0.8, 0.1, 0, 0.1});
    mVertices.push_back(Vertex{-0.1, -0.8, -0.8, 0.1, 0, 0.1});
    mVertices.push_back(Vertex{0.1, -0.8, -0.8, 0.1, 0, 0.1});

    mVertices.push_back(Vertex{0.1, -0.4, -0.8, 0.1, 0, 0.1});
    mVertices.push_back(Vertex{-0.1, -0.4, -0.8, 0.1, 0, 0.1});
    mVertices.push_back(Vertex{0.1, -0.8, -0.8, 0.1, 0, 0.1});

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