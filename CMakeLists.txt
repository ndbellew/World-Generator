cmake_minimum_required(VERSION 3.20)

project(WorldGenerator LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(SDL3 REQUIRED CONFIG)

add_executable(WorldGenerator
        src/main.cpp
        src/world.cpp
        src/Cell.cpp
        src/Map.cpp
        src/TerrainGenerator.cpp
        src/rendering/SDLRenderer.cpp
        src/rendering/Camera2D.cpp
        include/world.h
        include/Cell.hpp
        include/Map.hpp
        include/TerrainGenerator.hpp
        include/rendering/SDLRenderer.hpp
        include/rendering/Camera2D.hpp
)

target_include_directories(WorldGenerator PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/include
        ${CMAKE_CURRENT_SOURCE_DIR}/include/rendering
)

target_link_libraries(WorldGenerator PRIVATE
        SDL3::SDL3
)

target_include_directories(WorldGenerator PRIVATE include)