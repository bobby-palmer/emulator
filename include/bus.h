#pragma once

#include <cstddef>
#include <cstdint>
typedef unsigned char byte;

class bus {

  byte a[0xFFFF];

public:
  
  byte read (uint16_t address);
  void write(uint16_t address, byte value);

  uint16_t read16 (uint16_t address);
};
