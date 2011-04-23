#include "VM.h"
#include <iostream>

VM* VM::_instance = new VM;

VM::VM(void) : _pc(0)
{
    opset["push"] = &VM::push;
}

VM* VM::instance(void)
{
    return VM::_instance;
}

bool VM::run(vector<Instruction*> insns)
{
    map<string, opfunc> findit;

    for (_pc = 0; _pc < insns.size(); _pc++) {
        string op = insns.at(_pc)->op;
        int arg = insns.at(_pc)->arg;
        
        if (opset.find(op) != opset.end()) {
            (this->*opset[op])(arg);
        }
    }

    return true;
}

void VM::push(int arg)
{
    _stack.push(arg);
}

void VM::dup(int arg)
{
    _stack.push(_stack.top());
}

void VM::swap(int arg)
{
    int p1 = _stack.top(); _stack.pop();
    int p2 = _stack.top(); _stack.pop();

    _stack.push(p1);
    _stack.push(p2);
}

void VM::add(int arg)
{
    int p1 = _stack.top(); _stack.pop();
    int p2 = _stack.top(); _stack.pop();

    _stack.push(p1 + p2);
}

void VM::sub(int arg)
{
    int p1 = _stack.top(); _stack.pop();
    int p2 = _stack.top(); _stack.pop();

    _stack.push(p1 - p2);
}

void VM::mul(int arg)
{
    int p1 = _stack.top(); _stack.pop();
    int p2 = _stack.top(); _stack.pop();

    _stack.push(p1 * p2);
}

void VM::div(int arg)
{
    int p1 = _stack.top(); _stack.pop();
    int p2 = _stack.top(); _stack.pop();

    _stack.push(p1 / p2);
}
