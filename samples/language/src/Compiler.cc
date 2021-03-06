#include "Compiler.h"

Compiler* Compiler::_instance = new Compiler;
string Compiler::_treat = " a@g";

Compiler* Compiler::instance(void)
{
    return Compiler::_instance;
}

vector<Instruction*> Compiler::compile(string source)
{
    unsigned int index = 0;
    unsigned int cur = 0;

    std::vector<Instruction*> insns;

    /**
     * @todo 縺薙％縺ｯ萓句､悶ｒ謚輔£繧医≧
     */
    if (source.find_first_not_of(Compiler::_treat) != string::npos) {
        //return insns;
    }

    while (index < source.length()) {
        if ((cur = scan(source, "aa", index)) != index) {
            insns.push_back(op("push", input(source, cur)));
        } else if ((cur = scan(source, "a a",  index)) != index) {
            insns.push_back(op("dup"));
        } else if ((cur = scan(source, "a@a",  index)) != index) {
            insns.push_back(op("copy", input(source, cur)));
        } else if ((cur = scan(source, "a @",  index)) != index) {
            insns.push_back(op("swap"));
        } else if ((cur = scan(source, "a  ",  index)) != index) {
            insns.push_back(op("discard"));            
        } else if ((cur = scan(source, "a@ ",  index)) != index) {
            insns.push_back(op("slide", input(source, cur)));
        } else if ((cur = scan(source, "@aaa", index)) != index) {
            insns.push_back(op("add"));
        } else if ((cur = scan(source, "@aa@", index)) != index) {
            insns.push_back(op("sub"));
        } else if ((cur = scan(source, "@aa ", index)) != index) {
            insns.push_back(op("mul"));
        } else if ((cur = scan(source, "@a@a", index)) != index) {
            insns.push_back(op("div"));
        } else if ((cur = scan(source, "@a@@", index)) != index) {
            insns.push_back(op("mod"));
        } else if ((cur = scan(source, "@@  ", index)) != index) {
            insns.push_back(op("heap_write"));
        } else if ((cur = scan(source, "@@@",  index)) != index) {
            insns.push_back(op("heap_read"));
        } else if ((cur = scan(source, " aa",  index)) != index) {
            insns.push_back(op("label", input(source, cur)));
        } else if ((cur = scan(source, " a@",  index)) != index) {
            insns.push_back(op("call", input(source, cur)));
        } else if ((cur = scan(source, " a ",  index)) != index) {
            insns.push_back(op("jump", input(source, cur)));
        } else if ((cur = scan(source, " @a",  index)) != index) {
            insns.push_back(op("jump_zero", input(source, cur)));
        } else if ((cur = scan(source, " @@",  index)) != index) {
            insns.push_back(op("jump_negative", input(source, cur)));
        } else if ((cur = scan(source, " @ ",  index)) != index) {
            insns.push_back(op("return"));
        } else if ((cur = scan(source, "   ",  index)) != index) {
            insns.push_back(op("exit"));
        } else if ((cur = scan(source, "@ aa", index)) != index) {
            insns.push_back(op("char_out"));
        } else if ((cur = scan(source, "@ a@", index)) != index) {
            insns.push_back(op("num_out"));
        } else {
            insns.clear();
            break;
        }

        index = cur;
    }

    return insns;
}

int Compiler::scan(string str, string target, int index)
{
    return (str.find(target, index) == index) ? index + target.length() : index;
}

int Compiler::input(string str, unsigned int& index)
{
    int endIndex;
    int num = 0;
    int digit = 0;

    if ((endIndex = str.find('g', index)) == string::npos) {
        throw 3;
    }

    string::iterator itSt = str.begin() + index;
    string::iterator itEd = str.begin() + endIndex - 1;

    while (itSt < itEd) {
        char c = *itEd;
        num += (((c == 'a') ? 1 : 0) << digit++);
        itEd--;
    }

    if (*itSt == '@') {
        num = ~num + 1;
    }

    index = endIndex + 1;
    return num;
}

Instruction* Compiler::op(string str, int arg)
{
    return new Instruction(str, arg);
}

Instruction* Compiler::op(string str)
{
    return new Instruction(str);
}
