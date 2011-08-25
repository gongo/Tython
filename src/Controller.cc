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
    IMquit quitList = im->quit();

    while(true) {
        for (IMmap::iterator it = inputList.begin(); it != inputList.end(); ++it) {
            if (it->second->detect()) {
                eventRef = CGEventCreateKeyboardEvent(NULL, (CGKeyCode)(it->first), true);
                CGEventPost(kCGSessionEventTap, eventRef);
            }
        }

        for (IMquit::iterator it = quitList.begin(); it != quitList.end(); ++it) {
            if ((*it)->detect()) {
                eventRef = CGEventCreateKeyboardEvent(NULL, (CGKeyCode)53, true);
                CGEventPost(kCGSessionEventTap, eventRef);
                CFRelease(eventRef); 
                return;
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

