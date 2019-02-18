#include "vector3d.h"
#include <algorithm>
#include <cmath>
#include <fstream>
#include <iomanip>
#include <string>

namespace jl
{

void Vector3d::setXYZ(float &X, float &Y, float &Z)
{
    X = x;
    Y = y;
    Z = z;
}

float Vector3d::getX() const
{
    return x;
}

float Vector3d::getY() const
{
    return y;
}

float Vector3d::getZ() const
{
    return z;
}

void Vector3d::setX(float value)
{
    x = value;
}

void Vector3d::setY(float value)
{
    y = value;
}

void Vector3d::setZ(float value)
{
    z = value;
}

float Vector3d::length() const
{
    float length;
    return length = sqrtf(x * x + y * y + z * z);
}

void Vector3d::normalize()
{
    float magnitude = length();
    if (magnitude != 0.0f)
    {
        x /= magnitude;
        y /= magnitude;
        z /= magnitude;
    }
}
Vector3d Vector3d::normalized()
{
    float magnitude = length();
    return Vector3d(x / magnitude, y / magnitude, z / magnitude);
}
const Vector3d &Vector3d::operator=(const Vector3d &v) // Assignment
{
    x = v.x;
    y = v.y;
    z = v.z;
    return *this;
}

Vector3d Vector3d::operator+(const Vector3d &v) const
{
    Vector3d temp(x + v.x, y + v.y, z + v.z);
    return temp;
}

Vector3d Vector3d::operator-(const Vector3d &v) const
{
    Vector3d temp(x - v.x, y - v.y, z - v.z);
    return temp;
}

float Vector3d::operator*(const Vector3d &v) const // Dot Product
{
    return x * v.x + y * v.y + z * v.z;
}
Vector3d Vector3d::operator*(float c) const // Scaling
{
    Vector3d temp(x * c, y * c, z * c);
    return temp;
}

float Vector3d::size()
{
    return 3;
}

Vector3d Vector3d::operator^(const Vector3d &v) const // Cross Product
{
    float crossX = y * v.z - z * v.y;
    float crossY = z * v.x - x * v.z;
    float crossZ = x * v.y - y * v.x;
    Vector3d temp(crossX, crossY, crossZ);

    return temp;
}
std::istream &operator>>(std::istream &is, Vector3d &point)
{
    // Trenger fire temporære variabler som kun skal lese inn parenteser og komma
    char dum, dum2, dum3, dum4;
    is >> dum >> point.x >> dum2 >> point.y >> dum3 >> point.z >> dum4;

    return is;
}

std::ostream &operator<<(std::ostream &out, const Vector3d &c)
{
    // fixed and setprecision forces output to have one decimal.
    out << std::fixed << "(" << std::setprecision(1) << c.x << ", " << c.y << ", " << c.z << ")\n"; // actual output done here
    // (1.0, 2.0, 3.0)
    return out; // return std::ostream so we can chain calls to operator<<
}
float &Vector3d::at(unsigned int index)
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

float Vector3d::at(unsigned int index) const
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
void Vector3d::setXYZ2(int i, float xyz)
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
