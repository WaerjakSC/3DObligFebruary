#ifndef VECTOR3D_H
#define VECTOR3D_H

#include <iostream>

namespace jl
{
class Matrix4x4;
class Vector4D;

class Vector3D
{
public:
    Vector3D(float a = 0.0f, float b = 0.0f, float c = 0.0) // Constructor
        : x(a), y(b), z(c)
    {
    }
    Vector3D(Vector4D vec);

    const Vector3D &operator=(const Vector3D &v); // Assignment
    Vector3D operator+(const Vector3D &v) const;  // Addition
    Vector3D operator-(const Vector3D &v) const;  // Subtraction
    float operator*(const Vector3D &v) const;     // Dot product
    Vector3D operator^(const Vector3D &v) const;  // Cross product
    float length() const;                         // return length
    float squaredlLength() const;                 // Squared length
    void normalize();                             // Normalize to unit length
    Vector3D operator*(float c) const;            // Scaling
    Vector3D operator*(Matrix4x4 &m) const;       // Left-multiply with matrix

    float size();

    void setLength(float desiredLength);
    friend std::ostream &operator<<(std::ostream &out, const Vector3D &c);
    friend std::istream &operator>>(std::istream &in, Vector3D &point);
    // Overload stream operators << and >>. Let the vector look like (1.0, 2.0, 3.0) when stored
    // on a text file.
    void setXYZ(float &X, float &Y, float &Z);
    void setXYZ2(int i, float xyz);
    float getX() const;

    float getY() const;

    float getZ() const;

    void setX(float value);

    void setY(float value);

    void setZ(float value);

    Vector3D normalized();

    float &at(unsigned int index);
    float at(unsigned int index) const;

private:
    float x;
    float y;
    float z;
};
std::ostream &operator<<(std::ostream &out, const Vector3D &c);
std::istream &operator>>(std::istream &in, Vector3D &point);
} // namespace jl
#endif // VECTOR3D_H
