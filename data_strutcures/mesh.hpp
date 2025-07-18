#pragma once

#include "vector3.hpp"
#include "vector"
#include "triangle.hpp"
#include "vertex.hpp"

class Mesh{

    public:
        
        Mesh(){

        }

        ~Mesh(){

        }
        
        /**
         * Add Vertex to Vertices List 
         * @param v Vertex to add
         */
        void addVertex(Vertex v){
            vertices.push_back(v);
        }

        /**
         * Add Triangle to Triangle List 
         * @param t Triangle to add
         */
        void addTriangle(Triangle t){
            triangles.push_back(t);
        }

        /**
         * Return size of Vertices List
         * @return size 
         */
        int getVerticesLength(){
            return vertices.size();
        }

        /**
         * Return size of Triangle List
         * @return size 
         */
        int getTriangleLength(){
            return triangles.size();
        }

        Vertex getVertex(int x){
            return vertices.at(x);
        }

        Triangle getTriangle(int x){
            return triangles.at(x);
        }

        void out_Put_All_Triangles(){

        }

        void outputData(){

        }

        void clear(){

        }

    private:
        std::vector<Vertex> vertices;
        std::vector<Triangle> triangles;
};