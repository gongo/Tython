#include <stdio.h>
#include "Controller.h"
#include "RightStraightTriggerDetector.h"
#include "RightUpperTriggerDetector.h"
#include "LeftJabTriggerDetector.h"
#include "LeftHookTriggerDetector.h"
#include "ThanksTriggerDetector.h"
#include "AbstractRenderer.h"
#include "util.h"
#include "Instruction.h"
#include <vector>

LeftJabTriggerDetector *detect1;
RightStraightTriggerDetector *detect2;
ThanksTriggerDetector *detect3;
LeftHookTriggerDetector *detect4;
RightUpperTriggerDetector *detect5;
AbstractRenderer *renderer;

Controller::Controller(void)
{
    initXN();
    ctxUser = new User(&ctxGlobal);

    detect1 = new LeftJabTriggerDetector(ctxUser);
    detect2 = new RightStraightTriggerDetector(ctxUser);
    detect3 = new ThanksTriggerDetector(ctxUser);
    detect4 = new LeftHookTriggerDetector(ctxUser);
    detect5 = new RightUpperTriggerDetector(ctxUser);

    renderer = new AbstractRenderer(&ctxGlobal, ctxUser);

    compiler = Compiler::instance();
    vm = VM::instance();
}

Controller::~Controller(void)
{
    delete detect1;
    delete detect2;
    delete detect3;
    delete renderer;
    delete ctxUser;
    ctxGlobal.Shutdown();
}

void Controller::main(void)
{
    renderer->draw();
    if (detect1->detect()) {
        printf("'a' Jab!\n");
        source += 'a';
    }
    if (detect2->detect()) {
        printf("'@' Straight!\n");
        source += '@';
    }
    if (detect4->detect()) {
        printf("' ' hook\n");
        source += ' ';
    }
    if (detect5->detect()) {
        printf("'g' UPPPERRRRRRR\n");
        source += 'g';
    }
    if (detect3->detect()) {
        printf("Thanks!!!!\n");
        std::vector<Instruction*> insns = compiler->compile(source);
        vm->run(insns);
        printf("\n");
        exit(0);
    }
    ctxGlobal.WaitAndUpdateAll();
}

void Controller::initXN(void)
{
    CHECK_XN(ctxGlobal.InitFromXmlFile("Tython.xml"));
    CHECK_XN(ctxGlobal.SetGlobalMirror(true));
}

