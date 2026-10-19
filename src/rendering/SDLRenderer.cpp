#include "SDLRenderer.hpp"

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
    this->running = true;

    while (running) {
        SDL_Event event;

        while (SDL_PollEvent(&event)) {
            switch (event.type) {
                case SDL_EVENT_QUIT:
                    this->running = false;
                    break;

                case SDL_EVENT_KEY_DOWN:
                    if (event.key.key == SDLK_ESCAPE) {
                        this->running = false;
                    }
                    if (event.key.key == SDLK_R) {
                        camera.reset();
                    }
                    break;

                case SDL_EVENT_MOUSE_BUTTON_DOWN:
                    if (event.button.button == SDL_BUTTON_LEFT) {
                        this->dragging = true;
                    }
                    break;

                case SDL_EVENT_MOUSE_BUTTON_UP:
                    if (event.button.button == SDL_BUTTON_LEFT) {
                        this->dragging = false;
                    }
                    break;

                case SDL_EVENT_MOUSE_MOTION:
                    if (this->dragging) {
                        camera.move(event.motion.xrel, event.motion.yrel);
                    }
                    break;

                case SDL_EVENT_MOUSE_WHEEL:
                    if (event.wheel.y != 0.0f) {
                        float mouseX, mouseY;
                        SDL_GetMouseState(&mouseX, &mouseY);

                        float factor = event.wheel.y > 0 ? 1.1f : 0.9f;

                        camera.zoomAt(factor, mouseX, mouseY);
                    }
                    break;

                default:
                    break;
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

    const float cellSize = baseCellSize * camera.getZoom();

    for (int y = 0; y < map.getHeight(); y++) {
        for (int x = 0; x < map.getWidth(); x++) {

            const Cell& cell = map.getCell(x, y);

            float elevation = cell.getElevation();

            // Simple elevation-based coloring
            if (elevation <= 0.0f) {
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
                camera.getX() + x * cellSize,
                camera.getY() + y * cellSize,
                cellSize,
                cellSize
            };
            // if (rect.x + rect.w <= 0.0f ||
            //     rect.y + rect.h <= 0.0f ||
            //     rect.x >= static_cast<float>(renderWidth) ||
            //     rect.y >= static_cast<float>(renderHeight))  { continue; }
            SDL_RenderFillRect(renderer, &rect);
        }
    }

    SDL_RenderPresent(renderer);
}