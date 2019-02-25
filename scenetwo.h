#ifndef SCENETWO_H
#define SCENETWO_H
#include "visualobject.h"
#include "door.h"
#include "matrix4x4.h"

namespace jl
{

class Scenetwo : public VisualObject
{
private:
    float xPos1 = 0;
    float xPos2 = 0;
    float zPos1 = 0;
    float zPos2 = 0;
    char key;


public:
    Scenetwo();
    void drawFloor();
    void drawHouse();
    void drawTable();
    //void isDoorOpen(unsigned char key);
    //void rotateDoor();
    void drawDoor();

    void init(GLint matrixUniform) override;
    void draw() override;
    door Door;
};

} // namespace jl
#endif // SCENETWO_H
