#include "visualobject.h"
#include <fstream>

VisualObject::VisualObject() {}
VisualObject::~VisualObject()
{
    glDeleteVertexArrays(1, &mVAO);
    glDeleteBuffers(1, &mVBO);
}
void VisualObject::readFile(std::string filnavn)
{
    std::ifstream inn;
    inn.open(filnavn.c_str());

    if (inn.is_open())
    {
        int n;
        Vertex vertex;
        inn >> n;
        mVertices.reserve(n);
        for (int i = 0; i < n; i++)
        {
            inn >> vertex;
            mVertices.push_back(vertex);
        }
        inn.close();
    }
}
void VisualObject::writeFile(std::string filename)
{
    for (auto i : mVertices)
    {
        std::ofstream file(filename.c_str());
        if (file.is_open())
        {
            file << i;
            file.close();
        }
        else
        {
            std::cout << "Unable to open file\n";
        }
    }
}
