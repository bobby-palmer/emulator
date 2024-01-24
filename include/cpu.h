#pragma once

#include <cstddef>
#include <cstdint>
#include <iostream>

#include "bus.h"

typedef unsigned char byte;

class cpu {
  uint16_t pc; // program counter
  byte     s;  // stack pointer
  byte     a;  // accumulator
  byte     x;  // register x
  byte     y;  // register y

  bus&    mem;

  bool c; // carry
  bool z; // zero result
  bool i; // interupt disable
  bool d; // decimal mode
  bool b; // break
  bool v; // overflow
  bool n; // negative result

  // general functions
  void reset();

  // operations
  void ADC(byte  arg);
  void AND(byte  arg);
  void ASL(byte& arg);
  void BIT(byte  arg);
  void BCC(uint16_t arg);
  void BCS();
  void BEQ();
  void BMI();
  void BNE();
  void BPL();
  void BRK();
  void BVC();
  void BVS();
  void CLC();
  void CLD();
  void CLI();
  void CLV();
  void CMP();
  void CPX();
  void CPY();
  void DEC();
  void DEX();
  void DEY();
  void EOR();
  void INC();
  void INX();
  void INY();
  void JMP();
  void JSR();
  void LDA();
  void LDX();
  void LDY();
  void LSR();
  void NOP();
  void ORA();
  void PHA();
  void PHP();
  void PLA();
  void PLP();
  void ROL();
  void ROR();
  void RTI();
  void RTS();
  void SBC();
  void SEC();
  void SED();
  void SEI();
  void STA();
  void STX();
  void STY();
  void TAX();
  void TAY();
  void TSX();
  void TXA();
  void TXS();
  void TYA();

  // Addressing


  // flag setting

public:
};

