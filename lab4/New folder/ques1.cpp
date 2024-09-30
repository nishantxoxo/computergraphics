#include <GL/glut.h>
#include <iostream>
#include <cmath>

struct Point {
    int x, y;
};

// Function to plot a point
void plot(int x, int y) {
    glBegin(GL_POINTS);
    glVertex2i(x, y);
    glEnd();
}

// Function to draw a line using the Midpoint (Bresenham's) algorithm
void drawMidpointLine(Point p1, Point p2) {
    int x1 = p1.x, y1 = p1.y;
    int x2 = p2.x, y2 = p2.y;

    int dx = x2 - x1;
    int dy = y2 - y1;

    int d = 2 * dy - dx;  // Decision variable

    int y = y1;

    for (int x = x1; x <= x2; x++) {
        plot(x, y);  // Plot the current point
        if (d > 0) {
            y++;         // Move y to the next pixel if decision variable is positive
            d = d + 2 * (dy - dx);  // Update the decision variable
        } else {
            d = d + 2 * dy;  // Update the decision variable if no y increment
        }
    }
    glFlush();  // Flush the OpenGL buffer to display the points
}

// Display function to render the line
void display() {
    glClear(GL_COLOR_BUFFER_BIT);  // Clear the screen

    Point p1 = {100, 100};  // Starting point
    Point p2 = {300, 200};  // Ending point

    drawMidpointLine(p1, p2);  // Draw the line using the Midpoint Line Algorithm

    glFlush();  // Ensure everything gets drawn
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
    glutCreateWindow("Midpoint Line Algorithm");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
