#ifndef CUBE_H
#define CUBE_H

#include "vector3d.h"
#include "visualobject.h"
class Cube : public VisualObject
{
public:
    Cube();
    Cube(std::string filnavn);
    ~Cube();
    void init(GLint shader);
    void draw();
    unsigned int makeId();

private:
    struct triangle
    {
        unsigned int arr[3];
        triangle(unsigned int a = 0,
                 unsigned int b = 0,
                 unsigned int c = 0)
            : arr{a, b, c} {}
    };
    std::vector<triangle> mTriangles;
    unsigned int mEBO;
};

#endif // CUBE_H
