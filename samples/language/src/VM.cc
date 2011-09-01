#include "VM.h"
#include <iostream>

VM* VM::_instance = new VM;

VM::VM(void) : _pc(0)
{
    _opset["push"]          = &VM::push;
    _opset["dup"]           = &VM::dup;
    _opset["swap"]          = &VM::swap;
    _opset["discard"]       = &VM::discard;
    _opset["slide"]         = &VM::slide;
    _opset["add"]           = &VM::add;
    _opset["sub"]           = &VM::sub;
    _opset["mul"]           = &VM::mul;
    _opset["div"]           = &VM::div;
    _opset["mod"]           = &VM::mod;
    _opset["label"]         = &VM::label;
    //_opset["call"]          = &VM::call;
    _opset["jump"]          = &VM::jump;
    _opset["jump_zero"]     = &VM::jump_zero;
    _opset["jump_negative"] = &VM::jump_negative;
    _opset["char_out"]      = &VM::char_out;
    _opset["num_out"]       = &VM::num_out;
}

VM* VM::instance(void)
{
    return VM::_instance;
}

void VM::findLabel(vector<Instruction*> insns)
{
    for (unsigned int i = 0; i < insns.size(); i++) {
        if (insns.at(i)->op.compare("label")) {
            _labels[insns.at(i)->arg] = i;
        }
    }
}

bool VM::run(vector<Instruction*> insns)
{
    findLabel(insns);
    
    for (_pc = 0; _pc < insns.size(); _pc++) {
        string op = insns.at(_pc)->op;
        int arg = insns.at(_pc)->arg;

        if (_opset.find(op) != _opset.end()) {
            (this->*_opset[op])(arg);
        }
    }

    refresh(insns);
    clear();

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

void VM::mod(int arg)
{
    int p1 = pop();
    int p2 = pop();

    push(p1 % p2);
}

void VM::label(int arg)
{
}

void VM::jump(int arg)
{
    jump_to(arg);
}

void VM::jump_zero(int arg)
{
    if (pop() == 0) {
        jump(arg);
    }
}

void VM::jump_negative(int arg)
{
    if (pop() == 0) {
        jump(arg);
    }
}

void VM::char_out(int arg)
{
    std::cout << (char)pop();
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
    _labels.clear();
}

int VM::size(void)
{
    return _stack.size();
}

void VM::refresh(vector<Instruction*> insns)
{
    vector<Instruction*>::iterator it = insns.begin();

    while (it != insns.end()) {
        Instruction *ins = *it;
        it++;
        delete ins;
    }

    clear();
}

void VM::jump_to(int pc)
{
    _pc = _labels[pc];
}
