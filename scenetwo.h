#ifndef SCENETWO_H
#define SCENETWO_H

#include "gameobject.h"

class Scenetwo
{
private:
    //    float xPos1{0};
    //    float xPos2{0};
    //    float zPos1{0};
    //    float zPos2{0};
    bool doorOpen{false};
    //    char key;
    GameObject *floor, *house, *table, *door;

public:
    Scenetwo();
    std::vector<Vertex> drawFloor();
    std::vector<Vertex> drawHouse();
    std::vector<Vertex> drawTable();
    std::vector<Vertex> drawDoor();

    void init(GLint matrixUniform);
    void draw();
    void openDoor();
};

#endif // SCENETWO_H
