#include "../include/cpu.h"

// master do operation function
// will perform the operation at pc
void cpu::do_op() {
  switch (mem.read(pc++)) {
    case 0x69: return ADC(immediate());
    case 0x65: return ADC(zero_page());
    case 0x75: return ADC(zero_page_x());
    case 0x6D: return ADC(absolute());
    case 0x7D: return ADC(absolute_x());
    case 0x79: return ADC(absolute_y());
    case 0x61: return ADC(indirect_x());
    case 0x71: return ADC(indirect_y());
  }
};

const uint16_t RESET_VECTOR = 0xFFFC;
const uint16_t BRK_VECTOR = 0xFFFE;

void cpu::reset() {
  i = true;
  pc = mem.read16(RESET_VECTOR);
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
  flagZN(b);
  a = b;
};
// load index register x from memory
void cpu::LDX(byte b) {
  flagZN(b);
  x = b;
};
// load index regiuster y from memory
void cpu::LDY(byte b) {
  flagZN(b);
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
};
// exclusive or memory with accumulator
void cpu::EOR(byte b) {
  a ^= b;
  flagZN(a);
};

// increment and decremement
// increment x
void cpu::INX() {
  ++x;
  flagZN(x);
};
// increment y
void cpu::INY() {
  ++y;
  flagZN(y);
};
void cpu::DEX() {
  --x;
  flagZN(x);
};
void cpu::DEY() {
  --y;
  flagZN(y);
};
// increment memory
void cpu::INC(byte& b) {
  ++b;
  flagZN(b);
};
void cpu::DEC(byte& b) {
  --b;
  flagZN(b);
};

// byte comparisons
// compare memory with acc
void cpu::CMP(byte b) {
  c = a >= b;
  byte sub = a - b;
  flagZN(sub);
};
void cpu::CPX(byte b) {
  c = x >= b;
  byte sub = x - b;
  flagZN(sub);
};
void cpu::CPY(byte b) {
  c = y >= b;
  byte sub = y - b;
  flagZN(sub);
};

// bit manip
// test and of acc and byte
void cpu::BIT(byte b) {
  byte t = a & b;
  flagZN(t);
  v = t & (1 << 6);
};
// right shift
void cpu::LSR(byte& b) {
  c = b & 0x01;
  b >>= 1;
  flagZN(b);
};
// left shift
void cpu::ASL(byte& b) {
  c = b & 0x80;
  b <<= 1;
  flagZN(b);
};
// rotate left
void cpu::ROL(byte& b) {
  bool new_carry = b & 0x80;
  b <<= 1;
  b |= c;
  c = new_carry;
  flagZN(b);
};
// rotate right
void cpu::ROR(byte& b) {
  bool new_carry = b & 0x01;
  b >>= 1;
  b |= (byte(c) << 7);
  c = new_carry;
};

// branching
// jump to new location
void cpu::JMP(uint16_t address) {
  pc = address;
};
// branch minus
void cpu::BMI(int8_t off) {
  if (n) pc += off;
};
void cpu::BPL(int8_t off) {
  if (!n) pc += off;
};
void cpu::BVS(int8_t off) {
  if (v) pc += off;
};
void cpu::BVC(int8_t off) {
  if (!v) pc += off;
};
void cpu::BCS(int8_t off) {
  if (c) pc += off;
};
void cpu::BCC(int8_t off) {
  if (!c) pc += off;
};
void cpu::BEQ(int8_t off) {
  if (z) pc += off;
};
void cpu::BNE(int8_t off) {
  if (!z) pc += off;
};

// call stack managment
// jump and save return addy
void cpu::JSR(uint16_t address) {
  --s;
  mem.write16(s, pc);
  --s;
  pc = address;
};
// return
void cpu::RTS() {
  ++s;
  pc = mem.read16(s);
  ++s;
};
void cpu::PHA() {
  mem.write(s, a);
  --s;
};
void cpu::PHP() {
  byte status = (
    c * 1 +
    z * (1 << 1) +
    i * (1 << 2) +
    d * (1 << 3) +
    b * (1 << 4) +
    v * (1 << 6) +
    n * (1 << 7)
  );
  mem.write(s, status);
  --s;
};
void cpu::PLA() {
  --s;
  a = mem.read(s);
};
void cpu::PLP() {
  --s;
  byte stat = mem.read(s);
  c = stat & 1;
  z = stat & (1 << 1);
  i = stat & (1 << 2);
  d = stat & (1 << 3);
  b = stat & (1 << 4);
  v = stat & (1 << 6);
  n = stat & (1 << 7);
};

// interupt
void cpu::RTI() {
  PLP();
  RTS();
};
void cpu::BRK() {
  --s;
  mem.write16(s, pc);
  --s;
  PHP();
  pc = mem.read16(BRK_VECTOR);
  i = true;
};
void cpu::NOP() {  };
