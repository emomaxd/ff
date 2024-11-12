#include "ff.h"
#include <iostream>

int main() {
    // Format integers
    std::cout << ff::format("Decimal: {1}, Hex: {X}, Binary: {1:b}", 42, 255, 0) << std::endl;

    // Format floating-point numbers with precision
    std::cout << ff::format("Pi: {.2}, Scientific: {s}", 3.14159f, 1000.0f) << std::endl;

    return 0;
}
