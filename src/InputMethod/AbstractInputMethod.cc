#include "AbstractInputMethod.h"

AbstractInputMethod::AbstractInputMethod(void)
{
}

AbstractInputMethod::~AbstractInputMethod(void)
{
    IMmap::iterator ip = inputList.begin();
    IMquit::iterator qu = quitList.end();

    // while (ip != inputList.end()) {
    //     delete ip->second;
    //     ++ip;
    // }

    // while (qu != quitList.end()) {
    //     AbstractDetector* quit = *(qu++);
    //     delete quit;
    // }
}

IMmap AbstractInputMethod::input(void)
{
    return inputList;
}

IMquit AbstractInputMethod::quit(void)
{
    return quitList;
}
