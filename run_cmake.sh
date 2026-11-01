#!/usr/bin/bash
# 1. Generate build files in a temporary 'build' directory
cmake -S . -B build -DCMAKE_BUILD_TYPE=Releasei -Wno-dev

# 2. Compile the binary module
cmake --build build --config Release 

rm -rf build
