#include "../loader/meshloader.hpp"
#include "../data_strutcures/mesh.hpp"
#include "../assets/camera.hpp"

int main(){
    Mesh mesh;
    Meshloader ms;

    ms.loadMesh("./objects/test.obj", mesh);
    return 0;
}