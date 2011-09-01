#include <GLUT/glut.h>
#include "Controller.h"

Controller *controller;

const GLfloat vertex[] = {
    -0.0, 0.9, 0.9, 0.9, 0.0, -0.9
};

void glutDisplay(void)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    controller->main();
    glFlush();
    glutSwapBuffers();
}

void onIdleDisplay(void)
{
    glutPostRedisplay();
}

void initGL(int *argc, char* argv[])
{
    glutInit(argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("hoge");
    glutInitWindowSize(640, 480);
    glClearColor(0.0f, 0.0f, 0.0f, 0.5f);
    glEnableClientState(GL_VERTEX_ARRAY);
    glDisableClientState(GL_COLOR_ARRAY);

    glutDisplayFunc(glutDisplay);
    glutIdleFunc(onIdleDisplay);

    // glViewport(0, 0, 640, 480);
    // glLoadIdentity();
    glOrtho(0.0, 640, 480, 0.0, -1.0, 1.0);
    //glOrtho(0, depthMD.XRes(), depthMD.YRes(), 0, -1.0, 1.0);

    if (!glutExtensionSupported("GL_ARB_texture_non_power_of_two")) {
        printf("hogehoge...\n");
        exit(1);
    }
}

int main(int argc, char **argv)
{
    initGL(&argc, argv);
    controller = new Controller();
    glutMainLoop();
    return 0;
}
