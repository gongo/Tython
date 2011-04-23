#include "VM.h"
#include <iostream>

VM* VM::_instance = new VM;

VM::VM(void) : _pc(0)
{
    opset["push"]    = &VM::push;
    opset["dup"]     = &VM::dup;
    opset["swap"]    = &VM::swap;
    opset["discard"] = &VM::discard;
    opset["slide"]   = &VM::slide;
    opset["add"]     = &VM::add;
    opset["sub"]     = &VM::sub;
    opset["mul"]     = &VM::mul;
    opset["div"]     = &VM::div;
    opset["num_out"] = &VM::num_out;
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

void VM::discard(int arg)
{
    pop();
}

void VM::slide(int arg)
{
    int p = pop();
    for (; arg > 0; arg--) {
        pop();
    }
    push(p);
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
    std::cout << pop();
}

void VM::push(int arg)
{
    vector<int>::iterator it = _stack.begin();
    _stack.insert(it, arg);
}

int VM::top(void)
{
    return _stack.front();
}

int VM::pop(void)
{
    int p = _stack.front();
    vector<int>::iterator it = _stack.begin();
    _stack.erase(it);
    return p;
}

void VM::clear(void)
{
    _stack.clear();
}

int VM::size(void)
{
    return _stack.size();
}
