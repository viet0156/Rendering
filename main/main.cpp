#include "../loader/meshloader.hpp"
#include "../data_strutcures/mesh.hpp"

int main(){
    
    Mesh mesh;
    Meshloader ms;

    ms.loadMesh("./objects/test.obj", mesh);
    return 0;
}