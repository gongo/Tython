#include "Controller.h"

int main(int argc, char **argv)
{
    Controller *controller = new Controller();
    controller->main();

    delete controller;

    return 0;
}
