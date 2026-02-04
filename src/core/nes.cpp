
#include "nes.h"

#include "core/bus.h"

ZynNes::Core::Nes::Nes() {
    m_bus = std::make_unique<Bus>();
};

void ZynNes::Core::Nes::run() {

}

