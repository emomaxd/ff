cmake_minimum_required(VERSION 3.8)

project(flog-root)

# Set the C++ standard for the whole project
set(CMAKE_CXX_STANDARD 17)

# Enable debug symbols for Debug build type
set(CMAKE_CXX_FLAGS_DEBUG "-g -O0")  # No optimizations for debugging

# Set flags for Release build type (high optimization, link-time optimization)
set(CMAKE_CXX_FLAGS_RELEASE "-O3 -flto -march=native")

# Enable common warning flags for all builds
add_compile_options(-Wall -Wextra -Wpedantic)

# Optionally set the default build type to Debug
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Debug CACHE STRING "Choose the build type" FORCE)
endif()

# Include the subdirectories
add_subdirectory(src)
add_subdirectory(tester)

# Set the output directories for libraries and binaries
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)
