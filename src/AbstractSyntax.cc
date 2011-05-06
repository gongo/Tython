#include "AbstractSyntax.h"

AbstractSyntax::AbstractSyntax(void)
{
}

AbstractSyntax::~AbstractSyntax(void)
{
    SyntaxInput::iterator ip = inputList.begin();
    SyntaxQuit::iterator qu = quitList.end();

    // while (ip != inputList.end()) {
    //     delete ip->second;
    //     ++ip;
    // }

    // while (qu != quitList.end()) {
    //     AbstractDetector* quit = *(qu++);
    //     delete quit;
    // }
}

SyntaxInput AbstractSyntax::input(void)
{
    return inputList;
}

SyntaxQuit AbstractSyntax::quit(void)
{
    return quitList;
}
