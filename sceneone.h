#ifndef SCENEONE_H
#define SCENEONE_H

#include "gameobject.h"
#include "vector3d.h"
#include "visualobject.h"
#include <vector>

class Sceneone : public GameObject
{
public:
    Sceneone();
    void init(GLint matrixUniform) override;
    std::vector<Vector3D> getSceneTriangles() const;

private:
    std::vector<Vector3D> sceneTriangles;
};
#endif // SCENEONE_H
