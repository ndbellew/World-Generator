#include "Map.hpp"
#include "TerrainGenerator.hpp"
#include "rendering/SDLRenderer.hpp"

int main(int argc, char* argv[]) {

    // Create a 256x256 map with default values
    Map map(1024, 1024);

    // Generate mountains using our terrain generator
    TerrainGenerator::generate(map, 12345678);

    // Print elevation values to the terminal
    //map.printMap();

    // Create SDL3 renderer
    SDLRenderer renderer(1024, 768);

    // Initialize SDL3
    if (!renderer.initialize()) {
        return 1;
    }

    // Display our generated terrain
    renderer.run(map);

    return 0;
}