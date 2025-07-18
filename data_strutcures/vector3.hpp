#pragma once

struct Vector3{
    
    float x, y, z;

    Vector3 operator+(const Vector3 v) const {
        return { x + v.x, y + v.y, z + v.z };
    }

    Vector3 operator-(){
        return {-x, -y, -z};
    }

    Vector3 operator-(const Vector3 v){
        return {x - v.x, y - v.y, z - v.z};
    }
};