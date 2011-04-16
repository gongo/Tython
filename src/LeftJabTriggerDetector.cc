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
    Vector upperArm = user->skeletonLeftUpperArm();
    Vector forearm  = user->skeletonLeftForearm();
    return upperArm.isOrthogonal(forearm);
}

bool LeftJabTriggerDetector::isLeftJab(void)
{
    Vector upperArm = user->skeletonLeftUpperArm();
    Vector forearm  = user->skeletonLeftForearm();
    return upperArm.isStraight(forearm);
}
