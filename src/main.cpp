#include <iostream>

/**
 * @brief main emulator include
 */
#include "core/bus.h"
#include "core/nes.h"

using namespace ZynNes::Core;

int main() {
    // const expert evaluation for optimizations
    Nes nes;

    try {
        nes.run();
    } catch (std::exception& err) {
        std::cerr << err.what();
    }

    // run emulator
    return EXIT_SUCCESS;
}