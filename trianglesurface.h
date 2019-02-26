#ifndef TRIANGLESURFACE_H
#define TRIANGLESURFACE_H
#include "vector3d.h"
#include "visualobject.h"

typedef jl::Vector3D Vec3;
class TriangleArray
{
public:
    TriangleArray();
    // Using tuple to prevent more than 3 vertices in case of a mistake
    TriangleArray(std::tuple<Vertex, Vertex, Vertex> vertices);
    TriangleArray(std::vector<std::tuple<Vertex, Vertex, Vertex>> vertices);
    ~TriangleArray();
    void init(GLint shader);
    void draw();
    void push_back(std::tuple<Vertex, Vertex, Vertex> vertices);

    std::tuple<Vec3, Vec3, Vec3> vertexToVec3(std::tuple<Vertex, Vertex, Vertex> vertices);
    Vec3 getPoint1();
    Vec3 getPoint2();
    Vec3 getPoint3();

    unsigned int size();
    std::vector<Vertex> getVertices();

    std::vector<Vec3> at(unsigned int index);
    float at(unsigned int index) const;

    std::vector<std::tuple<Vec3, Vec3, Vec3>> getTriangles() const;

private:
    std::vector<std::tuple<Vec3, Vec3, Vec3>> TriPoints;
    std::vector<Vertex> mVertices;
};

#endif // TRIANGLESURFACE_H
