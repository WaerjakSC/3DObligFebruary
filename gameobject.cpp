#include "gameobject.h"

GameObject::GameObject(TriangleArray triangles, std::string actorName, Vec3 position, Vec3 scale, Vec3 rotateAxis,
                       float angles)
    : VisualObject(), mPosition(position), mScale(scale), name(actorName)
{
    objectTriangles = triangles;

    // Get all the vertices in the triangle array
    mVertices = objectTriangles.getVertices();

    // Perform initial transformations
    this->scale(scale);
    rotate(rotateAxis, angles);
    move(position);

    // Save all the triangles of the object
    // ObjectTriangles contains (vertices.size() / 3) amount of std::vectors
    // of type Vector3D.
    // Each Vector3D constitutes the three points of a single triangle.
    //    if (vertices.size() % 3 == 0)
    //    {
    //        // vertices should always be divisible by 3 since it's a collection of triangles.
    //        for (unsigned int i = 0; i < vertices.size() / 3; i++)
    //        {
    //            for (unsigned int j = 0; j < 3; j++)
    //            {
    //                // Temporarily transform into Vector4D for multiplication with model matrix
    //                Vector4D tempVec = Vector3D(mVertices.at(j + i * 3).at(0),
    //                                            mVertices.at(j + i * 3).at(1),
    //                                            mVertices.at(j + i * 3).at(2));
    //                // (Hopefully) convert the vector into scene space
    //                tempVec = mMatrix * tempVec;
    //                objectTriangles.push_back(Vector3D(tempVec));
    //            }
    //        }
    //    }
    //    else
    //        qDebug() << "Something went wrong, "
    //                    "the object doesn't have the required amount of vertices!";
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
    if (IsMovable) // No need to call this function if the object won't ever be moved
    {
        UpdateTRS(); // Called every frame but could probably be called only when explicitly moved if not a character/pawn
    }
    glBindVertexArray(mVAO);
    glUniformMatrix4fv(mMatrixUniform, 1, GL_FALSE, mMatrix.constData());
    glDrawArrays(GL_TRIANGLES, 0, mVertices.size());
}
void GameObject::move(Vec3 distanceToMove)
{
    mMatrix.translate(distanceToMove);
    // Update the object's variables with the new values.
    UpdateTRS();
}
void GameObject::rotate(Vec3 axis, float angle)
{
    mMatrix.rotate(axis, angle);
    // Update the object's variables with the new values.
    UpdateTRS();
}

void GameObject::scale(Vec3 newScale)
{
    mMatrix.scale(newScale);
    // Update the object's variables with the new values.
    UpdateTRS();
}

void GameObject::resetPosition()
{
    // This really doesn't work but whatever :)))
    if (position().length() > 0.1)
        mMatrix.translate(-position().getX(), -position().getY(), -position().getZ());
}

TriangleArray GameObject::getTriangles() const
{
    return objectTriangles;
}

Vec3 GameObject::position() const
{
    return mPosition;
}

Vec3 GameObject::scale() const
{
    return mScale;
}

void GameObject::setIsMovable(bool value)
{
    IsMovable = value;
}

Matrix4x4 GameObject::getModelMatrix()
{
    return mMatrix;
}
/**
 * @brief GameObject::getTriangle
 * @param triangle
 * @param point
 * @return Returns the desired triangle multiplied into the model matrix
 */

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
// SetEulerRotation()?
