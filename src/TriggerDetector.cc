#include "TriggerDetector.h"

TriggerDetector::TriggerDetector(User* _user) : AbstractDetector(_user)
{
}

TriggerDetector::~TriggerDetector(void)
{
}

bool TriggerDetector::isPosing(void)
{
    return true;
}
