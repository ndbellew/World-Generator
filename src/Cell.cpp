//
// Created by nathanbellew on 10/15/26.
//
#include "Cell.hpp"

// Getters

float Cell::getElevation() const {
    return elevation;
}

float Cell::getTemperature() const {
    return temperature;
}

float Cell::getRainfall() const {
    return rainfall;
}

bool Cell::getHasWater() const {
    return hasWater;
}

// Setters

void Cell::setElevation(float Elevation) {
    elevation = Elevation;
}

void Cell::setTemperature(float Temperature) {
    temperature = Temperature;
}

void Cell::setRainfall(float Rainfall) {
    rainfall = Rainfall;
}

void Cell::setHasWater(bool HasWater) {
    hasWater = HasWater;
}

Cell Cell::generator(
    float elevation,
    float temperature,
    float rainfall,
    bool hasWater) {
    Cell cell;
    cell.setElevation(elevation);
    cell.setTemperature(temperature);
    cell.setRainfall(rainfall);
    cell.setHasWater(hasWater);
    return cell;
}