#include "../include/cpu.h"

void cpu::reset() {

};

// Flag commands
// set carry flag
void cpu::SEC() { c = true; };
// clear carry flag
void cpu::CLC() { c = false; };
// clear overflow flag
void cpu::CLV() { v = false; };
// set interupt disable flag
void cpu::SEI() { i = true; };
// clear interupt disable flag
void cpu::CLI() { i = false; };
// set decimal mode
void cpu::SED() { d = true; };

// ops for transfering data
// load accumulator with memory
void cpu::LDA(byte b) {
  flagZero(b);
  flagNegative(b);
  a = b;
};
// load index register x from memory
void cpu::LDX(byte b) {
  flagZero(b);
  flagNegative(b);
  x = b;
};
// load index regiuster y from memory
void cpu::LDY(byte b) {
  flagZero(b);
  flagNegative(b);
  y = b;
};
// store accumulator in memory
void cpu::STA(byte& b) { b = a; };
// store regiuster x in memory
void cpu::STX(byte& b) { b = x; };
// store register y in memory
void cpu::STY(byte& b) { b = y; };
// transfer accumulator to regsiter x
void cpu::TAX() {
  flagZN(a);
  x = a;
};
// transfer accumulator to register y
void cpu::TAY() {
  flagZN(a);
  y = a;
};
// transfer x to accumulator
void cpu::TXA() {
  flagZN(x);
  a = x;
};
// transfer y to accumulator
void cpu::TYA() {
  flagZN(y);
  a = y;
};
// transfer reg x to the stack pointer
void cpu::TXS() { s = x; };
// transfer stack pointer to the reg x
void cpu::TSX() { x = s; };

// add/sub functions
// add with carry
void cpu::ADC(byte b) {
  uint16_t sum = a + b + c;
  flagCarry(sum); 
  flagZN(sum);
  v = ~(a ^ b) & (a ^ sum) & 0x80; // flag on overflow
  a = sum;
};
// sub with borrow
void cpu::SBC(byte b) {
  ADC(~b + 1);
};

// bitwise
// and memory with accumulator
void cpu::AND(byte b) {
  a &= b;
  flagZN(a);
};
// or memory with accumulator
void cpu::ORA(byte b) {
  a |= b;
  flagZN(a);
}
// exclusive or memory with accumulator
void cpu::EOR(byte b) {
  a ^= b;
  flagZN(a);
}
