#include <cstdarg>
#include "TriggerDetector.h"
#include "Timer.h"

TriggerDetector::TriggerDetector(User* _user) : AbstractDetector(_user)
{
    triggerList   = NULL;
    resetTrigger();
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
    if (triggerList == NULL) {
        return false;
    }

    if (!withinTimeLimit()) {
        resetTrigger();
        return false;
    }

    if ((this->*triggerList[triggerIndex])()) {
        nextTrigger();
    }

    if (triggerIndex == triggerNum) {
        resetTrigger();
        return true;
    }

    return false;
}

void TriggerDetector::resetTrigger(void)
{
    detectionTime = 0;
    triggerIndex  = 0;
}

void TriggerDetector::nextTrigger(void)
{
    if (triggerIndex == 0) {
        detectionTime = timer->current();
    }
    
    triggerIndex++;
}

bool TriggerDetector::withinTimeLimit(void)
{
    if (triggerIndex == 0) {
        return true;
    }

    return (timer->current() - detectionTime) <= timeLimit;
}
