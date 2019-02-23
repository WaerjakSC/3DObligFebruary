#ifndef SCENETWO_H
#define SCENETWO_H

#include "visualobject.h"
#include "housestuff.h"

class Scenetwo : public VisualObject
{
public:
    Scenetwo();
    void drawFloor();
    void drawHouse();
    void drawDoor();
    void isDoorOpen(unsigned char key);

    void init(GLint matrixUniform) override;
    void draw() override;

private:
   bool doorOpen = false;
   float xPos1 = 0;
   float xPos2 = 0;
   float zPos1 = 0;
   float zPos2 = 0;
   char key;

};

#endif // SCENETWO_H
