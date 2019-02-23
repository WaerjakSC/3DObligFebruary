#include "vector4d.h"
#include <algorithm>
#include <cmath>
#include <fstream>
#include <iomanip>
#include <string>

namespace jl
{

Vector4D::Vector4D(Vector3D vec3, float d)
{
    x = vec3.getX();
    y = vec3.getY();
    z = vec3.getZ();
    w = d;
}
Vector3D Vector4D::vec3ToVec4(Vector4D vec4)
{
    Vector3D vec3(vec4.x, vec4.y, vec4.z);
    return vec3;
}

std::vector<float> Vector4D::arr() const
{
    return std::vector<float>{x, y, z, w};
}

float Vector4D::getX() const
{
    return x;
}

float Vector4D::getY() const
{
    return y;
}

float Vector4D::getZ() const
{
    return z;
}

float Vector4D::getW() const
{
    return w;
}

float &Vector4D::at(unsigned int index)
{
    switch (index)
    {
    case 0:
        return x;
    case 1:
        return y;
    case 2:
        return z;
    case 3:
        return w;
    default:
        throw std::out_of_range{"Vector4d only has 4 datavalues."};
        return x;
    }
}

float Vector4D::at(unsigned int index) const
{
    switch (index)
    {
    case 0:
        return x;
    case 1:
        return y;
    case 2:
        return z;
    case 3:
        return w;
    default:
        return x;
    }
}
float Vector4D::size()
{
    return 4;
}
float &Vector4D::operator[](int i)
{
    x = array[0];
    y = array[1];
    z = array[2];
    w = array[3];
    return array[i];
}

const Vector4D &Vector4D::operator=(const Vector4D &v) // Assignment
{
    x = v.x;
    y = v.y;
    z = v.z;
    w = v.w;
    return *this;
}

Vector4D Vector4D::operator+(const Vector4D &v) const
{
    Vector4D temp(x + v.x, y + v.y, z + v.z, w + v.w);
    return temp;
}

Vector4D Vector4D::operator-(const Vector4D &v) const
{
    Vector4D temp(x - v.x, y - v.y, z - v.z, w - v.w);
    return temp;
}

float Vector4D::operator*(const Vector4D &v) const // Dot Product
{
    return x * v.x + y * v.y + z * v.z + w * v.w;
}
Vector4D Vector4D::operator*(float c) const // Scaling
{
    Vector4D temp(x * c, y * c, z * c, w * c);
    return temp;
}

float Vector4D::length() const
{
    float length;
    return length = sqrtf(x * x + y * y + z * z);
}

void Vector4D::normalize()
{
    float magnitude = length();
    if (magnitude != 0.0f)
    {
        x /= magnitude;
        y /= magnitude;
        z /= magnitude;
        w /= magnitude;
    }
}

std::istream &operator>>(std::istream &is, Vector4D &point)
{
    // Trenger fire temporære variabler som kun skal lese inn parenteser og komma
    char dum, dum2, dum3, dum4, dum5;
    is >> dum >> point.x >> dum2 >> point.y >> dum3 >> point.z >> dum4 >> point.w >> dum5;

    return is;
}

std::ostream &operator<<(std::ostream &out, const Vector4D &c)
{
    // fixed and setprecision forces output to have one decimal.
    out << std::fixed << "(" << std::setprecision(1) << c.x << ", " << c.y << ", " << c.z << ", " << c.w << ")\n"; // actual output done here
    // (1.0, 2.0, 3.0, 4.0)
    return out; // return std::ostream so we can chain calls to operator<<
}
} // namespace jl
