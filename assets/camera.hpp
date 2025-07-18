#pragma once

#include "../data_strutcures/vector3.hpp"
#include "../data_strutcures/ray.hpp"

class Camera {
    
    public:
    
        Camera( Vector3 eye = {0,0,0},
                Vector3 view = {1,1,1},
                float width = 1.0, 
                float height = 1.0, 
                int width_pixels = 400, 
                int height_pixels = 400){
            this->eye = eye;
            this->view = view; 
            this->width = width;
            this->height = height;
            this->width_pixels = width_pixels;
            this->height_pixels = height_pixels;
        }

        ~Camera(){

        }

        void init(){
            
        }

        Vector3 get_Pixel(int x, int y) const{

        }

        Ray get_Ray(int x, int y) const {
        
            Vector3 forward = view.normalize();
            Vector3 tmp = Vector3::cross(world_up, forward);
            Vector3 right = tmp.normalize();
            
            float width_px = width / width_pixels;
            float height_px = height / height_pixels;

            float u = (x + 0.5f) * width_px - (width / 2.0f);
            float v = (height / 2.0f) - (y + 0.5f) * height_px;
        
            Vector3 px_pos = eye + (forward + (right * u) + (world_up * v));

            Vector3 tmp_direction = px_pos - eye; 
            Vector3 direction = tmp_direction.normalize();

            return Ray(eye, direction);

        }

        int getWidthPixel(){
            return width_pixels;
        }

        int getHeightPixel(){
            return height_pixels;
        }

    private:
        Vector3 eye;
        Vector3 view;
        float width;
        float height;
        int width_pixels;
        int height_pixels;
        Vector3 world_up = {0,1,0};
}; 