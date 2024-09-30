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

// Display function to render the star
void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    Point p1 = {180, 320}; // left top point
    Point p2 = {320, 320}; // right top point
    Point p3 = {250, 380}; // top peak point
    Point p4 = {180, 180}; // left bottom point
    Point p5 = {320, 180}; // right bottom point
    Point p6 = {250, 120}; // bottom peak point

    // Draw outer triangle (inverted)
    drawDDALine(p1, p2); // p1 -> p2 (top side)
    drawDDALine(p2, p6); // p2 -> p6 (right diagonal down)
    drawDDALine(p6, p1); // p6 -> p1 (left diagonal down)

    // Draw inner triangle
    drawDDALine(p3, p4); // p3 -> p4 (left diagonal down)
    drawDDALine(p4, p5); // p4 -> p5 (bottom side)
    drawDDALine(p5, p3); // p5 -> p3 (right diagonal up)

    glFlush();
}

// Initialize OpenGL settings
void init() {
    glClearColor(1.0, 1.0, 1.0, 1.0);  // Set background color to white
    glColor3f(0.0, 0.0, 0.0);          // Set drawing color to black
    glMatrixMode(GL_PROJECTION);       // Select the projection matrix
    glLoadIdentity();                  // Reset the projection matrix
    gluOrtho2D(0, 400, 0, 400);        // Set up a 2D orthographic viewing region
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("DDA Line Algorithm - Star Shape");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
