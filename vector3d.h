#ifndef VECTOR3D_H
#define VECTOR3D_H

#include <iostream>

namespace jl
{
class Vector3d
{
public:
    Vector3d(float a = 0.0f, float b = 0.0f, float c = 0.0) // Constructor
        : x(a), y(b), z(c)
    {
    }

    const Vector3d &operator=(const Vector3d &v); // Assignment
    Vector3d operator+(const Vector3d &v) const;  // Addition
    Vector3d operator-(const Vector3d &v) const;  // Subtraction
    float operator*(const Vector3d &v) const;     // Dot product
    Vector3d operator^(const Vector3d &v) const;  // Cross product
    float length() const;                         // return length
    void normalize();                             // Normalize to unit length
    Vector3d operator*(float c) const;            // Scaling

    float size();

    friend std::ostream &operator<<(std::ostream &out, const Vector3d &c);
    friend std::istream &operator>>(std::istream &in, Vector3d &point);
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

    Vector3d normalized();

    float &at(unsigned int index);
    float at(unsigned int index) const;

private:
    float x;
    float y;
    float z;
};
std::ostream &operator<<(std::ostream &out, const Vector3d &c);
std::istream &operator>>(std::istream &in, Vector3d &point);
} // namespace jl
#endif // VECTOR3D_H
