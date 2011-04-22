#include "AbstractDetector.h"

AbstractDetector::AbstractDetector(User* _user) : user(_user)
{
    timer = Timer::getInstance();
}

AbstractDetector::~AbstractDetector(void)
{
}

bool AbstractDetector::detect()
{
    if (!user->getTrackingId()) {
        return false;
    }

    if (isPosing()) {
        return true;
    }

    return false;
}