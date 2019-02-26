#ifndef SCENETWO_H
#define SCENETWO_H

#include "gameobject.h"

class Scenetwo
{
public:
    Scenetwo();
    ~Scenetwo();
    TriangleArray drawFloor();
    TriangleArray drawHouse();
    TriangleArray drawTable();
    TriangleArray drawDoor();
    std::vector<GameObject *> objects;
    TriangleArray getSceneTriangles() const;

    void init(GLint matrixUniform);
    void draw();
    void openDoor();

private:
    //    float xPos1{0};
    //    float xPos2{0};
    //    float zPos1{0};
    //    float zPos2{0};
    bool doorOpen{false};
    //    char key;
    GameObject *floor, *house, *table, *door;
    TriangleArray sceneTriangles;
};

#endif // SCENETWO_H
