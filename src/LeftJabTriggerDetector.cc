#include "LeftJabTriggerDetector.h"

LeftJabTriggerDetector::LeftJabTriggerDetector(User* _user)
    : TriggerDetector(_user, 3, 2)
{
    triggerList[0] = reinterpret_cast<Trigger>(&LeftJabTriggerDetector::isStand);
    triggerList[1] = reinterpret_cast<Trigger>(&LeftJabTriggerDetector::isLeftJab);
    triggerList[2] = reinterpret_cast<Trigger>(&LeftJabTriggerDetector::isStand);
}

LeftJabTriggerDetector::~LeftJabTriggerDetector(void)
{
}

bool LeftJabTriggerDetector::isStand(void)
{
    return true;
}

bool LeftJabTriggerDetector::isLeftJab(void)
{
    return true;
}
