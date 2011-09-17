#include <iostream>
#include <stdio.h>
#include "Controller.h"
#include "DefaultInputMethod.h"
#include "AbstractRenderer.h"
#include "util.h"
#include "Instruction.h"
#include "UserFactory.h"
#include <vector>
#include <opencv2/opencv.hpp>

AbstractRenderer *renderer;
xn::Player player;
Controller::Controller(const XnChar* recordFileName)
{
    ty::xnRuntimeCheck(ctxGlobal.Init());
    ty::xnRuntimeCheck(ctxGlobal.OpenFileRecording(recordFileName, player));
    player.SetRepeat(false);

    initXN();

    ctxGlobal.StartGeneratingAll();
}
Controller::Controller(void)
{
    ty::xnRuntimeCheck(ctxGlobal.InitFromXmlFile("Tython.xml"));
    ty::xnRuntimeCheck(ctxGlobal.SetGlobalMirror(true));

    initXN();

    world->enableRecord("hoge.oni");
    ctxGlobal.StartGeneratingAll();
}

Controller::~Controller(void)
{
    delete im;
    delete renderer;
    delete user;
    delete ctxUser;
    delete world;
    ctxGlobal.StopGeneratingAll();
    ctxGlobal.Shutdown();
}

void Controller::main(void)
{
    while (1) {
        ctxGlobal.WaitAndUpdateAll();

        renderer->draw();

        if ((cvWaitKey(30) & 0xff) == 'q') break;

        IMmap inputList = im->input();
        IMquit quitList = im->quit();

        for (IMmap::iterator it = inputList.begin(); it != inputList.end(); ++it) {
            if (it->second->detect()) {
                source += it->first;
                //printf("%s\n", it->first.c_str());
                switch ((int)(*it->first.c_str())) {
                case 97:
                    printf("左ジャブ\n");
                    break;
                case 64:
                    printf("右ストレート\n");
                    break;
                case 32:
                    printf("左フック\n");
                    break;
                case 103:
                    printf("右アッパー\n");
                    break;
                }
            }
        }

        for (IMquit::iterator it = quitList.begin(); it != quitList.end(); ++it) {
            if ((*it)->detect()) {
                printf("%s\n", source.c_str());
                std::vector<Instruction*> insns = compiler->compile(source);
                vm->run(insns);
                printf("\n");
                return;
            }
        }
    }
}

void Controller::initXN(void)
{
    ty::UserFactory::setContext(&ctxGlobal);
    user     = ty::UserFactory::get(1);
    world    = new ty::WorldContext(&ctxGlobal,
                                    ty::WorldContext::NODE_USE_IMAGE);
    renderer = new AbstractRenderer(world, user);
    im       = new DefaultInputMethod(user);
    compiler = Compiler::instance();
    vm       = VM::instance();
}

