#include "TerrainGenerator.hpp"
#include <cmath>
#include <random>

// Generate terrain
void TerrainGenerator::generate(Map& map, unsigned int seed) {
    std::mt19937 generator(seed);

    std::uniform_int_distribution<int> xDist(0, map.getWidth() - 1);
    std::uniform_int_distribution<int> yDist(0, map.getHeight() - 1);

    std::uniform_real_distribution<float> heightDist(300.0f, 8000.00f);
    std::uniform_real_distribution<float> radiusDist(10.0f, 80.0f);

    std::uniform_real_distribution<float> declineDist(1.0f, 800.0f);

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
        float decline = declineDist(generator);

        addMountain(map, centerX, centerY, height, radius, decline);
    }
}

// Add a mountain to the map
void TerrainGenerator::addMountain(
    Map& map,
    int centerX,
    int centerY,
    float height,
    float radius,
    float declineDistance
) {
    const float radiusSquared = radius * radius;
    const float declineSquared = declineDistance * declineDistance;

    constexpr float peakWeight = 0.4f;
    constexpr float highlandWeight = 0.6f;

    for (int y = 0; y < map.getHeight(); y++) {
        for (int x = 0; x < map.getWidth(); x++) {

            auto dx = static_cast<float>(x - centerX);
            auto dy = static_cast<float>(y - centerY);

            float distanceSquared = dx * dx + dy * dy;

            // Mountain peak
            float peakElevation = height * peakWeight * std::exp(
                -distanceSquared / (2.0f * radiusSquared)
            );

            // Surrounding terrain
            float highlandElevation = height * highlandWeight * std::exp(
                -distanceSquared / (2.0f * declineSquared)
            );

            float elevation = peakElevation + highlandElevation;

            Cell& cell = map.getCell(x, y);

            cell.setElevation(
                cell.getElevation() + elevation
            );
        }
    }
}