#include "gameobject.h"

GameObject::GameObject()
{ // Plane
    mVertices.push_back(Vertex{-0.8, 0, 0.8, 0.5, 1, 1});
    mVertices.push_back(Vertex{-0.8, 0, -0.8, 0.5, 1, 1});
    mVertices.push_back(Vertex{0.8, 0, -0.8, 0.5, 1, 1});

    mVertices.push_back(Vertex{-0.8, 0, 0.8, 0.5, 1, 1});
    mVertices.push_back(Vertex{0.8, 0, 0.8, 0.5, 1, 1});
    mVertices.push_back(Vertex{0.8, 0, -0.8, 0.5, 1, 1});

    // Left Wall
    mVertices.push_back(Vertex{-0.8, 0, 0.8, 1, 0, 1});
    mVertices.push_back(Vertex{-0.8, 0.4, 0.8, 1, 1, 0});
    mVertices.push_back(Vertex{-0.8, 0, -0.8, 0, 1, 1});

    mVertices.push_back(Vertex{-0.8, 0.4, 0.8, 1, 0, 1});
    mVertices.push_back(Vertex{-0.8, 0.4, -0.8, 1, 1, 0});
    mVertices.push_back(Vertex{-0.8, 0, -0.8, 0, 1, 1});

    // Right Wall
    mVertices.push_back(Vertex{0.8, 0, 0.8, 1, 1, 0});
    mVertices.push_back(Vertex{0.8, 0.4, 0.8, 1, 0, 1});
    mVertices.push_back(Vertex{0.8, 0, -0.8, 0, 1, 1});

    mVertices.push_back(Vertex{0.8, 0.4, 0.8, 1, 1, 0});
    mVertices.push_back(Vertex{0.8, 0.4, -0.8, 1, 0, 1});
    mVertices.push_back(Vertex{0.8, 0, -0.8, 0, 1, 1});

    // Back Wall
    mVertices.push_back(Vertex{0.8, 0, 0.8, 0, 0, 1});
    mVertices.push_back(Vertex{0.8, 0.4, 0.8, 0, 0, 1});
    mVertices.push_back(Vertex{-0.8, 0, 0.8, 0, 0, 1});

    mVertices.push_back(Vertex{0.8, 0.4, 0.8, 0, 0, 1});
    mVertices.push_back(Vertex{-0.8, 0.4, 0.8, 0, 0, 1});
    mVertices.push_back(Vertex{-0.8, 0, 0.8, 0, 0, 1});

    // Front Wall
    mVertices.push_back(Vertex{-0.8, 0, 0.8, 1, 0, 0});
    mVertices.push_back(Vertex{-0.8, 0.4, 0.8, 1, 0, 0});
    mVertices.push_back(Vertex{-0.8, 0, -0.8, 1, 0, 0});

    mVertices.push_back(Vertex{-0.8, 0.4, 0.8, 1, 0, 0});
    mVertices.push_back(Vertex{-0.8, 0.4, -0.8, 1, 0, 0});
    mVertices.push_back(Vertex{-0.8, 0, -0.8, 1, 0, 0});
}

bool GameObject::CheckCollisions(const GameObject &first, const GameObject &second)
{
    Vec3 center(first.position() + first.radius());
    Vec3 otherCenter(second.position() + second.radius());
    Vec3 distance = center - otherCenter;

    return distance.length() < radius();
}

void GameObject::init(GLint matrixUniform)
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

    glBindBuffer(GL_ARRAY_BUFFER, mVBO);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid *)0);
    glEnableVertexAttribArray(0);

    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid *)(3 * sizeof(GLfloat)));
    glEnableVertexAttribArray(1);

    glBindVertexArray(0);
}
void GameObject::draw()
{
    glBindVertexArray(mVAO);
    UpdateTRS(); // Called every frame but could probably be called only when explicitly moved if not a character/pawn
    glUniformMatrix4fv(mMatrixUniform, 1, GL_FALSE, mMatrix.constData());
    glDrawArrays(GL_TRIANGLES, 0, mVertices.size());
}

Vec3 GameObject::position() const
{
    return mPosition;
}

Vec3 GameObject::scale() const
{
    return mScale;
}

float GameObject::radius() const
{
    return mRadius;
}
/**
 * @brief GameObject::UpdateTRS
 * Finds and updates the position, scale and rotation of the object.
 * Vectors updated are mPosition, mScale and mRotation.
 * mRotation is initially in radians,
 * must be converted with GetEulerRotation() if you want degrees instead.
 */
void GameObject::UpdateTRS()
{
    // Initialize transformation matrix
    Matrix4x4 trans = mMatrix;

    // Position
    for (int i = 0; i < 3; i++)
    {
        mPosition.at(i) = trans.at(3, i);
        trans.at(3, i) = 0.f; // Zero out the fourth column in preparation for rotation matrix
    }

    // Scale
    Vec3 scaleX, scaleY, scaleZ;
    for (int i = 0; i < 3; i++)
    {
        // Set up the first three columns of the transformation matrix into vectors
        scaleX.at(i) = trans.at(0, i);
        scaleY.at(i) = trans.at(1, i);
        scaleZ.at(i) = trans.at(2, i);
    }
    // The absolute scale of the object is calculated by the length of each column vector.
    mScale.setX(scaleX.length());
    mScale.setY(scaleY.length());
    mScale.setZ(scaleZ.length());

    // Rotation
    for (int i = 0; i < 3; i++)
    {

        for (int j = 0; j < 3; j++)
        {
            // To get the rotation matrix, divide each column by the scale at x, y or z
            trans.at(i, j) = trans.at(i, j) / mScale.at(i);
        }
    }
    mRotation.setX(std::atan2(trans.at(1, 2), trans.at(2, 2)));
    mRotation.setY(std::atan2(-trans.at(0, 2),
                              std::sqrt(
                                  std::pow(trans.at(1, 2), 2) +
                                  std::pow(trans.at(2, 2), 2))));
    mRotation.setZ(std::atan2(trans.at(0, 1), trans.at(0, 0)));
}
/**
 * @brief GameObject::GetEulerRotation converts the mRotation vector from radians to degrees.
 * @return euler angles
 */
Vec3 GameObject::GetEulerRotation() const
{
    Vec3 euler;
    const float PI = 3.1415927;

    for (int i = 0; i < 3; i++)
    {
        // From radians to degrees
        float rad = mRotation.at(i) * (180 / PI);
        euler.at(i) = rad;
    }
    return euler;
}
