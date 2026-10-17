//
// Created by nathanbellew on 10/15/26.
//
#ifndef UNTITLED_CELL_H
#define UNTITLED_CELL_H

#endif //UNTITLED_CELL_H

#pragma once

class Cell {
public:
    // Generator
    static Cell generator(
        float elevation = 1.0f,
        float temperature = 15.0f,
        float rainFall = 0.0f,
        bool hasWater = false
    );
    Cell() = default;

    // Getters
    [[nodiscard]] float getElevation() const;
    [[nodiscard]] float getTemperature() const;
    [[nodiscard]] float getRainfall() const;
    [[nodiscard]] bool getHasWater() const;

    // Setters
    void setElevation(float Elevation);
    void setTemperature(float Temperature);
    void setRainfall(float Rainfall);
    void setHasWater(bool HasWater);


private:
    float elevation = 0.0f;
    float temperature = 20.0f;
    float rainfall = 0.0f;
    bool hasWater = false;


};
