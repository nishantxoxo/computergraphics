#include <GL/glut.h>
#include <iostream>
#include <cmath>

struct Point {
    int x, y;
};

// Function to draw a line using Bresenham's line algorithm
void drawBresenhamLine(Point p1, Point p2) {
    int x1 = p1.x, y1 = p1.y;
    int x2 = p2.x, y2 = p2.y;

    int dx = abs(x2 - x1), dy = abs(y2 - y1);
    int sx = (x1 < x2) ? 1 : -1;  // Step for x
    int sy = (y1 < y2) ? 1 : -1;  // Step for y
    int err = dx - dy;

    glBegin(GL_POINTS);
    while (true) {
        glVertex2i(x1, y1);  // Draw the point

        if (x1 == x2 && y1 == y2) break;  // End point reached

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
    drawBresenhamLine(p1, p2); // p1 -> p2 (top side)
    drawBresenhamLine(p2, p6); // p2 -> p6 (right diagonal down)
    drawBresenhamLine(p6, p1); // p6 -> p1 (left diagonal down)

    // Draw inner triangle
    drawBresenhamLine(p3, p4); // p3 -> p4 (left diagonal down)
    drawBresenhamLine(p4, p5); // p4 -> p5 (bottom side)
    drawBresenhamLine(p5, p3); // p5 -> p3 (right diagonal up)

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
    glutCreateWindow("Bresenham Line Algorithm - Star Shape");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
