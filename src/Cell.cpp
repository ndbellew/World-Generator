//
// Created by nathanbellew on 10/15/26.
//
#include "Cell.hpp"

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