#include "../include/bus.h"
#include <cstdint>
uint16_t bus::read16(uint16_t address) {
  return a[address] + (a[address + 1] << 8);
};

void bus::write16(uint16_t address, uint16_t value) {
  a[address] = 0xFF & value;
  a[address + 1] = (value >> 8);
};

void bus::copy(std::vector<byte> &program, uint16_t start) {
  std::copy(program.begin(), program.end(), a + start);
};
