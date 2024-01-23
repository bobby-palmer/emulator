#pragma once

enum op {

};

enum addressMode {
  imp,
  acc,
  imm,
  abs,
  abx,
  aby,
  ind,
  zpg,
  zpx,
  zpy,
  inx,
  iny,
  rel,
  ill,
};

const addressMode mode_loopup[] = {
//  0    1    2    3    4    5    6    7    8    9    A    B    C    D    E    F
  imp, ind, ill, ill, ill, zpg, zpg, ill, imp, imm, acc, ill, ill, abs, abs, ill,//0
};

enum operation {
  ADC, AND, ASL, BCC, BCS, BEQ, BIT, BMI, BNE, BPL, BRK, BVC, BVS, CLC,
  CLD, CLI, CLV, CMP, CPX, CPY, DEC, DEX, DEY, EOR, INC, INX, INY, JMP,
  JSR, LDA, LDX, LDY, LSR, NOP, ORA, PHA, PHP, PLA, PLP, ROL, ROR, RTI,
  RTS, SBC, SEC, SED, SEI, STA, STX, STY, TAX, TAY, TSX, TXA, TXS, TYA,
  ILL
};

const operation op_lookup[] = {
//  0    1    2    3    4    5    6    7    8    9    A    B    C    D    E    F
  BRK, ORA, ILL, ILL, ILL, ORA, ASL, ILL, PHP, ORA, ASL, ILL, ILL, ORA, ASL, ILL, // 0
  BPL, ORA, ILL, ILL, ILL, ORA, ASL, ILL, CLC, ORA, ILL, ILL, ILL, ORA, ASL, ILL, // 1

};

