#pragma once

#include <vector>
#include "Cell.hpp"

class Map {
public:
    // Constructor
    Map(int width = 256, int height = 256);

    // Generator
    void generate();

    // Getters
    [[nodiscard]] int getWidth() const { return width; };
    [[nodiscard]] int getHeight() const { return height; };

    Cell& getCell(int x, int y);
    [[nodiscard]] const Cell& getCell(int x, int y) const;

    // Setters
    void setWidth(int Width) { this->width = Width; };
    void setHeight(int Height) {this->height = Height; };

    // Functions
    void printMap() const;

private:
    int width;
    int height;

    std::vector<std::vector<Cell>> cells;
};