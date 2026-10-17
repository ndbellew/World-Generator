//
// Created by nathanbellew on 10/17/26.
//
#include "Map.hpp"
#include <stdexcept>
#include <random>

// Constructor
Map::Map(int width, int height)
    : width(width), height(height)
{
    generate();
}

// Generator
void Map::generate() {
    cells.resize(height);

    for (int y = 0; y < height; y++) {
        cells[y].resize(width);

        for (int x = 0; x < width; x++) {
            cells[y][x] = Cell::generator();
        }
    }
}

void Map::randomGenerate() {
    std::random_device rd;
    std::mt19937 gen(rd());

    std::uniform_real_distribution<float> elevationDist(-100.0f, 1000.0f);
    std::uniform_real_distribution<float> temperatureDist(-20.0f, 40.0f);
    std::uniform_real_distribution<float> rainfallDist(0.0f, 500.0f);

    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            Cell& cell = getCell(x, y);

            cell.setElevation(elevationDist(gen));
            cell.setTemperature(temperatureDist(gen));
            cell.setRainfall(rainfallDist(gen));
            cell.setHasWater(cell.getElevation() < 0.0f);
        }
    }
}

// Getters
int Map::getWidth() const {
    return width;
}

int Map::getHeight() const {
    return height;
}

Cell& Map::getCell(int x, int y) {
    return cells.at(y).at(x);
}

const Cell& Map::getCell(int x, int y) const {
    return cells.at(y).at(x);
}

// Setters
void Map::setWidth(int newWidth) {
    if (newWidth <= 0) {
        throw std::invalid_argument("Width must be positive");
    }

    width = newWidth;
    generate();
}

void Map::setHeight(int newHeight) {
    if (newHeight <= 0) {
        throw std::invalid_argument("Height must be positive");
    }

    height = newHeight;
    generate();
}