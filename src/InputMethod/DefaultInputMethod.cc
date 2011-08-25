#include "DefaultInputMethod.h"
#include "RightStraightCommandDetector.h"
#include "LeftJabCommandDetector.h"
#include "OwataPoseDetector.h"

DefaultInputMethod::DefaultInputMethod(void)
{
}

DefaultInputMethod::DefaultInputMethod(User* _user)
{
    inputList.insert(std::make_pair(123, new LeftJabCommandDetector(_user)));
    inputList.insert(std::make_pair(124, new RightStraightCommandDetector(_user)));

    quitList.push_back(new OwataPoseDetector(_user));
}
