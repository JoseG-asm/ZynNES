#pragma once


#include "nes.h"

namespace ZynNes::Core {

    class Bus {
    public:
        Bus();

        template<typename T>
        void attachDevice(T* device, std::size_t idx);

        template<typename T>
        T* getDevice(std::size_t idx);

        u8 read(u16 addr);
        void write(u16 addr, u8 data);

    private:
        /**
         * devices on the bus
         */
        // fake ram
        std::array<u16, 64 * 1024> m_ram{};

        std::unordered_map<std::size_t, std::any> m_devices;
    };
}
