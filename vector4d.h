#ifndef VECTOR4D_H
#define VECTOR4D_H
#include "vector3d.h"
#include <vector>
namespace jl
{
class Matrix4x4;
class Vector4D
{
public:
    Vector4D(float a = 0.0f, float b = 0.0f, float c = 0.0, float d = 0.0) // Constructor
        : x(a), y(b), z(c), w(d)
    {
    }
    Vector4D(Vector3D vec3, float d = 0.0f);
    ~Vector4D() {}
    const Vector4D &operator=(const Vector4D &v); // Assignment
    Vector4D operator+(const Vector4D &v) const;  // Addition
    Vector4D operator-(const Vector4D &v) const;  // Subtraction
    float operator*(const Vector4D &v) const;     // Dot product
    float length() const;                         // return length
    void normalize();                             // Normalize to unit length
    Vector4D operator*(float c) const;            // Scaling
    Vector3D vec3ToVec4(Vector4D vec4);

    friend std::ostream &operator<<(std::ostream &out, const Vector4D &c);
    friend std::istream &operator>>(std::istream &in, Vector4D &point);
    // Overload stream operators << and >>. Let the vector look like (1.0, 2.0, 3.0) when stored
    // on a text file.
    std::vector<float> arr() const;
    float getX() const;

    float getY() const;

    float getZ() const;

    float getW() const;
    float &operator[](int i);
    float &at(unsigned int index);
    float at(unsigned int index) const;

    float size();

private:
    float x;
    float y;
    float z;
    float w;
    float array[4]{x, y, z, w};
};
std::ostream &operator<<(std::ostream &out, const Vector4D &c);
std::istream &operator>>(std::istream &in, Vector4D &point);
} // namespace jl
#endif // VECTOR4D_H
