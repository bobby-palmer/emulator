#include "../include/cpu.h"

void cpu::reset() {

};

uint16_t cpu::get_address(addressMode m) {
  switch (m) {
    case immediate:
      return pc; 
    case absolute:
      return mem.read16(pc);
    case absX:
      return mem.read16(pc) + (uint16_t) x;
    case absY:
      return mem.read16(pc) + (uint16_t) y;
    case zeroPage:
      return mem.read(pc); 
    case zeroPageX:
      return ( mem.read(pc) + (uint16_t) x) & 0x00FF;
    case zeroPageY:
      return ( mem.read(pc) + (uint16_t) y) & 0x00FF;
    case indirectX:
      auto lsb = mem.read(pc) + (uint16_t) x;
      lsb &= 0x00FF;
      auto msb = (lsb + 1) & 0x00FF;
      return mem.read(msb) << 8 | mem.read(lsb);
    case indirectY:
      auto lsb = mem.read(pc) + (uint16_t) x;
      lsb &= 0x00FF;
      auto msb = (lsb + 1) & 0x00FF;
      return mem.read(msb) << 8 | mem.read(lsb);
  };
}
