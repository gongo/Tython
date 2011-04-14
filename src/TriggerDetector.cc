#include "TriggerDetector.h"

TriggerDetector::TriggerDetector(User* _user, int _triggerNum, int _timeLimit)
    : AbstractDetector(_user), triggerNum(_triggerNum), timeLimit(_timeLimit)
{
    triggerList = new Trigger[triggerNum];
}

TriggerDetector::~TriggerDetector(void)
{
    delete [] triggerList;
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
    triggerIndex = 0;
}

bool TriggerDetector::withinTimeLimit(void)
{
    return true;
}
