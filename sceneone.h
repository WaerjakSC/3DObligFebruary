#ifndef SCENEONE_H
#define SCENEONE_H

#include "gameobject.h"
#include "vector3d.h"
#include "visualobject.h"
#include <vector>

class Sceneone
{
public:
    Sceneone();
    ~Sceneone();
    void init(GLint matrixUniform);
    void draw();
    std::vector<Vector3D> getSceneTriangles() const;
    std::vector<GameObject *> objects;

private:
    std::vector<Vector3D> sceneTriangles;
    std::vector<Vertex> drawPlane();
    std::vector<Vertex> drawRightWall();
    std::vector<Vertex> drawLeftWall();
    std::vector<Vertex> drawBackWall();
    std::vector<Vertex> drawFrontWall();
    GameObject *plane, *rWall, *lWall, *bWall, *fWall;
};
#endif // SCENEONE_H
