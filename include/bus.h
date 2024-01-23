#pragma once

#include <cstddef>
#include <cstdint>
using std::byte;

class bus {

  byte a[0xFFFF];

public:
  
  uint16_t read (uint16_t address);
  void write(uint16_t address);

  uint16_t read16 (uint16_t address);
  void     write16(uint16_t address);
};
