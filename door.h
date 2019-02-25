#ifndef DOOR_H
#define DOOR_H
#include "visualobject.h"

namespace jl
{

class door: public VisualObject
{
public:
    door();
    ~door() override;
    void init(GLint shader) override;
    void draw() override;
    void openDoor();

    void setShouldMoveUp(bool Open);
    bool shouldMoveUp = false;

private:
    bool doorOpen = false;
};

} // end namespace

#endif // DOOR_H
