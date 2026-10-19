#include "TerrainGenerator.hpp"
#include <cmath>
#include <random>

// Generate terrain
void TerrainGenerator::generate(Map& map, unsigned int seed) {
    std::mt19937 generator(seed);

    std::uniform_int_distribution<int> xDist(0, map.getWidth() - 1);
    std::uniform_int_distribution<int> yDist(0, map.getHeight() - 1);

    std::uniform_real_distribution<float> heightDist(300.0f, 1000.0f);
    std::uniform_real_distribution<float> radiusDist(10.0f, 40.0f);

    constexpr int mountainCount = 15;

    // Reset previous elevations
    for (int y = 0; y < map.getHeight(); y++) {
        for (int x = 0; x < map.getWidth(); x++) {
            map.getCell(x, y).setElevation(0.0f);
        }
    }

    // Generate mountains
    for (int i = 0; i < mountainCount; i++) {
        int centerX = xDist(generator);
        int centerY = yDist(generator);

        float height = heightDist(generator);
        float radius = radiusDist(generator);

        addMountain(map, centerX, centerY, height, radius);
    }
}

// Add a mountain to the map
void TerrainGenerator::addMountain(
    Map& map,
    int centerX,
    int centerY,
    float height,
    float radius
) {
    const float radiusSquared = radius * radius;

    for (int y = 0; y < map.getHeight(); y++) {
        for (int x = 0; x < map.getWidth(); x++) {

            auto dx = static_cast<float>(x - centerX);
            auto dy = static_cast<float>(y - centerY);

            float distanceSquared = dx * dx + dy * dy;
            if (distanceSquared > 9.0f * radiusSquared) {
                continue;
            }
            // Gaussian elevation contribution
            float elevation =
                height * std::exp(
                    -distanceSquared / (2.0f * radiusSquared)
                );

            Cell& cell = map.getCell(x, y);

            // Combine elevation contributions
            cell.setElevation(
                cell.getElevation() + elevation
            );
        }
    }
}