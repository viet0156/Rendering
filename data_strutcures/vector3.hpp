#pragma once

#include <cmath>

struct Vector3{
    
    float x, y, z;

    Vector3 operator+(const Vector3 v) const {
        return { x + v.x, y + v.y, z + v.z };
    }

    Vector3 operator-(){
        return {-x, -y, -z};
    }

    Vector3 operator-(const Vector3 v) const {
        return {x - v.x, y - v.y, z - v.z};
    }

    Vector3 operator*(float scalar) const {
        return Vector3{x * scalar, y * scalar, z * scalar};
    }

    float magnitude() const {
        return std::sqrt(x * x + y * y + z * z);
    }

    Vector3 normalize() const {
        float len = magnitude();
        return (len > 0) ? Vector3{x / len, y / len, z / len} : *this;    
    }

    Vector3 scale(float f){
        return {x*f, y*f, z*f};
    }

    static Vector3 cross(Vector3 v1, Vector3 v2){
        return Vector3{
            v1.y * v2.z - v1.z * v2.y,
            v1.z * v2.x - v1.x * v2.z, 
            v1.x * v2.y - v1.y * v2.x
        };
    }

};