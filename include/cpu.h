#pragma once

#include <cstddef>
#include <cstdint>
#include <iostream>

#include "bus.h"

using std::byte;

enum addressMode {
  immediate,
  zeroPage,
  zeroPageX,
  zeroPageY,
  absolute,
  absX,
  absY,
  indirectX,
  indirectY,
};

class cpu {
  uint16_t pc;
  byte status;
  byte     sp;
  byte      a;
  byte      x;
  byte      y;
  bus&    mem;
public:

  void reset();

  uint16_t get_address(addressMode m);
};
