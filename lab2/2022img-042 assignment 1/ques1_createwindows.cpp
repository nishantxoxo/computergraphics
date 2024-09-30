#include <GL/glut.h>
#include <iostream>

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glFlush();
}

void createWindow(int width, int height, const char* title) {
    glutInitWindowSize(width, height);
    glutCreateWindow(title);
    glutDisplayFunc(display);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

    // Create windows with different resolutions
    createWindow(128, 128, "Window 128x128");
    createWindow(256, 256, "Window 256x256");
    createWindow(512, 512, "Window 512x512");
    createWindow(256, 360, "Window 256x360");

    glutMainLoop();

    return 0;
}
