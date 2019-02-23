#include "scenetwo.h"

Scenetwo::Scenetwo() : GameObject(Vec3(0, 0, 0), Vec3(2, 1, 2))
{
    // Ground
    mVertices.push_back(Vertex{-1, -0.8, 1, 0, 0.3, 0.5});
    mVertices.push_back(Vertex{-1, -0.8, -1, 0, 0.3, 0.5});
    mVertices.push_back(Vertex{1, -0.8, -1, 0, 0.3, 0.5});

    mVertices.push_back(Vertex{-1, -0.8, 1, 0, 0.3, 0.5});
    mVertices.push_back(Vertex{1, -0.8, 1, 0, 0.3, 0.5});
    mVertices.push_back(Vertex{1, -0.8, -1, 0, 0.3, 0.5});

    // Left Wall
    mVertices.push_back(Vertex{-0.8, -0.8, 0.8, 1, 0.5, 0.5});
    mVertices.push_back(Vertex{-0.8, 0.1, 0.8, 1, 0.5, 0.5});
    mVertices.push_back(Vertex{-0.8, -0.8, -0.8, 1, 0.5, 0.5});

    mVertices.push_back(Vertex{-0.8, 0.1, 0.8, 1, 0.5, 0.5});
    mVertices.push_back(Vertex{-0.8, 0.1, -0.8, 1, 0.5, 0.5});
    mVertices.push_back(Vertex{-0.8, -0.8, -0.8, 1, 0.5, 0.5});

    // Right Wall
    mVertices.push_back(Vertex{0.8, -0.8, 0.8, 1, 0.5, 0.5});
    mVertices.push_back(Vertex{0.8, 0.1, 0.8, 1, 0.5, 0.5});
    mVertices.push_back(Vertex{0.8, -0.8, -0.8, 1, 0.5, 0.5});

    mVertices.push_back(Vertex{0.8, 0.1, 0.8, 1, 0.5, 0.5});
    mVertices.push_back(Vertex{0.8, 0.1, -0.8, 1, 0.5, 0.5});
    mVertices.push_back(Vertex{0.8, -0.8, -0.8, 1, 0.5, 0.5});

    // Back Wall
    mVertices.push_back(Vertex{0.8, -0.8, 0.8, 1, 0.5, 0.5});
    mVertices.push_back(Vertex{0.8, 0.1, 0.8, 1, 0.5, 0.5});
    mVertices.push_back(Vertex{-0.8, -0.8, 0.8, 1, 0.5, 0.5});

    mVertices.push_back(Vertex{0.8, 0.1, 0.8, 1, 0.5, 0.5});
    mVertices.push_back(Vertex{-0.8, 0.1, 0.8, 1, 0.5, 0.5});
    mVertices.push_back(Vertex{-0.8, -0.8, 0.8, 1, 0.5, 0.5});

    // Front Wall 1
    mVertices.push_back(Vertex{-0.8, -0.8, -0.8, 1, 0.5, 0.5});
    mVertices.push_back(Vertex{-0.8, 0.1, -0.8, 1, 0.5, 0.5});
    mVertices.push_back(Vertex{-0.1, -0.8, -0.8, 1, 0.5, 0.5});

    mVertices.push_back(Vertex{-0.8, 0.1, -0.8, 1, 0.5, 0.5});
    mVertices.push_back(Vertex{-0.1, 0.1, -0.8, 1, 0.5, 0.5});
    mVertices.push_back(Vertex{-0.1, -0.8, -0.8, 1, 0.5, 0.5});

    // Front Wall 2
    mVertices.push_back(Vertex{0.8, -0.8, -0.8, 1, 0.5, 0.5});
    mVertices.push_back(Vertex{0.8, 0.1, -0.8, 1, 0.5, 0.5});
    mVertices.push_back(Vertex{0.1, -0.8, -0.8, 1, 0.5, 0.5});

    mVertices.push_back(Vertex{0.8, 0.1, -0.8, 1, 0.5, 0.5});
    mVertices.push_back(Vertex{0.1, 0.1, -0.8, 1, 0.5, 0.5});
    mVertices.push_back(Vertex{0.1, -0.8, -0.8, 1, 0.5, 0.5});

    // Front wall upper
    mVertices.push_back(Vertex{-0.1, 0.1, -0.8, 1, 0.5, 0.5});
    mVertices.push_back(Vertex{-0.1, -0.4, -0.8, 1, 0.5, 0.5});
    mVertices.push_back(Vertex{0.1, -0.4, -0.8, 1, 0.5, 0.5});

    mVertices.push_back(Vertex{0.1, 0.1, -0.8, 1, 0.5, 0.5});
    mVertices.push_back(Vertex{-0.1, 0.1, -0.8, 1, 0.5, 0.5});
    mVertices.push_back(Vertex{0.1, -0.4, -0.8, 1, 0.5, 0.5});

    // Door
    mVertices.push_back(Vertex{-0.1, -0.4, -0.8, 0.1, 0, 0.1});
    mVertices.push_back(Vertex{-0.1, -0.8, -0.8, 0.1, 0, 0.1});
    mVertices.push_back(Vertex{0.1, -0.8, -0.8, 0.1, 0, 0.1});

    mVertices.push_back(Vertex{0.1, -0.4, -0.8, 0.1, 0, 0.1});
    mVertices.push_back(Vertex{-0.1, -0.4, -0.8, 0.1, 0, 0.1});
    mVertices.push_back(Vertex{0.1, -0.8, -0.8, 0.1, 0, 0.1});

    // Upper front wall
    mVertices.push_back(Vertex{-0.8, 0.1, -0.8, 1, 0.5, 0.5});
    mVertices.push_back(Vertex{0, 0.1, -0.8, 1, 0.5, 0.5});
    mVertices.push_back(Vertex{0, 0.9, -0.8, 1, 0.5, 0.5});

    mVertices.push_back(Vertex{0.8, 0.1, -0.8, 1, 0.5, 0.5});
    mVertices.push_back(Vertex{0, 0.1, -0.8, 1, 0.5, 0.5});
    mVertices.push_back(Vertex{0, 0.9, -0.8, 1, 0.5, 0.5});

    // Upper back wall
    mVertices.push_back(Vertex{-0.8, 0.1, 0.8, 1, 0.5, 0.5});
    mVertices.push_back(Vertex{0, 0.1, 0.8, 1, 0.5, 0.5});
    mVertices.push_back(Vertex{0, 0.9, 0.8, 1, 0.5, 0.5});

    mVertices.push_back(Vertex{0.8, 0.1, 0.8, 1, 0.5, 0.5});
    mVertices.push_back(Vertex{0, 0.1, 0.8, 1, 0.5, 0.5});
    mVertices.push_back(Vertex{0, 0.9, 0.8, 1, 0.5, 0.5});

    // Left Roof
    mVertices.push_back(Vertex{-0.9, 0, 0.9, 0.1, 0.1, 0.1});
    mVertices.push_back(Vertex{-0.9, 0, -0.9, 0.1, 0.1, 0.1});
    mVertices.push_back(Vertex{0, 0.9, -0.9, 0.1, 0.1, 0.1});

    mVertices.push_back(Vertex{-0.9, 0, 0.9, 0.1, 0.1, 0.1});
    mVertices.push_back(Vertex{0, 0.9, 0.9, 0.1, 0.1, 0.1});
    mVertices.push_back(Vertex{0, 0.9, -0.9, 0.1, 0.1, 0.1});

    // Right Roof
    mVertices.push_back(Vertex{0.9, 0, 0.9, 0.1, 0.1, 0.1});
    mVertices.push_back(Vertex{0.9, 0, -0.9, 0.1, 0.1, 0.1});
    mVertices.push_back(Vertex{0, 0.9, -0.9, 0.1, 0.1, 0.1});

    mVertices.push_back(Vertex{0.9, 0, 0.9, 0.1, 0.1, 0.1});
    mVertices.push_back(Vertex{0, 0.9, 0.9, 0.1, 0.1, 0.1});
    mVertices.push_back(Vertex{0, 0.9, -0.9, 0.1, 0.1, 0.1});
}
