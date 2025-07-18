#pragma once

#include "camera.hpp"
#include "../data_strutcures/mesh.hpp"
#include <vector>
#include "../data_strutcures/vector3.hpp"
#include "../data_strutcures/ray.hpp"

class scene {
    public:
        std::vector<Mesh> MeshList;
        Camera camera = Camera();
        
        void fillRayList(){
            for(int i = 0; i < camera.getHeightPixel(); i++){
                for(int j = 0; j < camera.getWidthPixel(); j++){
                    rayList.push_back(camera.get_Ray(j,i));
                }
            }
        }

        bool isObjectHit(){
            
        }
    private:
        std::vector<Ray> rayList;
};