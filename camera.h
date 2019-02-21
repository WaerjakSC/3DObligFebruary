#ifndef CAMERA_H
#define CAMERA_H
#include "matrix4x4.h"
#include "octahedronball.h"
#include "vector3d.h"
#include "visualobject.h"
#include <QElapsedTimer>
#include <QObject>
#include <QOpenGLFunctions_4_1_Core>

class Shader;

namespace jl
{

class Camera : public QObject, public QOpenGLFunctions_4_1_Core
{
    Q_OBJECT
public:
    //    Camera(Vector3d position, Vector3d up, float yaw, float pitch);
    Camera(const Vector3d &position = Vector3d(0.f, 0.f, -4.f), float pitch = 0.f, float yaw = 0.f);
    Matrix4x4 *GetVMatrix() { return &mVMatrix; }
    Matrix4x4 *GetPMatrix() { return &mPMatrix; }
    void setPersp(float fov, float aspectRatio, float zMin, float zMax);

    void PrintProj();
    void PrintView();
    void lookAt();

    void init(GLint vMatrixUniform, GLint pMatrixUniform, Shader *shader);
    void render();

    Vector3d getViewTarget() const;
    Matrix4x4 getViewRotation() const;
    Matrix4x4 getLookMatrix() const;

    void setPosition(float pos, int index);
    void setTarget(float target, int index);
    void setUp(float up, int index);

    Vector3d getPosition() const;

    Vector3d getTarget() const;

    Vector3d getUp() const;

signals:
    void lookAtChanged();

private:
    Matrix4x4 mVMatrix;
    Matrix4x4 mPMatrix;
    OctahedronBall *ball;
    Vector3d mPosition, mUp = Vector3d(0, 1, 0), mTarget = Vector3d(0, 0, 0);
    GLint mVMatrixUniform{0}, mPMatrixUniform{0};
    std::vector<VisualObject *> *mRenderQueue;
    Shader *mShaderProgram;
    float FOV;
    float mPitch, mYaw;
    QElapsedTimer mTimer; //timer that drives the gameloop
};
} // namespace jl
#endif // CAMERA_H
