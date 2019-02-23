#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H
#include "vector3d.h"
#include "visualobject.h"

using namespace jl;
typedef Vector3D Vec3;

class GameObject : public VisualObject
{
public:
    GameObject(Vec3 position = Vec3(0, 0, 0),
               Vec3 scale = Vec3(1, 1, 1),
               Vec3 rotateAxis = Vec3(0, 0, 0), float angles = 0,
               bool movable = false);
    Vec3 GetForwardVector();
    Vec3 GetEulerRotation() const;
    virtual void init(GLint matrixUniform);
    virtual void draw();

    Vec3 position() const;

    Vec3 scale() const;

    void setIsMovable(bool value);

private:
    Vec3 mPosition, mScale, mRotation;
    bool IsMovable;
    void UpdateTRS();
};

#endif // GAMEOBJECT_H
