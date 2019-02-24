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
    std::vector<Vector3D> sceneTriangles;
    void init(GLint matrixUniform) override;
    void saveSceneTriangles();

private:
};
#endif // SCENEONE_H
