cmake_minimum_required(VERSION 3.12)
project(tree_shared_module VERSION 1.0 LANGUAGES CXX)

# Force modern C++ standards required for std::shared_ptr and pybind11
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# -----------------------------------------------------------------------------
# 1. Locate the local pybind11 installation
# -----------------------------------------------------------------------------
# This looks for pybind11Config.cmake on your system path, in your active 
# python environment, or inside your local build/package tools.
find_package(pybind11 REQUIRED)

# -----------------------------------------------------------------------------
# 2. Define the Python extension module
# -----------------------------------------------------------------------------
# This creates a shared library named 'tree_shared_module' with correct extension
# flags for Python (e.g., .so on Linux/macOS, .pyd on Windows)
pybind11_add_module(tree_shared_module tree_shared.cpp)

# Forces CMake to output the compiled module in the root of your project directory
set_target_properties(tree_shared_module PROPERTIES
    LIBRARY_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}"
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}"
)

