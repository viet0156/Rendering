#pragma once

#include "../data_strutcures/vector3.hpp"
#include "../data_strutcures/vector2.hpp"
#include "../data_strutcures/mesh.hpp"
#include "../data_strutcures/vertex.hpp"
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

class Meshloader{

    public:
        
        Meshloader(){

        }

        ~Meshloader(){

        }

        void loadMesh(std::string filename, Mesh mesh){
            std::fstream file;
            file.open(filename, std::ios::in);
            
            if(file.is_open()){
                std::string line;
                
                while(std::getline(file, line)){
                    std::istringstream iss(line);
                    std::string prefix;
                    iss >> prefix;
                    
                    if(prefix == "v"){
                        float x, y, z;
                        iss >> x >> y >> z;
                        Vector3 position = {x, y, z};
                        this->addPosition(position);
                        std::cout << prefix << std::endl;
                        std::cout << "Position: (" << position.x << ", " << position.y << ", " << position.z << ")" << std::endl;
                    } else if(prefix == "vn"){
                        float nx, ny, nz;
                        iss >> nx >> ny >> nz;
                        Vector3 normal = {nx, ny, nz};
                        this->addNormal(normal);
                        std::cout << prefix << std::endl;
                        std::cout << "Normal: (" << normal.x << ", " << normal.y << ", " << normal.z << ")" << std::endl;
                    } else if(prefix == "vt"){
                        float u, v; 
                        iss >> u >> v;
                        Vector2 texCoord = {u, v};
                        this->addTexture(texCoord);
                        std::cout << prefix << std::endl;
                        std::cout << "TexCoord: (" << texCoord.x << ", " << texCoord.y << ")" << std::endl;
                    } else if(prefix == "f"){
                        std::cout << prefix << std::endl;

                        Triangle triangle;

                        for (int i = 0; i < 3; ++i) {
                            std::string group;
                            iss >> group;

                            int vertexIndex, texCoordIndex, normalIndex;
                            if (sscanf(group.c_str(), "%d/%d/%d", &vertexIndex, &texCoordIndex, &normalIndex) != 3) {
                                std::cerr << "Ungültiges Face-Format: " << group << std::endl;
                                continue;
                            }

                            Vertex vertex;
                            vertex.positions = tmp_positions[vertexIndex - 1];
                            vertex.normals = tmp_normals[normalIndex - 1];
                            vertex.texture = tmp_texture[texCoordIndex - 1];

                            mesh.addVertex(vertex);
                            int newIndex = mesh.getVerticesLength() - 1;

                            triangle.setIndex(i, newIndex);
                        }

                        mesh.addTriangle(triangle);
                        output_Faces(mesh);
                    }
                    else {
                        std::cout << "--Unbekanner Prefix-- " << prefix << std::endl;
                    }

                }

            } else {
                std::cerr << "OBJ File konnte nicht geöffnet werden: " << filename << std::endl;
            }
            file.close();
            std::cout << "File-Handler geschlossen" << std::endl;
        }

        void clearData(){

        }

        void addPosition(Vector3 v){
            tmp_positions.push_back(v);
        }

        void addNormal(Vector3 v){
            tmp_normals.push_back(v);
        }

        void addTexture(Vector2 v){
            tmp_texture.push_back(v);
        }
        
        void output_Faces(Mesh mesh){
            std::cout << "Faces:" << std::endl;
            for(int i = 0; i < mesh.getTriangleLength(); ++i){
                std::cout << "Triangle: " << i << std::endl;
                for(int j = 0; j < 3; j++){
                    std::cout << mesh.getTriangle(i).getTriangle(j)<< std::endl;
                }
            }

        }

    private:
        std::vector<Vector3> tmp_positions; 
        std::vector<Vector3> tmp_normals;
        std::vector<Vector2> tmp_texture;
};