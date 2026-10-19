#pragma once

#include <SDL3/SDL.h>
#include "Map.hpp"
#include "Camera2D.hpp"

class SDLRenderer {
public:
    SDLRenderer(int width, int height);
    ~SDLRenderer();

    bool initialize();
    void run(const Map& map);
    void drawMap(const Map& map);

private:
    Camera2D camera;
    bool dragging = false;
    float baseCellSize = 4.0f;
    int width = 1024;
    int height = 768;

    SDL_Window* window = nullptr;
    SDL_Renderer* renderer = nullptr;

    bool running = false;
};