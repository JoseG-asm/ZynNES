#pragma once

#include "nes.h"

namespace ZynNes::Core {
    class Bus;
}

namespace ZynNes::Core {
    class Cpu {
    public:
        Cpu(Bus* bus);

    private:
        // registers
        /**
         * @see https://www.nesdev.org/wiki/CPU_registers
         */
        u8 acc{0x00};
        u8 x{0x00};
        u8 y{0x00};
        u8 stack_pointer{0x00};
        u16 pc{0x0000};
        u8 status{0x0000};

        // cpu flags
        /**
         * @see https://www.nesdev.org/wiki/Status_flags
         */
        enum Flags
        {
            C = (1 << 0),	// Carry Bit
            Z = (1 << 1),	// Zero
            I = (1 << 2),	// Disable Interrupts
            D = (1 << 3),	// Decimal Mode
            B = (1 << 4),	// Break
            U = (1 << 5),	// Unused
            V = (1 << 6),	// Overflow
            N = (1 << 7),	// Negative
        };
    };
}