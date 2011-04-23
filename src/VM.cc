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

void VM::dup(int arg)
{
    push(top());
}

void VM::swap(int arg)
{
    int p1 = pop();
    int p2 = pop();

    push(p1);
    push(p2);
}

void VM::add(int arg)
{
    int p1 = pop();
    int p2 = pop();

    push(p1 + p2);
}

void VM::sub(int arg)
{
    int p1 = pop();
    int p2 = pop();

    push(p1 - p2);
}

void VM::mul(int arg)
{
    int p1 = pop();
    int p2 = pop();

    push(p1 * p2);
}

void VM::div(int arg)
{
    int p1 = pop();
    int p2 = pop();

    push(p1 / p2);
}

void VM::num_out(int arg)
{
    std::cout << pop() << std::endl;
}

void VM::push(int arg)
{
    _stack.push(arg);
}

int VM::top(void)
{
    return _stack.top();
}

int VM::pop(void)
{
    int p = _stack.top();
    _stack.pop();
    return p;
}
