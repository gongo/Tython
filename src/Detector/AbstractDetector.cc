#include "AbstractDetector.h"

AbstractDetector::AbstractDetector(User* _user) : user(_user)
{
    timer = Timer::instance();
}

AbstractDetector::~AbstractDetector(void)
{
}

bool AbstractDetector::detect()
{
    if (!user->isCalibrated()) {
        return false;
    }

    return isPosing();
}
