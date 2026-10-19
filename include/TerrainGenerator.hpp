//
// Created by nathanbellew on 10/15/26.
//

#pragma once

#include "Map.hpp"



class TerrainGenerator {
public:
    static void generate(Map& map, unsigned int seed);

private:
    static void addMountain(
      Map &map,
      int centerX,
      int centerY,
      float height,
      float radius
    );

};

