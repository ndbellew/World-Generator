#pragma once

#include <vector>
#include "Cell.hpp"

class Map {
public:
    // Constructor
    Map(int width = 256, int height = 256);

    // Generator
    void generate();
    void randomGenerate();
    // Getters
    int getWidth() const;
    int getHeight() const;

    Cell& getCell(int x, int y);
    const Cell& getCell(int x, int y) const;

    // Setters
    void setWidth(int width);
    void setHeight(int height);

private:
    int width;
    int height;

    std::vector<std::vector<Cell>> cells;
};