#include <stdio.h>
#include "Controller.h"
#include "DefaultInputMethod.h"
#include "AbstractRenderer.h"
#include "util.h"
#include "Instruction.h"
#include <vector>

AbstractRenderer *renderer;

Controller::Controller(void)
{
    initXN();

    ctxUser  = new UserContext(&ctxGlobal);
    user = new User(ctxUser);
    renderer = new AbstractRenderer(&ctxGlobal, user);
    im       = new DefaultInputMethod(user);
    compiler = Compiler::instance();
    vm       = VM::instance();
}

Controller::~Controller(void)
{
    delete im;
    delete renderer;
    delete user;
    delete ctxUser;
    ctxGlobal.Shutdown();
}

void Controller::main(void)
{
    renderer->draw();

    IMmap inputList = im->input();
    IMquit quitList = im->quit();

    for (IMmap::iterator it = inputList.begin(); it != inputList.end(); ++it) {
        if (it->second->detect()) {
            source += it->first;
            printf("%s\n", it->first.c_str());
        }
    }

    for (IMquit::iterator it = quitList.begin(); it != quitList.end(); ++it) {
        if ((*it)->detect()) {
            printf("%s\n", source.c_str());
            std::vector<Instruction*> insns = compiler->compile(source);
            vm->run(insns);
            printf("\n");
            exit(0);
        }
    }

    ctxGlobal.WaitAndUpdateAll();
}

void Controller::initXN(void)
{
    CHECK_XN(ctxGlobal.InitFromXmlFile("Tython.xml"));
    CHECK_XN(ctxGlobal.SetGlobalMirror(true));
}

