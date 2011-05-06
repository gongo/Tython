#include "DefaultInputMethod.h"
#include "RightStraightCommandDetector.h"
#include "RightUpperCommandDetector.h"
#include "LeftJabCommandDetector.h"
#include "LeftHookCommandDetector.h"
#include "ThanksCommandDetector.h"

DefaultInputMethod::DefaultInputMethod(void)
{
}

DefaultInputMethod::DefaultInputMethod(User* _user)
{
    inputList.insert(std::make_pair("a", new LeftJabCommandDetector(_user)));
    inputList.insert(std::make_pair("@", new RightStraightCommandDetector(_user)));
    inputList.insert(std::make_pair("g", new RightUpperCommandDetector(_user)));
    inputList.insert(std::make_pair(" ", new LeftHookCommandDetector(_user)));

    quitList.push_back(new ThanksCommandDetector(_user));
}
