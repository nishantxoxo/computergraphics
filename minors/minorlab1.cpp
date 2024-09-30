#include <GL/glut.h>
#include <cmath>


void drawCircle(int xc, int yc, int r) {


    glBegin(GL_POINTS);
    for (int i = 0; i < 360; i++) {
        float theta = i * M_PI / 180; // Convert degree to radian
        float x = r * cos(theta);
        float y = r * sin(theta);
        glVertex2f(xc + x, yc + y);
    }
    glEnd();
}


void drawcart() {
    glClear(GL_COLOR_BUFFER_BIT);


    glBegin(GL_LINE_LOOP);
    glVertex2i(-50, -50);
    glVertex2i(50, -50);
    glVertex2i(50, 0);
    glVertex2i(-50, 0);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glVertex2i(-38, -38);
    glVertex2i(-13 , -38);
    glVertex2i(-13, -13);
    glVertex2i(-38, -13);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glVertex2i(13, -38);
    glVertex2i(38 , -38);
    glVertex2i(38, -13);
    glVertex2i(13, -13);
    glEnd();




    drawCircle(25, -62, 12);
    drawCircle(-25, -62, 12);
    glFlush();
}

void init() {
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glColor3f(0.0, 0.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(-100, 100, -100, 100);
}

int main(int argc, char **argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutCreateWindow("House Shape with Parallelogram and Triangle");
    init();
    glutDisplayFunc(drawcart);
    glutMainLoop();
    return 0;
}
