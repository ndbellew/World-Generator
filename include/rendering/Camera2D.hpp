//
// Created by kaladin on 10/18/26.
//

#pragma once
#include <algorithm>

class Camera2D {
public:
    // Constructors
    Camera2D() = default;
    Camera2D(float x, float y, float zoom);
    // Getters
    [[nodiscard]] float getX() const { return this->x; }
    [[nodiscard]] float getY() const { return this->y; }
    [[nodiscard]] float getZoom() const { return this->zoom; }

    // Setters
    void setX(float newX) { this->x = newX; }
    void setY(float newY) { this->y = newY; }
    void setZoom(float newZoom) {
        this->zoom = std::clamp(newZoom, 0.1f, 10.0f);
    }

    // Functions
    void reset();
    void move(float dx, float dy);
    void zoomAt(float zoomFactor, float mouseX, float mouseY);

private:
    float x = 0.0f;
    float y = 0.0f;
    float zoom = 1.0f;
};
