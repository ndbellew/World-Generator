#include "rendering/SDLRenderer.hpp"

#include <stdexcept>

// Constructor
SDLRenderer::SDLRenderer(int width, int height)
    : width(width), height(height) {
}

// Destructor
SDLRenderer::~SDLRenderer() {
    if (renderer) {
        SDL_DestroyRenderer(renderer);
    }

    if (window) {
        SDL_DestroyWindow(window);
    }

    SDL_Quit();
}

// Initialize SDL3
bool SDLRenderer::initialize() {
    if (!SDL_Init(SDL_INIT_VIDEO)) {
        SDL_Log("SDL initialization failed: %s", SDL_GetError());
        return false;
    }

    if (!SDL_CreateWindowAndRenderer(
        "WorldGenerator",
        width,
        height,
        SDL_WINDOW_RESIZABLE,
        &window,
        &renderer
    )) {
        SDL_Log("Window creation failed: %s", SDL_GetError());
        return false;
    }

    return true;
}

// Main application loop
void SDLRenderer::run(const Map& map) {
    running = true;

    while (running) {
        SDL_Event event;

        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_EVENT_QUIT) {
                running = false;
            }

            if (event.type == SDL_EVENT_KEY_DOWN &&
                event.key.key == SDLK_ESCAPE) {
                running = false;
            }
        }

        drawMap(map);
    }
}

// Render the map
void SDLRenderer::drawMap(const Map& map) {
    if (!renderer) {
        return;
    }

    SDL_SetRenderDrawColor(renderer, 20, 20, 20, 255);
    SDL_RenderClear(renderer);

    // Use current window dimensions so resizing works
    int renderWidth = 0;
    int renderHeight = 0;

    if (!SDL_GetRenderOutputSize(renderer, &renderWidth, &renderHeight)) {
        return;
    }

    float cellWidth =
        static_cast<float>(renderWidth) / map.getWidth();

    float cellHeight =
        static_cast<float>(renderHeight) / map.getHeight();

    for (int y = 0; y < map.getHeight(); y++) {
        for (int x = 0; x < map.getWidth(); x++) {

            const Cell& cell = map.getCell(x, y);

            float elevation = cell.getElevation();

            // Simple elevation-based coloring
            if (elevation < 0.0f) {
                // Water
                SDL_SetRenderDrawColor(renderer, 30, 80, 180, 255);
            }
            else if (elevation < 200.0f) {
                // Lowlands
                SDL_SetRenderDrawColor(renderer, 40, 150, 60, 255);
            }
            else if (elevation < 600.0f) {
                // Highlands
                SDL_SetRenderDrawColor(renderer, 140, 110, 70, 255);
            }
            else {
                // Mountains
                SDL_SetRenderDrawColor(renderer, 230, 230, 230, 255);
            }

            SDL_FRect rect = {
                x * cellWidth,
                y * cellHeight,
                cellWidth,
                cellHeight
            };

            SDL_RenderFillRect(renderer, &rect);
        }
    }

    SDL_RenderPresent(renderer);
}