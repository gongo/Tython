#include "AbstractDetector.h"

namespace ty {

AbstractDetector::AbstractDetector(User* _user) : user(_user)
{
    timer = Timer::instance();
}

AbstractDetector::~AbstractDetector(void)
{
}

bool AbstractDetector::detect()
{
    return user->isTracking() && isPosing();
}

} // namespace ty
