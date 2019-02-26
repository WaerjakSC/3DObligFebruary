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
    void openDoor();

private:
    TriangleArray sceneTriangles;
    TriangleArray drawPlane();
    TriangleArray drawRightWall();
    TriangleArray drawLeftWall();
    TriangleArray drawBackWall();
    TriangleArray drawFrontWall();
    TriangleArray drawDoor();

    GameObject *plane, *rWall, *lWall, *bWall, *fWall, *door;
    bool doorOpen = false;
};
#endif // SCENEONE_H
