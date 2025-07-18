#pragma once

#include "../data_strutcures/vector3.hpp"

class Camera {
    public:
       
    private:
        Vector3 eye;
        Vector3 view;
        float width;
        float height;
        int width_pixels;
        int height_pixels;
}; 