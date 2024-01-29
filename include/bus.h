#pragma once

#include <cstddef>
#include <cstdint>
#include <vector>
typedef unsigned char byte;

class bus {

  byte a[0xFFFF];

public:

  bus();
  
  byte& read (uint16_t address) { return a[address]; };
  void write(uint16_t address, byte value) { a[address] = value; };

  uint16_t read16 (uint16_t address);
  void write16    (uint16_t address, uint16_t value);
  void copy(std::vector<byte> &program, uint16_t start);
};
