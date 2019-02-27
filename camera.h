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

class Camera : public QObject, public QOpenGLFunctions_4_1_Core
{
    Q_OBJECT
public:
    //    Camera(Vector3d position, Vector3d up, float yaw, float pitch);
    Camera(const Vector3D &position = Vector3D(0.f, 0.f, -4.f), float pitch = 0.f, float yaw = 0.f);
    Matrix4x4 *GetVMatrix() { return &mVMatrix; }
    Matrix4x4 *GetPMatrix() { return &mPMatrix; }
    void SetPersp(float fov, float aspectRatio, float zMin, float zMax);

    void PrintProj();
    void PrintView();
    void LookAt();

    void init(GLint vMatrixUniform, GLint pMatrixUniform, Shader *shader);
    void render();

    Vector3D getViewTarget() const;
    Matrix4x4 getViewRotation() const;
    Matrix4x4 getLookMatrix() const;

    void setPosition(float pos, int index);
    void setTarget(float target, int index);
    void setUp(float up, int index);

    void setPosition(Vec3 vec);
    void setTarget(Vec3 vec);
    void setUp(Vec3 vec);
    Vector3D getPosition() const;

    Vector3D getTarget() const;

    Vector3D getUp() const;

signals:
    void lookAtChanged();
    void posChanged(Vec3 value);
    void tarChanged(Vec3 value);
    void upChanged(Vec3 value);

private:
    Matrix4x4 mVMatrix;
    Matrix4x4 mPMatrix;
    OctahedronBall *ball;
    Vector3D mPosition, mUp = Vector3D(0, 1, 0), mTarget = Vector3D(0, 0, 0);
    GLint mVMatrixUniform{0}, mPMatrixUniform{0};
    std::vector<VisualObject *> *mRenderQueue;
    Shader *mShaderProgram;
    float FOV;
    float mPitch, mYaw;
    QElapsedTimer mTimer; //timer that drives the gameloop
};
#endif // CAMERA_H
