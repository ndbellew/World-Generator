#pragma once

#include <vector>
#include "Cell.hpp"

class Map {
public:
    // Constructor
    Map(int width = 256, int height = 256);

    // Generator
    void generate();
    // void randomGenerate();
    // Getters
    [[nodiscard]] int getWidth() const;
    [[nodiscard]] int getHeight() const;

    Cell& getCell(int x, int y);
    [[nodiscard]] const Cell& getCell(int x, int y) const;

    // Setters
    void setWidth(int width);
    void setHeight(int height);

    // Functions
    void printMap() const;

private:
    int width;
    int height;

    std::vector<std::vector<Cell>> cells;
};