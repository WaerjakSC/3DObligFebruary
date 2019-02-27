#include "camera.h"
#include "mainwindow.h"
#include "shader.h"
#include <QTimer>
#include <QtMath>

Camera::Camera(const Vector3D &position, float pitch, float yaw) : mPosition{position}, mPitch{pitch}, mYaw{yaw}
{
    mVMatrix.translate(mPosition); // Place the camera at the desired point in the scene.
    mTimer.start();
}
Vector3D Camera::getViewTarget() const
{
    const float PI = 3.1415927;
    float radians = (PI / 180); // From degrees to radians for sine/cosine
    float radPitch = mPitch * radians;
    float radYaw = mYaw * radians;

    return Vector3D{
        cosf(radPitch) * cosf(radYaw),
        sinf(radPitch),
        cosf(radPitch) * sinf(radYaw)};
}
Matrix4x4 Camera::getViewRotation() const
{
    return Matrix4x4::sLookAt(Vector3D(), getViewTarget()).transpose();
}

Matrix4x4 Camera::getLookMatrix() const
{
    return Matrix4x4::sLookAt(mPosition, mTarget, mUp).transpose();
}

void Camera::setPosition(float pos, int index)
{
    mPosition.at(index) = pos;
    emit lookAtChanged();
}

void Camera::setTarget(float target, int index)
{
    mTarget.at(index) = target;
    emit lookAtChanged();
}

void Camera::setUp(float up, int index)
{
    mUp.at(index) = up;
    emit lookAtChanged();
}
void Camera::setPosition(Vec3 vec)
{
    mPosition = vec;
    emit posChanged(vec);
}

void Camera::setTarget(Vec3 vec)
{
    mTarget = vec;
    emit tarChanged(vec);
}

void Camera::setUp(Vec3 vec)
{
    mUp = vec;
    emit upChanged(vec);
}
Vector3D Camera::getPosition() const
{
    return mPosition;
}

Vector3D Camera::getTarget() const
{
    return mTarget;
}

Vector3D Camera::getUp() const
{
    return mUp;
}
// Set mPMatrix to a 4x4 perspective matrix
void Camera::SetPersp(float fov, float aspectRatio, float zMin, float zMax)
{
    FOV = fov;
    mPMatrix = Matrix4x4{1.f}.perspective(FOV, aspectRatio, zMin, zMax);
}

void Camera::init(GLint vMatrixUniform, GLint pMatrixUniform, Shader *shader)
{
    mVMatrixUniform = vMatrixUniform;
    mPMatrixUniform = pMatrixUniform;
    mShaderProgram = shader;

    initializeOpenGLFunctions();
}

void Camera::render()
{
    //to clear the screen for each redraw
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    mVMatrix = Matrix4x4::sLookAt(mPosition, mTarget, mUp).transpose();

    glUseProgram(mShaderProgram->getProgram());
    // Receive and send player view matrix and projection matrix to the shader
    glUniformMatrix4fv(mPMatrixUniform, 1, GL_FALSE, mPMatrix.constData());
    glUniformMatrix4fv(mVMatrixUniform, 1, GL_FALSE, mVMatrix.constData());
}

void Camera::PrintProj()
{
    std::cout << mPMatrix;
}
void Camera::PrintView()
{
    std::cout << mVMatrix;
}
