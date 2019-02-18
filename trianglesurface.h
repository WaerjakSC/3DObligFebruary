#ifndef TRIANGLESURFACE_H
#define TRIANGLESURFACE_H
#include "vector3d.h"
#include "visualobject.h"

class TriangleSurface : public VisualObject
{
public:
    TriangleSurface();
    TriangleSurface(std::string filnavn);
    ~TriangleSurface() override;
    void init(GLint shader) override;
    void draw() override;
    void construct();
    void writeFile(std::string filename);
};

#endif // TRIANGLESURFACE_H
