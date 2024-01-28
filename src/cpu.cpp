#include "../include/cpu.h"
#include <cstdlib>

// master do operation function
// will perform the operation at pc
void cpu::do_op() {
  auto op = read_pc();
  switch (op) {
    case 0x69: return ADC(immediate());
    case 0x65: return ADC(zero_page());
    case 0x75: return ADC(zero_page_x());
    case 0x6D: return ADC(absolute());
    case 0x7D: return ADC(absolute_x());
    case 0x79: return ADC(absolute_y());
    case 0x61: return ADC(indirect_x());
    case 0x71: return ADC(indirect_y());

    case 0x29: return AND(immediate());
    case 0x25: return AND(zero_page());
    case 0x35: return AND(zero_page_x());
    case 0x2D: return AND(absolute());
    case 0x3D: return AND(absolute_x());
    case 0x39: return AND(absolute_y());
    case 0x21: return AND(indirect_x());
    case 0x31: return AND(indirect_y());

    case 0x0A: return ASL(accumulator());
    case 0x06: return ASL(zero_page());
    case 0x16: return ASL(zero_page_x());
    case 0x0E: return ASL(absolute());
    case 0x1E: return ASL(absolute_x());

    case 0x90: return BCC(relative());
    case 0xB0: return BCS(relative());
    case 0xF0: return BEQ(relative());

    case 0x24: return BIT(zero_page());
    case 0x2C: return BIT(absolute());

    case 0x30: return BMI(relative());
    case 0xD0: return BNE(relative());
    case 0x10: return BPL(relative());
    case 0x00: return BRK();
    case 0x50: return BVC(relative());
    case 0x70: return BVS(relative());

    case 0x18: return CLC();
    case 0xD8: return CLD();
    case 0x58: return CLI();
    case 0xB8: return CLV();
  
    case 0xC9: return CMP(immediate());
    case 0xC5: return CMP(zero_page());
    case 0xD5: return CMP(zero_page_x());
    case 0xCD: return CMP(absolute());
    case 0xDD: return CMP(absolute_x());
    case 0xD9: return CMP(absolute_y());
    case 0xC1: return CMP(indirect_x());
    case 0xD1: return CMP(indirect_y());

    case 0xE0: return CPX(immediate());
    case 0xE4: return CPX(zero_page());
    case 0xEC: return CPX(absolute());

    case 0xC0: return CPY(immediate());
    case 0xC4: return CPY(zero_page());
    case 0xCC: return CPY(absolute());

    case 0xC6: return DEC(zero_page());
    case 0xD6: return DEC(zero_page_x());
    case 0xCE: return DEC(absolute());
    case 0xDE: return DEC(absolute_x());

    case 0xCA: return DEX();
    case 0x88: return DEY();

    case 0x49: return EOR(immediate());
    case 0x45: return EOR(zero_page());
    case 0x55: return EOR(zero_page_x());
    case 0x4D: return EOR(absolute());
    case 0x5D: return EOR(absolute_x());
    case 0x59: return EOR(absolute_y());
    case 0x41: return EOR(indirect_x());
    case 0x51: return EOR(indirect_y());

    case 0xE6: return INC(zero_page());
    case 0xF6: return INC(zero_page_x());
    case 0xEE: return INC(absolute());
    case 0xFE: return INC(absolute_x());

    case 0xE8: return INX();
    case 0xC8: return INY();

    case 0x4C: return JMP(abs);
    case 0x6C: return JMP(indirect);

    case 0x20: return JSR(abs);

    case 0xA9: return LDA(immediate());
    case 0xA5: return LDA(zero_page());
    case 0xB5: return LDA(zero_page_x());
    case 0xAD: return LDA(absolute());
    case 0xBD: return LDA(absolute_x());
    case 0xB9: return LDA(absolute_y());
    case 0xA1: return LDA(indirect_x());
    case 0xB1: return LDA(indirect_y());

    case 0xA2: return LDX(immediate());
    case 0xA6: return LDX(zero_page());
    case 0xB6: return LDX(zero_page_y());
    case 0xAE: return LDX(absolute());
    case 0xBE: return LDA(absolute_y());

    case 0xA0: return LDY(immediate());
    case 0xA4: return LDY(zero_page());
    case 0xB4: return LDY(zero_page_x());
    case 0xAC: return LDY(absolute());
    case 0xBC: return LDY(absolute_x());

    case 0x4A: return LSR(accumulator());
    case 0x46: return LSR(zero_page());
    case 0x56: return LSR(zero_page_x());
    case 0x4E: return LSR(absolute());
    case 0x5E: return LSR(absolute_x());

    case 0xEA: return NOP();

    case 0x09: return ORA(immediate());
    case 0x05: return ORA(zero_page());
    case 0x15: return ORA(zero_page_x());
    case 0x0D: return ORA(absolute());
    case 0x1D: return ORA(absolute_x());
    case 0x19: return ORA(absolute_y());
    case 0x01: return ORA(indirect_x());
    case 0x11: return ORA(indirect_y());

    case 0x48: return PHA();
    
    case 0x08: return PHP();

    case 0x68: return PLA();

    case 0x28: return PLP();

    case 0x2A: return ROL(accumulator());
    case 0x26: return ROL(zero_page());
    case 0x36: return ROL(zero_page_x());
    case 0x2E: return ROL(absolute());
    case 0x3E: return ROL(absolute_x());

    case 0x6A: return ROR(accumulator());
    case 0x66: return ROR(zero_page());
    case 0x76: return ROR(zero_page_x());
    case 0x6E: return ROR(absolute());
    case 0x7E: return ROR(absolute_x());

    case 0x40: return RTI();

    case 0x60: return RTS();

    case 0xE9: return SBC(immediate());
    case 0xE5: return SBC(zero_page());
    case 0xF5: return SBC(zero_page_x());
    case 0xED: return SBC(absolute());
    case 0xFD: return SBC(absolute_x());
    case 0xF9: return SBC(absolute_y());
    case 0xE1: return SBC(indirect_x());
    case 0xF1: return SBC(indirect_y());

    case 0x38: return SEC();
    
    case 0xF8: return SED();
    
    case 0x78: return SEI();

    case 0x85: return STA(zero_page());
    case 0x95: return STA(zero_page_x());
    case 0x8D: return STA(absolute());
    case 0x9D: return STA(absolute_x());
    case 0x99: return STA(absolute_y());
    case 0x81: return STA(indirect_x());
    case 0x91: return STA(indirect_y());

    case 0x86: return STX(zero_page());
    case 0x96: return STX(zero_page_y());
    case 0x8E: return STX(absolute());

    case 0x84: return STY(zero_page());
    case 0x94: return STY(zero_page_x());
    case 0x8c: return STY(absolute());

    case 0xAA: return TAX();

    case 0xA8: return TAY();

    case 0xBA: return TSX();

    case 0x8A: return TXA();

    case 0x9A: return TXS();

    case 0x98: return TYA();

    default:
      std::fprintf(stderr, "ERROR: opcode %.4x is not implemented\n", op);
      std::exit(1); 
  };
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
  b = stat & (0 << 4);
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
