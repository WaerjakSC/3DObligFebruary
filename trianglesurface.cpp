#include "trianglesurface.h"
#include "vector3d.h"
#include <fstream>
#include <tuple>
TriangleArray::TriangleArray()
{
}

TriangleArray::TriangleArray(std::tuple<Vertex, Vertex, Vertex> vertices)
{
    mVertices.push_back(std::get<0>(vertices));
    mVertices.push_back(std::get<1>(vertices));
    mVertices.push_back(std::get<2>(vertices));
}

TriangleArray::TriangleArray(std::vector<std::tuple<Vertex, Vertex, Vertex>> vertices)
{
    for (std::tuple<Vertex, Vertex, Vertex> vert : vertices)
    {
        mVertices.push_back(std::get<0>(vert));
        mVertices.push_back(std::get<1>(vert));
        mVertices.push_back(std::get<2>(vert));
    }
}

TriangleArray::~TriangleArray()
{
}
/**
 * @brief TriangleArray::push_back Add another triangle to the array
 * @param vertices
 */
void TriangleArray::push_back(std::tuple<Vertex, Vertex, Vertex> vertices)
{
    TriPoints.push_back(vertexToVec3(vertices));
    mVertices.push_back(std::get<0>(vertices));
    mVertices.push_back(std::get<1>(vertices));
    mVertices.push_back(std::get<2>(vertices));
}
/**
 * @brief TriangleArray::vertexToVec3 Only saves the first three coordinates in the vertex
 * @param vertices
 * @return
 */
std::tuple<Vec3, Vec3, Vec3> TriangleArray::vertexToVec3(std::tuple<Vertex, Vertex, Vertex> vertices)
{
    Vec3 point1 = Vec3(std::get<0>(vertices).at(0),
                       std::get<0>(vertices).at(1),
                       std::get<0>(vertices).at(2));
    Vec3 point2 = Vec3(std::get<1>(vertices).at(0),
                       std::get<1>(vertices).at(1),
                       std::get<1>(vertices).at(2));
    Vec3 point3 = Vec3(std::get<2>(vertices).at(0),
                       std::get<2>(vertices).at(1),
                       std::get<2>(vertices).at(2));
    std::tuple<Vec3, Vec3, Vec3> Tri;
    Tri = std::make_tuple(point1, point2, point3);
    return Tri;
}
/**
 * @brief TriangleArray::size
 * @return How many tuples (triangles) are in the array
 */
unsigned int TriangleArray::size()
{
    return TriPoints.size();
}

std::vector<Vertex> TriangleArray::getVertices()
{
    return mVertices;
}

/**
 * @brief TriangleArray::at
 * @param index
 * @return Returns a vector of three Vec3 points constituting one triangle.
 * Easier than getting stuff from the tuple itself.
 */
std::vector<Vec3> TriangleArray::at(unsigned int index)
{
    std::vector<Vec3> triangleVector;
    triangleVector.push_back(std::get<0>(TriPoints.at(index)));
    triangleVector.push_back(std::get<1>(TriPoints.at(index)));
    triangleVector.push_back(std::get<2>(TriPoints.at(index)));
    return triangleVector;
}
/**
 * @brief TriangleArray::getTriangles
 * @return Returns the tuple if you absolutely must have it for some reason.
 */
std::vector<std::tuple<Vec3, Vec3, Vec3>> TriangleArray::getTriangles() const
{
    return TriPoints;
}
