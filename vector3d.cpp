#include "vector3d.h"
#include <algorithm>
#include <cmath>
#include <fstream>
#include <iomanip>
#include <string>

namespace jl
{

void Vector3D::setXYZ(float &X, float &Y, float &Z)
{
    X = x;
    Y = y;
    Z = z;
}

float Vector3D::getX() const
{
    return x;
}

float Vector3D::getY() const
{
    return y;
}

float Vector3D::getZ() const
{
    return z;
}

void Vector3D::setX(float value)
{
    x = value;
}

void Vector3D::setY(float value)
{
    y = value;
}

void Vector3D::setZ(float value)
{
    z = value;
}

float Vector3D::length() const
{
    float length;
    return length = sqrtf(x * x + y * y + z * z);
}

void Vector3D::normalize()
{
    float magnitude = length();
    if (magnitude != 0.0f)
    {
        x /= magnitude;
        y /= magnitude;
        z /= magnitude;
    }
}
Vector3D Vector3D::normalized()
{
    float magnitude = length();
    return Vector3D(x / magnitude, y / magnitude, z / magnitude);
}
const Vector3D &Vector3D::operator=(const Vector3D &v) // Assignment
{
    x = v.x;
    y = v.y;
    z = v.z;
    return *this;
}

Vector3D Vector3D::operator+(const Vector3D &v) const
{
    Vector3D temp(x + v.x, y + v.y, z + v.z);
    return temp;
}

Vector3D Vector3D::operator-(const Vector3D &v) const
{
    Vector3D temp(x - v.x, y - v.y, z - v.z);
    return temp;
}

float Vector3D::operator*(const Vector3D &v) const // Dot Product
{
    return x * v.x + y * v.y + z * v.z;
}
Vector3D Vector3D::operator*(float c) const // Scaling
{
    Vector3D temp(x * c, y * c, z * c);
    return temp;
}

float Vector3D::size()
{
    return 3;
}

Vector3D Vector3D::operator^(const Vector3D &v) const // Cross Product
{
    float crossX = y * v.z - z * v.y;
    float crossY = z * v.x - x * v.z;
    float crossZ = x * v.y - y * v.x;
    Vector3D temp(crossX, crossY, crossZ);

    return temp;
}
std::istream &operator>>(std::istream &is, Vector3D &point)
{
    // Trenger fire temporære variabler som kun skal lese inn parenteser og komma
    char dum, dum2, dum3, dum4;
    is >> dum >> point.x >> dum2 >> point.y >> dum3 >> point.z >> dum4;

    return is;
}

std::ostream &operator<<(std::ostream &out, const Vector3D &c)
{
    // fixed and setprecision forces output to have one decimal.
    out << std::fixed << "(" << std::setprecision(1) << c.x << ", " << c.y << ", " << c.z << ")\n"; // actual output done here
    // (1.0, 2.0, 3.0)
    return out; // return std::ostream so we can chain calls to operator<<
}
float &Vector3D::at(unsigned int index)
{
    switch (index)
    {
    case 0:
        return x;
    case 1:
        return y;
    case 2:
        return z;
    default:
        throw std::out_of_range{"Vector4d only has 4 datavalues."};
        return x;
    }
}

float Vector3D::at(unsigned int index) const
{
    switch (index)
    {
    case 0:
        return x;
    case 1:
        return y;
    case 2:
        return z;
    default:
        return x;
    }
}
void Vector3D::setXYZ2(int i, float xyz)
{
    switch (i)
    {
    case 0:
        x = xyz;
        break;
    case 1:
        y = xyz;
        break;
    case 2:
        z = xyz;
        break;
    }
}

} // namespace jl
