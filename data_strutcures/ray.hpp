#pragma once

#include "point3.hpp"
#include "vector3.hpp"

class Ray{
    public:
        Ray(Vector3 origin, Vector3 direction){
            this->origin = origin;
            this->direction = direction;
        }
        Vector3 origin;
        Vector3 direction;
};