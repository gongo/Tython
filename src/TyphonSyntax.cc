#include "TyphonSyntax.h"
#include "RightStraightCommandDetector.h"
#include "RightUpperCommandDetector.h"
#include "LeftJabCommandDetector.h"
#include "LeftHookCommandDetector.h"
#include "ThanksCommandDetector.h"

TyphonSyntax::TyphonSyntax(void)
{
}

TyphonSyntax::TyphonSyntax(User* _user)
{
    LeftJabCommandDetector *detect = new LeftJabCommandDetector(_user);
    inputList["a"] = detect;
    // inputList["@"] = new RightStraightCommandDetector(_user);
    // inputList["g"] = new RightUpperCommandDetector(_user);
    // inputList[" "] = new LeftHookCommandDetector(_user);

    quitList.push_back(new ThanksCommandDetector(_user));
}
