#include "camera.h"
#include "shader.h"
#include <QTimer>
#include <QtMath>

namespace jl
{

Camera::Camera(const Vector3d &position, float pitch, float yaw) : mPosition{position}, mPitch{pitch}, mYaw{yaw}
{

    mVMatrix.translate(mPosition);
    mTimer.start();
}


Vector3d Camera::getViewTarget() const
{
    const float PI = 3.1415927;
    float radians = (PI / 180); // From degrees to radians for sine/cosine
    float radPitch = mPitch * radians;
    float radYaw = mYaw * radians;

    return Vector3d{
        cosf(radPitch) * cosf(radYaw),
        sinf(radPitch),
        cosf(radPitch) * sinf(radYaw)};
}
Matrix4x4 Camera::getViewRotation() const
{
    return Matrix4x4::sLookAt(Vector3d(), getViewTarget()).transpose() * Matrix4x4::translation(mPosition);
}

Matrix4x4 Camera::getViewMatrix() const
{
    return mVMatrix;
}

void Camera::setPosition(float pos, int index)
{
    mPosition.at(index) = pos;
}

void Camera::setTarget(float target, int index)
{
    mTarget.at(index) = target;
}

void Camera::setUp(float up, int index)
{
    mUp.at(index) = up;
}

Vector3d Camera::getPosition() const
{
    return mPosition;
}

Vector3d Camera::getTarget() const
{
    return mTarget;
}

Vector3d Camera::getUp() const
{
    return mUp;
}

Vector3d Camera::getRight() const{
    return mRight;
}

void Camera::setPersp(float fov, float aspectRatio, float zMin, float zMax)
{
    FOV = fov;
    mPMatrix = Matrix4x4{1.f}.perspective(FOV, aspectRatio, zMin, zMax);
}

void Camera::Init(GLint vMatrixUniform, GLint pMatrixUniform, Shader *shader)
{

    mVMatrixUniform = vMatrixUniform;
    mPMatrixUniform = pMatrixUniform;
    mShaderProgram = shader;
    //    mVMatrix.translate(0, 0, 2);

    initializeOpenGLFunctions();
}

void Camera::Render()
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



// Camera movement with WASD
// direction times magnitude
void Camera::addForward(float speed){
  mPosition = mPosition -  (mFront * speed);

}

void Camera::strafe(float speed){
    Vector3d strafeDirection = mFront^mUp;
    //strafeDirection.normalize();
    mPosition = mPosition + (strafeDirection*speed);


}

} // namespace jl
