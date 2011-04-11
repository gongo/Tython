#include "PoseDetector.h"

PoseDetector::PoseDetector(User* _user) : AbstractDetector(_user)
{
}

PoseDetector::~PoseDetector(void)
{
}

bool PoseDetector::isPosing(void)
{
    return true;
}
