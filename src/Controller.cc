#include "Controller.h"
#include "DefaultInputMethod.h"
#include "util.h"
#include "UserFactory.h"
#include <ApplicationServices/ApplicationServices.h> 

Controller::Controller(void)
{
    initXN();

    UserFactory::setContext(&ctxGlobal);
    user     = UserFactory::get(1);
    im       = new DefaultInputMethod(user);
}

Controller::~Controller(void)
{
    delete im;
    delete user;
    delete ctxUser;
    ctxGlobal.Shutdown();
}

void Controller::main(void)
{
    CGEventRef eventRef; 
    IMmap inputList = im->input();
    int keymask = 0x7f;
    int keycode = 0;
    int keyflag = 0;

    while(true) {
        for (IMmap::iterator it = inputList.begin(); it != inputList.end(); ++it) {
            if (it->second->detect()) {
                keycode = (it->first) & keymask;
                keyflag = (it->first) & ~keymask;
                eventRef = CGEventCreateKeyboardEvent(NULL, (CGKeyCode)keycode, true);
                CGEventSetFlags(eventRef, keyflag);
                CGEventPost(kCGSessionEventTap, eventRef);
            }
        }

        ctxGlobal.WaitAndUpdateAll();
    }
}

void Controller::initXN(void)
{
    CHECK_XN(ctxGlobal.InitFromXmlFile("Tython.xml"));
    CHECK_XN(ctxGlobal.SetGlobalMirror(true));
}

