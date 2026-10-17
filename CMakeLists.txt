cmake_minimum_required(VERSION 3.20)

project(WorldGenerator LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(SDL3 REQUIRED CONFIG)

add_executable(WorldGenerator
        src/main.cpp

        src/terrain/TerrainGenerator.cpp

        src/rendering/SDLRenderer.cpp
        src/world.cpp
        include/world.h
        include/Cell.hpp
        src/Cell.cpp
        src/terrain/TerrainGenerator.cpp
        include/terrain/TerrainGenerator.h
        include/Cell.hpp
        include/Map.hpp
        src/Map.cpp
        include/rendering/SDLRenderer.hpp
)

target_include_directories(WorldGenerator PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)

target_link_libraries(WorldGenerator PRIVATE
        SDL3::SDL3
)

target_include_directories(WorldGenerator PRIVATE include)