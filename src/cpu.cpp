#include "../include/cpu.h"

void cpu::reset() {

};

void cpu::do_op() {
  auto op = mem.read(pc++);
  switch (op) {


  }
}
