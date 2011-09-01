// -*- C++ -*-

#ifndef _TYTHON_INSTRUCTION_H_
#define _TYTHON_INSTRUCTION_H_

#include <string>

using std::string;

typedef struct Instruction {
public:
    Instruction(void) {}
    Instruction(std::string _s) : op(_s), arg(NULL) {}
    Instruction(std::string _s, int _v) : op(_s), arg(_v) {}

    std::string op;
    int arg;
} Instruction;

#endif // _TYTHON_INSTRUCTION_H_
