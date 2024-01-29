#pragma once

#include <cstddef>
#include <cstdint>
#include <iostream>

#include "bus.h"

typedef unsigned char byte;

const uint16_t STACK_RESET = 0xFD;

class cpu {
  uint16_t pc; // program counter
  byte     s;  // stack pointer
  byte     a = 0;  // accumulator
  byte     x = 0;  // register x
  byte     y = 0;  // register y

  bus    mem;

  bool c = true; // carry
  bool z = true; // zero result
  bool i = true; // interupt disable
  bool d = true; // decimal mode
  bool b = true; // break
  bool v = true; // overflow
  bool n = true; // negative result

  // general functions
  void reset();
  void do_op();

  // mem function forwards
  byte& read(uint16_t address) { return mem.read(address); };
  uint16_t read16(uint16_t address) { return mem.read16(address); };
  byte& read_pc() { return mem.read(pc++); };
  uint16_t read_pc16() { 
    auto temp = mem.read16(pc);
    pc = pc + 2;
    return temp;
  };

  byte pop_stack() { return mem.read(--s); };
  uint16_t read_stack16() {
    --s;
    return read16(s--);
  };

  // flag checking functions
  void flagZero    (byte b);
  void flagNegative(byte b);
  void flagZN      (byte b);
  void flagCarry   (uint16_t val);

  // operations
  void ADC(byte  b);
  void AND(byte  b);
  void ASL(byte& b);
  void BIT(byte  b);
  void BCC(int8_t off);
  void BCS(int8_t off);
  void BEQ(int8_t off);
  void BMI(int8_t off);
  void BNE(int8_t off);
  void BPL(int8_t off);
  void BRK();
  void BVC(int8_t off);
  void BVS(int8_t off);
  void CLC();
  void CLD();
  void CLI();
  void CLV();
  void CMP(byte b);
  void CPX(byte b);
  void CPY(byte b);
  void DEC(byte& b);
  void DEX();
  void DEY();
  void EOR(byte b);
  void INC(byte& b);
  void INX();
  void INY();
  void JMP(uint16_t address);
  void JSR(uint16_t address);
  void LDA(byte b);
  void LDX(byte b);
  void LDY(byte b);
  void LSR(byte& b);
  void NOP();
  void ORA(byte b);
  void PHA();
  void PHP();
  void PLA();
  void PLP();
  void ROL(byte& b);
  void ROR(byte& b);
  void RTI();
  void RTS();
  void SBC(byte b);
  void SEC();
  void SED();
  void SEI();
  void STA(byte& b);
  void STX(byte& b);
  void STY(byte& b);
  void TAX();
  void TAY();
  void TSX();
  void TXA();
  void TXS();
  void TYA();

  // Addressing
  byte& accumulator();
  byte& immediate  ();
  byte& absolute   ();
  byte& zero_page  ();
  byte& zero_page_x();
  byte& zero_page_y();
  byte& absolute_x ();
  byte& absolute_y ();
  byte& indirect_x ();
  byte& indirect_y ();
  byte& relative   ();

  uint16_t absolute_address ();
  uint16_t indirect_address ();

public:

  cpu();

  void load(std::vector<byte> &program);

  template<typename T>
  void run(T callback);
};

