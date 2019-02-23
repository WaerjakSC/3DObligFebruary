#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H
#include "vector3d.h"
#include "visualobject.h"

using namespace jl;
typedef Vector3D Vec3;

class GameObject : public VisualObject
{
public:
    GameObject();
    bool CheckCollisions(const GameObject &first, const GameObject &second);
    Vec3 GetForwardVector();
    Vec3 GetEulerRotation() const;
    void init(GLint matrixUniform);
    void draw();

    Vec3 position() const;

    Vec3 scale() const;

    float radius() const;

private:
    Vec3 mPosition, mScale, mRotation;
    float mRadius;
    void UpdateTRS();
};

#endif // GAMEOBJECT_H
