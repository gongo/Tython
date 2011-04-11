#include "stdio.h"
#include "Controller.h"
#include "CrossArmBlockPoseDetector.h"
#include "util.h"

Controller::Controller(void)
{
    initXN();
    ctxUser = new User(&ctxGlobal);
}

Controller::~Controller(void)
{
    delete ctxUser;
    ctxGlobal.Shutdown();
}

void Controller::main(void)
{
    CrossArmBlockPoseDetector *detect = new CrossArmBlockPoseDetector(ctxUser);

    while (true) {
        if (detect->detect()) {
            printf("OK!\n");
        } else {
            printf("Boooooooo........\n");
        }
        ctxGlobal.WaitAndUpdateAll();
    }
}

void Controller::initXN(void)
{
    CHECK_XN(ctxGlobal.InitFromXmlFile("Tython.xml"));
    CHECK_XN(ctxGlobal.SetGlobalMirror(true));
}
