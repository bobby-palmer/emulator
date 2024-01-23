#pragma once

#include <cstddef>
#include <cstdint>
#include <iostream>

#include "bus.h"

using std::byte;

class cpu {
  uint16_t pc;
  byte     sp;
  byte      a;
  byte      x;
  byte      y;

  bus&    mem;

  bool c;
  bool z;
  bool i;
  bool d;
  bool b;
  bool v;
  bool n;

public:

  void reset();

  void do_op();
};
