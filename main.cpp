#include "Chip8.h"
#include <iostream>

int main() {
    Chip8 chip;
    chip.LoadROM("test.rom");  // this file can be any small binary
    std::cout << "ROM loaded!\n";
    return 0;
}
