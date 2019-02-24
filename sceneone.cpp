#include "sceneone.h"
Sceneone::Sceneone() : GameObject(Vec3(0, 0, 0), Vec3(2, 1, 2))
{
    // Plane
    mVertices.push_back(Vertex{-0.8, 0, 0.8, 0.5, 1, 1});
    mVertices.push_back(Vertex{-0.8, 0, -0.8, 0.5, 1, 1});
    mVertices.push_back(Vertex{0.8, 0, -0.8, 0.5, 1, 1});

    mVertices.push_back(Vertex{-0.8, 0, 0.8, 0.5, 1, 1});
    mVertices.push_back(Vertex{0.8, 0, 0.8, 0.5, 1, 1});
    mVertices.push_back(Vertex{0.8, 0, -0.8, 0.5, 1, 1});

    // Left Wall
    mVertices.push_back(Vertex{-0.8, 0, 0.8, 1, 0, 1});
    mVertices.push_back(Vertex{-0.8, 0.4, 0.8, 1, 1, 0});
    mVertices.push_back(Vertex{-0.8, 0, -0.8, 0, 1, 1});

    mVertices.push_back(Vertex{-0.8, 0.4, 0.8, 1, 0, 1});
    mVertices.push_back(Vertex{-0.8, 0.4, -0.8, 1, 1, 0});
    mVertices.push_back(Vertex{-0.8, 0, -0.8, 0, 1, 1});

    // Right Wall
    mVertices.push_back(Vertex{0.8, 0, 0.8, 1, 1, 0});
    mVertices.push_back(Vertex{0.8, 0.4, 0.8, 1, 0, 1});
    mVertices.push_back(Vertex{0.8, 0, -0.8, 0, 1, 1});

    mVertices.push_back(Vertex{0.8, 0.4, 0.8, 1, 1, 0});
    mVertices.push_back(Vertex{0.8, 0.4, -0.8, 1, 0, 1});
    mVertices.push_back(Vertex{0.8, 0, -0.8, 0, 1, 1});

    // Back Wall
    mVertices.push_back(Vertex{0.8, 0, 0.8, 0, 0, 1});
    mVertices.push_back(Vertex{0.8, 0.4, 0.8, 0, 0, 1});
    mVertices.push_back(Vertex{-0.8, 0, 0.8, 0, 0, 1});

    mVertices.push_back(Vertex{0.8, 0.4, 0.8, 0, 0, 1});
    mVertices.push_back(Vertex{-0.8, 0.4, 0.8, 0, 0, 1});
    mVertices.push_back(Vertex{-0.8, 0, 0.8, 0, 0, 1});

    // Front Wall
    mVertices.push_back(Vertex{-0.8, 0, 0.8, 1, 0, 0});
    mVertices.push_back(Vertex{-0.8, 0.4, 0.8, 1, 0, 0});
    mVertices.push_back(Vertex{-0.8, 0, -0.8, 1, 0, 0});

    mVertices.push_back(Vertex{-0.8, 0.4, 0.8, 1, 0, 0});
    mVertices.push_back(Vertex{-0.8, 0.4, -0.8, 1, 0, 0});
    mVertices.push_back(Vertex{-0.8, 0, -0.8, 1, 0, 0});
}

void Sceneone::init(GLint matrixUniform)
{
    GameObject::init(matrixUniform);
    // Save all the triangles in the scene
    // SceneTriangles contains 10 std::vectors of type Vector3D.
    // These std::vectors all contain exactly 3 objects,
    // each std::vector constitutes one triangle.
    for (unsigned int i = 0; i < 10; i++)
    {
        for (unsigned int j = 0; j < 3; j++)
        {
            // Temporarily transform into Vector4D for multiplication with model matrix
            Vector4D tempVec = Vector3D(mVertices.at(j + i * 3).at(0), mVertices.at(j + i * 3).at(1), mVertices.at(j + i * 3).at(2));
            // (Hopefully) convert the vector into scene space
            tempVec = mMatrix * tempVec;
            sceneTriangles.push_back(Vector3D(tempVec));
        }
    }
}

std::vector<Vector3D> Sceneone::getSceneTriangles() const
{
    return sceneTriangles;
}
