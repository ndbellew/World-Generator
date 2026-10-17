#pragma once

#include <SDL3/SDL.h>
#include "Map.hpp"

class SDLRenderer {
public:
    SDLRenderer(int width = 1024, int height = 768);
    ~SDLRenderer();

    bool initialize();
    void run(const Map& map);
    void drawMap(const Map& map);

private:
    int width;
    int height;

    SDL_Window* window = nullptr;
    SDL_Renderer* renderer = nullptr;

    bool running = false;
};