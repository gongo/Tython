#include "CrossArmBlockPoseDetector.h"

namespace ty {

bool CrossArmBlockPoseDetector::isPosing(void)
{
    Vector rarm = user->skeletonRightForearm();
    Vector larm = user->skeletonLeftForearm();
    return rarm.isOrthogonal(larm);
}

} // namespace ty
