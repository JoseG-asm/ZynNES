#pragma once

// STL
#include <cstdint>
#include <array>
#include <iostream>
#include <unordered_map>
#include <variant>
#include <any>
#include <memory>

// forward declarations
namespace ZynNes::Core {
    class Bus;
    class Cpu;
}

namespace ZynNes::Core {
    /**
     * typedefs
     */
    using u16 = uint16_t;
    using u8 = uint8_t;

    class Nes {
    public:
        Nes();
        ~Nes();

        void run();
    private:
        std::unique_ptr<Bus> m_bus;
        std::unique_ptr<Cpu> m_cpu;
    };
}
