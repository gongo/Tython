#include <stdexcept>
#include <GLUT/glut.h>
#include "Controller.h"
#include <iostream>

Controller *controller;

const GLfloat vertex[] = {
    -0.0, 0.9, 0.9, 0.9, 0.0, -0.9
};

int main(int argc, char **argv)
{
    try {
        if (argc > 1) {
            controller = new Controller(argv[1]);
        } else {
            controller = new Controller();
        }
        controller->main();
        delete controller;
    } catch (std::runtime_error e) {
        std::cout << e.what() << std::endl;
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}
