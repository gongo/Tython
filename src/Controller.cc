#include <stdio.h>
#include "Controller.h"
#include "TyphonSyntax.h"
#include "AbstractRenderer.h"
#include "util.h"
#include "Instruction.h"
#include <vector>

AbstractRenderer *renderer;

Controller::Controller(void)
{
    initXN();
    ctxUser = new User(&ctxGlobal);

    renderer = new AbstractRenderer(&ctxGlobal, ctxUser);
    syntax = new TyphonSyntax(ctxUser);

    compiler = Compiler::instance();
    vm = VM::instance();
}

Controller::~Controller(void)
{
    delete syntax;
    delete renderer;
    delete ctxUser;
    ctxGlobal.Shutdown();
}

void Controller::main(void)
{
    renderer->draw();

    SyntaxInput inputList = syntax->input();
    SyntaxQuit quitList = syntax->quit();

    for (SyntaxInput::iterator it = inputList.begin(); it != inputList.end(); ++it) {
        if (it->second->detect()) {
            source += it->first;
            printf("%s\n", it->first.c_str());
        }
    }

    for (SyntaxQuit::iterator it = quitList.begin(); it != quitList.end(); ++it) {
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

