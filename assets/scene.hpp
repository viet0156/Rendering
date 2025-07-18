#pragma once

#include "camera.hpp"
#include "../data_strutcures/mesh.hpp"
#include <vector>

class scene {
    public:
        std::vector<Mesh> MeshList;
        Camera camera;
    private:
};