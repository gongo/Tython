#include "LeftJabTriggerDetector.h"

LeftJabTriggerDetector::LeftJabTriggerDetector(User* _user) : TriggerDetector(_user)
{
    setTrigger(2, 3,
               &LeftJabTriggerDetector::isStand,
               &LeftJabTriggerDetector::isLeftJab,
               &LeftJabTriggerDetector::isStand);
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
