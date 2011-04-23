#include "Compiler.h"
#include <cstring>
#include <iostream>

Compiler* Compiler::_instance = new Compiler;
string Compiler::_treat = " a@g";
//std::stack Compiler::_stack;

Compiler* Compiler::instance(void)
{
    return Compiler::_instance;
}

bool Compiler::compile(string source)
{
    int index = 0;
    int cur = 0;

    if (source.find_first_not_of(Compiler::_treat) != string::npos) {
        return false;
    }

    while (index < source.length()) {
        if ((cur = scan(source, "aa", index)) != index) {
        } else if ((cur = scan(source, "a a",  index)) != index) {
        } else if ((cur = scan(source, "a@a",  index)) != index) {
        } else if ((cur = scan(source, "a @",  index)) != index) {
        } else if ((cur = scan(source, "a  ",  index)) != index) {
        } else if ((cur = scan(source, "a@ ",  index)) != index) {
        } else if ((cur = scan(source, "@aaa", index)) != index) {
        } else if ((cur = scan(source, "@aa@", index)) != index) {
        } else if ((cur = scan(source, "@aa ", index)) != index) {
        } else if ((cur = scan(source, "@a@a", index)) != index) {
        } else if ((cur = scan(source, "@a@@", index)) != index) {
        } else if ((cur = scan(source, "@@  ", index)) != index) {
        } else if ((cur = scan(source, "@@@",  index)) != index) {
        } else if ((cur = scan(source, " aa",  index)) != index) {
        } else if ((cur = scan(source, " a@",  index)) != index) {
        } else if ((cur = scan(source, " a ",  index)) != index) {
        } else if ((cur = scan(source, " @a",  index)) != index) {
        } else if ((cur = scan(source, " @@",  index)) != index) {
        } else if ((cur = scan(source, " @ ",  index)) != index) {
        } else if ((cur = scan(source, "   ",  index)) != index) {
            return true;
        } else if ((cur = scan(source, "@ aa", index)) != index) {
        } else if ((cur = scan(source, "@ a@", index)) != index) {
        } else if ((cur = scan(source, "@ @ ", index)) != index) {
        } else if ((cur = scan(source, "@ @@", index)) != index) {
        } else {
            return false;
        }

        index = cur;
    }

    return true;
}

int Compiler::scan(string str, string target, int index)
{
    return (str.find(target, index) == index) ? index + target.length() : index;
}

int Compiler::input(string str, int index)
{
    int endIndex;
    int num = 0;
    int digit = 0;

    if ((endIndex = str.find('g', index)) == string::npos) {
        throw 3;
    }

    string::iterator itSt = str.begin() + index;
    string::iterator itEd = str.begin() + endIndex - 1;

    while (itSt <= itEd) {
        char c = *itEd;
        num += (((c == 'a') ? 1 : 0) << digit++);
        itEd--;
    }

    return endIndex + 1;
}
