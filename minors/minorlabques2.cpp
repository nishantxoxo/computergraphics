#include <GL/glut.h>
#include <cmath> // For abs() function


void plot(int x, int y) {
    glBegin(GL_POINTS);
    glVertex2i(x, y);
    glEnd();
}


void bresenhamCircle(int centerX, int centerY, int radius) {
    int x = radius;
    int y = 0;
    int p = 1 - radius;


    while (x >= y) {

        plot(centerX + x, centerY + y);
        plot(centerX - x, centerY + y);
        plot(centerX + x, centerY - y);
        plot(centerX - x, centerY - y);
        plot(centerX + y, centerY + x);
        plot(centerX - y, centerY + x);
        plot(centerX + y, centerY - x);
        plot(centerX - y, centerY - x);

        y++;
        if (p < 0) {
            p += 2 * y + 1;
        } else {
            x--;
            p += 2 * (y - x) + 1;
        }
    }
}


void init() {
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, 512.0, 0.0, 512.0);
}


void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(1.0, 1.0, 1.0);

    bresenhamCircle(100, 100, 50);
    bresenhamCircle(200, 100, 50);
    bresenhamCircle(150, 187, 50);

    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(512, 512);
    glutCreateWindow("Bresenham's Circle Algorithm");
    init();
    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}
