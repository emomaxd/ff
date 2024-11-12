cmake_minimum_required(VERSION 3.8)

project(tester)

# Set the C++ standard
set(CMAKE_CXX_STANDARD 17)

# Enable debug symbols in Debug mode
set(CMAKE_CXX_FLAGS_DEBUG "-g -O0")  # No optimizations, debug symbols

# Enable optimizations and other flags for Release mode
set(CMAKE_CXX_FLAGS_RELEASE "-O3 -flto -march=native")

# Enable common warnings for all builds
add_compile_options(-Wall -Wextra -Wpedantic)

# Include all source and header files in the tester directory
file(GLOB_RECURSE SRC
    ${CMAKE_SOURCE_DIR}/tester/*.cpp
    ${CMAKE_SOURCE_DIR}/tester/*.h
)

# Add an executable target for the tester
add_executable(tester ${SRC})

# Include the headers from the 'src' directory where the 'ff' library's header files are
target_include_directories(tester PRIVATE
    ${CMAKE_SOURCE_DIR}/src
)

# Link the tester to the static library 'ff' and the math library
target_link_libraries(tester
    m
    ff  # The static library 'ff' built in the 'lib' directory
)

# Set output directories for the compiled files
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)

# Optionally, set a default build type if none is specified
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Debug CACHE STRING "Choose the build type" FORCE)
endif()
