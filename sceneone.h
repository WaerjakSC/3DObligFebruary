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
    TriangleArray getSceneTriangles() const;
    std::vector<GameObject *> objects;

private:
    TriangleArray sceneTriangles;
    TriangleArray drawPlane();
    TriangleArray drawRightWall();
    TriangleArray drawLeftWall();
    TriangleArray drawBackWall();
    TriangleArray drawFrontWall();
    GameObject *plane, *rWall, *lWall, *bWall, *fWall;
};
#endif // SCENEONE_H
