#include "DefaultInputMethod.h"
#include "RightStraightCommandDetector.h"
#include "RightUpperCommandDetector.h"
#include "LeftJabCommandDetector.h"
#include "LeftHookCommandDetector.h"
#include "ThanksCommandDetector.h"
#include "OwataPoseDetector.h"

DefaultInputMethod::DefaultInputMethod(void)
{
}

DefaultInputMethod::DefaultInputMethod(ty::User* _user)
{
    inputList.insert(std::make_pair("a", new ty::LeftJabCommandDetector(_user)));
    inputList.insert(std::make_pair("@", new ty::RightStraightCommandDetector(_user)));
    inputList.insert(std::make_pair("g", new ty::RightUpperCommandDetector(_user)));
    inputList.insert(std::make_pair(" ", new ty::LeftHookCommandDetector(_user)));

    quitList.push_back(new ty::OwataPoseDetector(_user));
}
