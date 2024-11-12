cmake_minimum_required(VERSION 3.8)

project(ff)

# Set the C++ standard
set(CMAKE_CXX_STANDARD 17)

# Enable debugging symbols in Debug mode
set(CMAKE_CXX_FLAGS_DEBUG "-g -O0")  # Disable optimization for debugging

# Enable optimizations and other flags for Release mode
set(CMAKE_CXX_FLAGS_RELEASE "-O3 -flto -march=native")

# Enable Wall, Wextra, Wpedantic for all builds (not conditional on Debug/Release)
add_compile_options(-Wall -Wextra -Wpedantic)

# Include all source and header files in the src directory recursively
file(GLOB_RECURSE SRC
    ${CMAKE_SOURCE_DIR}/src/*.cpp
    ${CMAKE_SOURCE_DIR}/src/*.c
)

# Add a static library target
add_library(ff STATIC ${SRC})

# Link math library
target_link_libraries(ff m)

# Set the output directories for the compiled files
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)

# Optionally, set a default build type if it's not specified
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Debug CACHE STRING "Choose the build type" FORCE)
endif()
