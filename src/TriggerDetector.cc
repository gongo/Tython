#include <cstdarg>
#include "TriggerDetector.h"
#include "Timer.h"

TriggerDetector::TriggerDetector(User* _user)
    : AbstractDetector(_user), triggerList(NULL), elapsedTime(0)
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
    elapsedTime   = 0;
    detectionTime = 0;
    triggerIndex  = 0;
}

void TriggerDetector::nextTrigger(void)
{
    int currentTime = timer->current();

    elapsedTime += (triggerIndex == 0) ? 0 : currentTime - detectionTime;
    detectionTime = currentTime;

    triggerIndex++;
}

bool TriggerDetector::withinTimeLimit(void)
{
    return elapsedTime <= timeLimit;
}
