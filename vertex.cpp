#include "vertex.h"

Vertex::Vertex()
{
}

void Vertex::set_xyz(float x, float y, float z)
{
    m_xyz[0] = x;
    m_xyz[1] = y;
    m_xyz[2] = z;
}

void Vertex::set_normal(float r, float b, float g)
{
    m_normal[0] = r;
    m_normal[1] = b;
    m_normal[2] = g;
}

void Vertex::set_uv(float u, float v)
{
    m_uv[0] = u;
    m_uv[1] = v;
}
std::ostream &operator<<(std::ostream &os, const Vertex &v)
{
    os << std::fixed;
    os << "(" << v.m_xyz[0] << ", " << v.m_xyz[1] << ", " << v.m_xyz[2] << ") ";
    os << "(" << v.m_normal[0] << ", " << v.m_normal[1] << ", " << v.m_normal[2] << ") ";
    os << "(" << v.m_uv[0] << ", " << v.m_uv[1] << ") ";
    return os;
}
std::istream &operator>>(std::istream &is, Vertex &v)
{
    // Trenger fire temporære variabler som kun skal lese inn parenteser og komma
    char dum, dum2, dum3, dum4;
    is >> dum >> v.m_xyz[0] >> dum2 >> v.m_xyz[1] >> dum3 >> v.m_xyz[2] >> dum4;
    is >> dum >> v.m_normal[0] >> dum2 >> v.m_normal[1] >> dum3 >> v.m_normal[2] >> dum4;
    is >> dum >> v.m_uv[0] >> dum2 >> v.m_uv[1] >> dum3;
    return is;
}
