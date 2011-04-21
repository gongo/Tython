#include <stdio.h>
#include "Controller.h"
#include "RightStraightTriggerDetector.h"
#include "LeftJabTriggerDetector.h"
#include "AbstractRenderer.h"
#include "util.h"

LeftJabTriggerDetector *detect1;
RightStraightTriggerDetector *detect2;
AbstractRenderer *renderer;

Controller::Controller(void)
{
    initXN();
    ctxUser = new User(&ctxGlobal);

    detect1 = new LeftJabTriggerDetector(ctxUser);
    detect2 = new RightStraightTriggerDetector(ctxUser);
    renderer = new AbstractRenderer(&ctxGlobal, ctxUser);
}

Controller::~Controller(void)
{
    delete detect1;
    delete detect2;
    delete renderer;
    delete ctxUser;
    ctxGlobal.Shutdown();
}

void Controller::main(void)
{
    renderer->draw();
    if (detect1->detect()) {
        printf("Jab!\n");
    }
    if (detect2->detect()) {
        printf("Straight!\n");
    }
    ctxGlobal.WaitAndUpdateAll();
}

void Controller::initXN(void)
{
    CHECK_XN(ctxGlobal.InitFromXmlFile("Tython.xml"));
    CHECK_XN(ctxGlobal.SetGlobalMirror(true));
}

