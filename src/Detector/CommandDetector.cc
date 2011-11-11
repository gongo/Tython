#include <cstdarg>
#include "CommandDetector.h"
#include "Timer.h"

namespace ty {

CommandDetector::CommandDetector(User* _user) : AbstractDetector(_user), commandNum(0)
{
    commandList   = NULL;
    resetCommand();
}

CommandDetector::~CommandDetector(void)
{
    if (commandList != NULL) {
        delete [] commandList;
    }
}

void CommandDetector::setCommand(XnUInt64 _timeLimit, int _commandNum, ...)
{
    va_list ap;

    timeLimit   = _timeLimit;
    commandNum  = _commandNum;
    commandList = new Command[_commandNum];

    va_start(ap, _commandNum);
    while (_commandNum > 0) {
        commandList[commandNum - _commandNum] = va_arg(ap, Command);
        _commandNum--;
    }
    va_end(ap);
}

bool CommandDetector::isPosing(void)
{
    if (commandList == NULL) {
        return false;
    }

    if (!withinTimeLimit()) {
        resetCommand();
        return false;
    }

    if ((this->*commandList[commandIndex])()) {
        nextCommand();
    }

    if (commandIndex == commandNum) {
        resetCommand();
        return true;
    }

    return false;
}

void CommandDetector::resetCommand(void)
{
    detectionTime = 0;
    commandIndex  = 0;
}

void CommandDetector::nextCommand(void)
{
    if (commandIndex == 0) {
        detectionTime = timer->current();
    }

    commandIndex++;
}

bool CommandDetector::withinTimeLimit(void)
{
    return (commandIndex == 0) || ((timer->current() - detectionTime) <= timeLimit);
}

} // namespace ty
