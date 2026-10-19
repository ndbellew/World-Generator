//
// Created by kaladin on 10/18/26.
//

#include "Camera2D.hpp"
#include <algorithm>


// Constructor
Camera2D::Camera2D(float x, float y, float zoom)
    : x(x), y(y), zoom(std::clamp(zoom, 0.1f, 10.0f)) {
}

// Reset
void Camera2D::reset() {
    this->x = 0.0f;
    this->y = 0.0f;
    this->zoom = 1.0f;
}

// Move
void Camera2D::move(float dx, float dy) {
    this->x += dx;
    this->y += dy;
}

// Zoom toward mouse
void Camera2D::zoomAt(
    float zoomFactor,
    float mouseX,
    float mouseY
) {
    const float oldZoom = this->zoom;

    // Apply zoom limits
    this->zoom = std::clamp(
        this->zoom * zoomFactor,
        0.1f,
        10.0f
    );

    const float ratio = this->zoom / oldZoom;

    // Keep the world position under the mouse fixed
    this->x = mouseX - (mouseX - this->x) * ratio;
    this->y = mouseY - (mouseY - this->y) * ratio;
}