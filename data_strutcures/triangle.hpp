#pragma once
#include <array>
#include "vertex.hpp"

struct Triangle{
    std::array<int, 3> vertexIndices;
    
    void setIndex(int index, int i){    
        this->vertexIndices.at(index) = i;
    }

    int getTriangle(int i){
        return vertexIndices.at(i);
    }
};
