#include <cstdarg>
#include "TriggerDetector.h"

TriggerDetector::TriggerDetector(User* _user)
    : AbstractDetector(_user), triggerList(NULL), currentTime(0)
{
}

TriggerDetector::~TriggerDetector(void)
{
    if (triggerList != NULL) {
        delete [] triggerList;
    }
}

void TriggerDetector::setTrigger(int _timeLimit, int _triggerNum, ...)
{
    va_list ap;

    timeLimit   = _timeLimit;
    triggerNum  = _triggerNum;
    triggerList = new Trigger[_triggerNum];

    va_start(ap, _triggerNum);
    while (_triggerNum > 0) {
        triggerList[triggerNum - _triggerNum] = va_arg(ap, Trigger);
        _triggerNum--;
    }
    va_end(ap);
}

bool TriggerDetector::isPosing(void)
{
    if ((this->*triggerList[triggerIndex])()) {
        triggerIndex++;
    }

    if (!withinTimeLimit()) {
        resetTrigger();
        return false;
    }

    if (triggerIndex == triggerNum) {
        resetTrigger();
        return true;
    }

    return false;
}

void TriggerDetector::resetTrigger(void)
{
    currentTime = 0;
    triggerIndex = 0;
}

bool TriggerDetector::withinTimeLimit(void)
{
    return true;
}
