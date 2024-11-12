# ff - fast-format

**ff** is a lightweight header-only C++ library designed to formatting strings. Customize outputs easily with placeholders and specifiers for decimal, hex, octal, binary, scientific, and more.

### Usage
No need to build, just put ff.h into your project's include directory and you are ready to go!

### Building
In case if you want to build the library
```bash
mkdir build && cd build
cmake .. && make
```
And you can link with the static library in build/src/ named as ff

### Example
```cpp
std::string result = ff::format("Decimal: {}, Hex: {0:x}, Binary: {b}", 255, 15);
std::cout << result; // Output: Decimal: 255, Hex: 0xFF, Binary: 0b1111

    
std::string result1 = ff::format("Pi: {.2}, Scientific: {s}", 3.14159f, 1000.0f);
std::cout << result1; // Output: Pi: 3.14, Scientific, 1.000000e+03
```