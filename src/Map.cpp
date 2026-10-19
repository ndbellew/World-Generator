//
// Created by nathanbellew on 10/17/26.
//
#include "Map.hpp"
#include <iostream>
#include <iomanip>
#include <ios>
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

Cell& Map::getCell(int x, int y) {
    return cells.at(y).at(x);
}

const Cell& Map::getCell(int x, int y) const {
    return cells.at(y).at(x);
}

void Map::printMap() const {
    for (int y=0; y < height; y++) {
        for (int x=0; x < width; x++) {
            std::cout << std::setw(10)
                      << std::fixed
                      << std::setprecision(2)
                      << getCell(x,y).getElevation();
        }
        std::cout << "\n";
    }
}