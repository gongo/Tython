#include "LocusDetector.h"

namespace ty {

LocusDetector::LocusDetector(User* _user)
    : AbstractDetector(_user), timeLimit(0.0f), moveThreshold(0.0f)
{
}

LocusDetector::~LocusDetector(void)
{
}

bool LocusDetector::isPosing(void)
{
    return true;
}

bool LocusDetector::isTraceCondition (const Vector& v_st,
                                      const Vector& v_ed) const
{
    return v_st.distance(v_ed) > moveThreshold;
}

} // namespace ty
