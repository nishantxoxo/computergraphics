#include <GL/glut.h>
#include <iostream>
using namespace std;

// Function to plot a point
void plot(int x, int y) {
    glBegin(GL_POINTS);
    glVertex2i(x, y);
    glEnd();
    glFlush();
}


void drawLine(int x1, int y1, int x2, int y2) {
    int dx = abs(x2 - x1);
    int dy = abs(y2 - y1);

    int sx = (x1 < x2) ? 1 : -1;
    int sy = (y1 < y2) ? 1 : -1;

    int err = dx - dy;

    while (true) {
        plot(x1, y1);

        if (x1 == x2 && y1 == y2) break;

        int e2 = 2 * err;

        if (e2 > -dy) {
            err -= dy;
            x1 += sx;
        }

        if (e2 < dx) {
            err += dx;
            y1 += sy;
        }
    }
}


void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    // Use default start and end points
    //int x1 = 450, y1 = 100, x2 = 100, y2 = 300;  // Example of shallow slope
   // int x1 = 100, y1 = 100, x2 = 200, y2 = 400; //Steep Positive Slope
   // int x1 = 400, y1 = 100, x2 = 100, y2 = 300;   // negative
    int x1 = 50, y1 = 200, x2 = 450, y2 = 200;  //0 slope
    // int x1 = 100, y1 = 100, x2 = 200, y2 = 400;  // Example of steep slope

    drawLine(x1, y1, x2, y2);
}

// Initialize OpenGL
void init() {
    glClearColor(1.0, 1.0, 1.0, 0.0);
    glColor3f(0.0, 0.0, 0.0);
    glPointSize(2.0);
    gluOrtho2D(0.0, 500.0, 0.0, 500.0);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Midpoint Line Algorithm");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
}
