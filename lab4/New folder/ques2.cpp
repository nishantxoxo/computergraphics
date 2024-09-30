#include <GL/glut.h>
#include <iostream>
#include <cmath>

// Function to draw pixel points for a circle using symmetry
void plotPoints(int xc, int yc, int x, int y) {
    glBegin(GL_POINTS);
    glVertex2i(xc + x, yc + y);
    glVertex2i(xc - x, yc + y);
    glVertex2i(xc + x, yc - y);
    glVertex2i(xc - x, yc - y);
    glVertex2i(xc + y, yc + x);
    glVertex2i(xc - y, yc + x);
    glVertex2i(xc + y, yc - x);
    glVertex2i(xc - y, yc - x);
    glEnd();
}

// Mid-point Circle Algorithm
void midPointCircle(int xc, int yc, int r) {
    int x = 0, y = r;
    int d = 1 - r;

    // Initial point
    plotPoints(xc, yc, x, y);

    while (x <= y) {
        if (d < 0) {
            d = d + 2 * x + 3;
        } else {
            d = d + 2 * (x - y) + 5;
            y--;
        }
        x++;
        plotPoints(xc, yc, x, y);  // plot the calculated points
    }
    glFlush();  // Render the circle
}

void drawCircles() {
    glClear(GL_COLOR_BUFFER_BIT);

    // Draw Circle (a): r = 1, center = (0, 0)
    midPointCircle(0, 0, 10);

    // Draw Circle (b): r = 50, center = (-30, -40)
    midPointCircle(-30, -40, 50);
}

void init() {
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glColor3f(0.0, 0.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(-100, 100, -100, 100);  // Set coordinate system
}

int main(int argc, char **argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Mid-point Circle Algorithm");
    init();
    glutDisplayFunc(drawCircles);
    glutMainLoop();
    return 0;
}
