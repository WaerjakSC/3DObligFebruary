#ifndef SCENETWO_H
#define SCENETWO_H
#include "visualobject.h"
#include "matrix4x4.h"

namespace jl
{

class Scenetwo : public VisualObject
{
private:
    bool doorOpen = false;
    float xPos1 = 0;
    float xPos2 = 0;
    float zPos1 = 0;
    float zPos2 = 0;
    char key;
    Matrix4x4 dmOne{-0.1,-0.4, -0.8, 0, -0.1, -0.8, -0.8, 0, 0.1, -0.8, -0.8, 0, 0, 0, 0, 1};
    Matrix4x4 dmTwo{0.1,-0.4, -0.8, 0, -0.1, -0.4, -0.8, 0, 0.1, -0.8, -0.8, 0, 0, 0, 0, 1};

public:
    Scenetwo();
    void drawFloor();
    void drawHouse();
    void drawTable();
    void openDoor();
    //void isDoorOpen(unsigned char key);
    //void rotateDoor();
    void drawDoor();

    void init(GLint matrixUniform) override;
    void draw() override;
};

} // namespace jl
#endif // SCENETWO_H
