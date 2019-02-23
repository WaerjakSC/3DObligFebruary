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
