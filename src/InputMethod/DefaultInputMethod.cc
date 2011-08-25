#include "DefaultInputMethod.h"
#include "RightStraightCommandDetector.h"
#include "LeftJabCommandDetector.h"
#include "OwataPoseDetector.h"
#include "BoonPoseDetector.h"
#include <ApplicationServices/ApplicationServices.h> 

DefaultInputMethod::DefaultInputMethod(void)
{
}

DefaultInputMethod::DefaultInputMethod(User* _user)
{
    inputList.insert(std::make_pair(123, new LeftJabCommandDetector(_user)));
    inputList.insert(std::make_pair(124, new RightStraightCommandDetector(_user)));
    inputList.insert(std::make_pair(kCGEventFlagMaskShift + kCGEventFlagMaskCommand + 3, new BoonPoseDetector(_user)));
    inputList.insert(std::make_pair(53,  new OwataPoseDetector(_user)));
}
