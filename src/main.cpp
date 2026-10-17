#include "Map.hpp"
#include "rendering/SDLRenderer.hpp"

int main(int argc, char* argv[]) {

    // Create our world
    Map map(256, 256);

    // Randomly generate the terrain
    map.randomGenerate();

    // Create our renderer
    SDLRenderer renderer(1024, 768);

    // Initialize SDL3
    if (!renderer.initialize()) {
        return 1;
    }

    // Display our world
    renderer.run(map);

    return 0;
}