#include "bus.h"

static int test_pointer = 10;

ZynNes::Core::Bus::Bus() {
    attachDevice(&test_pointer, 0);

    std::cout << &test_pointer << std::endl;
    std::cout << getDevice<int>(0) << std::endl;
}

template<typename T>
void ZynNes::Core::Bus::attachDevice(T* device, std::size_t idx) {
    static_assert(!std::is_void_v<T>, "Device type cannot be void");
    m_devices[idx] = device;
}

template<typename T>
T* ZynNes::Core::Bus::getDevice(std::size_t idx) {
    auto it = m_devices.find(idx);
    if (it == m_devices.end())
        return nullptr;

    if (it->second.type() != typeid(T*)) {
        throw std::bad_any_cast{};
    }

    return std::any_cast<T*>(it->second);
}

ZynNes::Core::u8 ZynNes::Core::Bus::read(u16 addr) {
    std::integral auto _addr = addr;

    if (addr >= 0x0000 && addr <= 0xFFFF) {
        return m_ram[addr];
    }

    return 0x00;
}

void ZynNes::Core::Bus::write(u16 addr, u8 data) {
    if (addr >= 0x0000 && addr <= 0xFFFF) {
        m_ram[addr] = data;
    }
}
