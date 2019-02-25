#include "door.h"
#include <QOpenGLFunctions_4_1_Core>
#include <QMatrix4x4>
#include <QTimer>
#include <QOpenGLContext>
#include <QOpenGLFunctions>
#include <QOpenGLDebugLogger>
#include <QKeyEvent>
#include <QStatusBar>

#include "matrix4x4.h"
#include "vector3d.h"

namespace jl
{

door::door()
{
    mVertices.push_back(Vertex{-0.1, -0.4, -0.8, 0.1, 0, 0.1});
    mVertices.push_back(Vertex{-0.1, -0.8, -0.8, 0.1, 0, 0.1});
    mVertices.push_back(Vertex{0.1, -0.8, -0.8, 0.1, 0, 0.1});

    mVertices.push_back(Vertex{0.1,-0.4, -0.8, 0.1, 0, 0.1});
    mVertices.push_back(Vertex{-0.1, -0.4, -0.8, 0.1, 0, 0.1});
    mVertices.push_back(Vertex{0.1, -0.8, -0.8, 0.1, 0, 0.1});
}

door::~door()
{
    glDeleteVertexArrays( 1, &mVAO );
    glDeleteBuffers( 1, &mVBO );
}

void door::openDoor()
{
    if(doorOpen == false)
    {
        mMatrix.translate(QVector3D(0,0.4,0));
        doorOpen = !doorOpen;
    }
    else if(doorOpen == true)
    {
        mMatrix.translate(QVector3D(0,-0.4,0));
        doorOpen = !doorOpen;
    }
}

void door::init(GLint shader)
{
    initializeOpenGLFunctions();

    //Start Default triangle
    mMatrixUniform = shader;

    //Vertex Array Object - VAO
    glGenVertexArrays( 1, &mVAO );
    glBindVertexArray( mVAO );

    //Vertex Buffer Object to hold vertices - VBO
    glGenBuffers( 1, &mVBO );
    glBindBuffer( GL_ARRAY_BUFFER, mVBO );

    glBufferData( GL_ARRAY_BUFFER, mVertices.size()*sizeof(Vertex), mVertices.data(), GL_STATIC_DRAW );

    // 1st attribute buffer : vertices
    glBindBuffer(GL_ARRAY_BUFFER, mVBO);
    glVertexAttribPointer(0, 3, GL_FLOAT,GL_FALSE, sizeof(Vertex), (GLvoid*)0);
    glEnableVertexAttribArray(0);

    // 2nd attribute buffer : colors
    glVertexAttribPointer(1, 3, GL_FLOAT,GL_FALSE, sizeof(Vertex), (GLvoid*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);

    // 3rd attribute buffer : uv
    glVertexAttribPointer(2, 2, GL_FLOAT,GL_TRUE, sizeof(Vertex), (GLvoid*)(6 * sizeof(float)));
    glEnableVertexAttribArray(2);
}

void door::draw()
{
    glBindVertexArray( mVAO );
    glUniformMatrix4fv( mMatrixUniform, 1, GL_FALSE, mMatrix.constData());
    glDrawArrays(GL_TRIANGLES, 0, mVertices.size());
}

} // end namespace
