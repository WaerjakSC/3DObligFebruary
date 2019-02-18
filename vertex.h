#ifndef VERTEX_H
#define VERTEX_H
#include <iostream>

class Vertex
{
public:
    Vertex();
    Vertex(float x, float y, float z, float r, float g, float b)
        : m_xyz{x, y, z}, m_normal{r, b, g}
    {
    }
    void set_xyz(float x, float y, float z);
    void set_normal(float r, float b, float g);
    void set_uv(float u, float v);

private:
    float m_xyz[3];    // position i 3D
    float m_normal[3]; // normal in 3D or rgb colors
    float m_uv[2];     // texture coordinates if used

    //! Overloaded ostream operator which writes all vertex data on an open textfile stream
    friend std::ostream &operator<<(std::ostream &, const Vertex &);

    //! Overloaded ostream operator which reads all vertex data from an open textfile stream
    friend std::istream &operator>>(std::istream &, Vertex &);
};
#endif // VERTEX_H
