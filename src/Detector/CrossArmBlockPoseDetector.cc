#include "CrossArmBlockPoseDetector.h"

namespace ty {

bool CrossArmBlockPoseDetector::isPosing(void)
{
    Vector rarm = user->vectorRightForearm();
    Vector larm = user->vectorLeftForearm();
    return rarm.isOrthogonal(larm);
}

} // namespace ty
