#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H
#include "trianglesurface.h"
#include "vector3d.h"
#include "visualobject.h"
#include <QObject>

using namespace jl;
typedef Vector3D Vec3;

class GameObject : public QObject, public VisualObject
{
    Q_OBJECT
public:
    GameObject(TriangleArray triangles, QString actorName,
               Vec3 position = Vec3(0, 0, 0),
               Vec3 scale = Vec3(1, 1, 1),
               Vec3 rotateAxis = Vec3(0, 0, 0), float angles = 0);
    Vec3 GetForwardVector();
    Vec3 GetEulerRotation() const;
    virtual void init(GLint matrixUniform);
    virtual void draw();

    Vec3 position() const;

    Vec3 scale() const;

    Vec3 rotation() const;

    void setIsMovable(bool value);

    Matrix4x4 getModelMatrix();

    // Might need some rotate/translate/scale functions since mMatrix is protected

    void move(Vec3 distanceToMove);
    void rotate(Vec3 axis, float angle);
    void scale(Vec3 newScale);
    void resetPosition();
    void resetScale();
    void resetRotation();
    void reset();

    TriangleArray getTriangles() const;

    Vec3 getTriangle(int triangle, int point);

    QString getName() const;
    void setPosition(Vec3 newPos);
signals:
    void updatedTransforms();

private:
    Vec3 mPosition, mScale, mRotation;
    TriangleArray objectTriangles;
    bool IsMovable;
    QString name = "no name";

    void UpdateTRS();
};

#endif // GAMEOBJECT_H
