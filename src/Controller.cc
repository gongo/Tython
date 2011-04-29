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

    SyntaxInput::iterator inputIterator = syntax->input().begin();
    SyntaxQuit::iterator quitIterator = syntax->quit().begin();

    while (inputIterator != inputList.end()) {
        if (((*inputIterator).second)->detect()) {
            source += (*inputIterator).first;
            //printf("%c\n", (*inputIterator).first);
        }
        inputIterator++;
    }

    // while (quitIterator != quitList.end()) {
    //     if ((*quitIterator)->detect()) {
    //         std::vector<Instruction*> insns = compiler->compile(source);
    //         vm->run(insns);
    //         printf("\n");
    //         exit(0);
    //     }
    //     quitIterator++;
    // }

    ctxGlobal.WaitAndUpdateAll();
}

void Controller::initXN(void)
{
    CHECK_XN(ctxGlobal.InitFromXmlFile("Tython.xml"));
    CHECK_XN(ctxGlobal.SetGlobalMirror(true));
}

