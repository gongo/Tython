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

    if (source.find_first_not_of(Compiler::_treat) != string::npos) {
        return false;
    }

    while (index < source.length()) {
        printf("%d, %d\n", index, source.length());
        if ((index = scan(source, "aa", index)) != index) {
        } else if ((index = scan(source, "a a",  index)) != index) {
        } else if ((index = scan(source, "a@a",  index)) != index) {
        } else if ((index = scan(source, "a @",  index)) != index) {
        } else if ((index = scan(source, "a  ",  index)) != index) {
        } else if ((index = scan(source, "a@ ",  index)) != index) {
        } else if ((index = scan(source, "@aaa", index)) != index) {
        } else if ((index = scan(source, "@aa@", index)) != index) {
        } else if ((index = scan(source, "@aa ", index)) != index) {
        } else if ((index = scan(source, "@a@a", index)) != index) {
        } else if ((index = scan(source, "@a@@", index)) != index) {
        } else if ((index = scan(source, "@@  ", index)) != index) {
        } else if ((index = scan(source, "@@@",  index)) != index) {
        } else if ((index = scan(source, " aa",  index)) != index) {
        } else if ((index = scan(source, " a@",  index)) != index) {
        } else if ((index = scan(source, " a ",  index)) != index) {
        } else if ((index = scan(source, " @a",  index)) != index) {
        } else if ((index = scan(source, " @@",  index)) != index) {
        } else if ((index = scan(source, " @ ",  index)) != index) {
        } else if ((index = scan(source, "   ",  index)) != index) {
        } else if ((index = scan(source, "@ aa", index)) != index) {
        } else if ((index = scan(source, "@ a@", index)) != index) {
        } else if ((index = scan(source, "@ @ ", index)) != index) {
        } else if ((index = scan(source, "@ @@", index)) != index) {
        } else {
            return false;
        }
    }

    return true;
}

int Compiler::scan(string str, string target, int index)
{
    return (str.find(target, index) == index) ? index + target.length() : index;
}
