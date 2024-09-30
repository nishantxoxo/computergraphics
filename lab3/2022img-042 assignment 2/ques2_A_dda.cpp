#include <GL/glut.h>
#include <iostream>
#include <cmath>

struct Point {
    float x, y;
};

// Function to draw a line using the DDA algorithm
void drawDDALine(Point p1, Point p2) {
    float dx = p2.x - p1.x;
    float dy = p2.y - p1.y;
    float steps = (fabs(dx) > fabs(dy)) ? fabs(dx) : fabs(dy);

    float Xinc = dx / steps;
    float Yinc = dy / steps;

    float x = p1.x;
    float y = p1.y;

    glBegin(GL_POINTS);
    for (int i = 0; i <= steps; i++) {
        glVertex2f(x, y);
        x += Xinc;
        y += Yinc;
    }
    glEnd();
    glFlush();
}

// Display function to render all the lines
void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    Point p1 = {100, 100};
    Point p2 = {150, 200};
    Point p3 = {200, 300};
    Point p4 = {250, 200};
    Point p5 = {300, 100};

    // Draw the lines based on the uploaded image
    drawDDALine(p1, p2);  // Line between p1 and p2
    drawDDALine(p2, p3);  // Line between p2 and p3
    drawDDALine(p3, p4);  // Line between p3 and p4
    drawDDALine(p4, p5);  // Line between p4 and p5
    drawDDALine(p2, p4);  // Line between p2 and p4 (horizontal)
}

// Initialize OpenGL
void init() {
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glColor3f(0.0, 0.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, 400, 0, 400);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("DDA Line Algorithm");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
