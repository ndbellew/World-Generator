#!/usr/bin/env bash
set -euo pipefail

cmake -S . -B cmake-build-debug
cmake --build cmake-build-debug -j

exec ./cmake-build-debug/WorldGenerator "$@"