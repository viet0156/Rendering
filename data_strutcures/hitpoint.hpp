#pragma once 

#include "point3.hpp"
#include "mesh.hpp"
#include <iostream>

class Hitpoint{
    public:
        Point3 position;
        float distance = std::numeric_limits<float>::max();
        const Mesh* mesh = nullptr;
};