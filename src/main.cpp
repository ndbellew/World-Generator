#include "Map.hpp"

int main() {
    Map map(256, 256);

    // Map contains default cells
    map.randomGenerate();

    // Map now contains randomized terrain data
    map.randomGenerate();

    return 0;
}