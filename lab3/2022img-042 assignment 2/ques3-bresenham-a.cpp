#include <GL/glut.h>
#include <iostream>
#include <cmath>
#include <chrono>  // For time measurement

struct Point {
    int x, y;
};

// Function to draw a line using Bresenham's algorithm
void drawBresenhamLine(Point p1, Point p2) {
    int x1 = p1.x, y1 = p1.y;
    int x2 = p2.x, y2 = p2.y;

    int dx = abs(x2 - x1), dy = abs(y2 - y1);
    int sx = (x1 < x2) ? 1 : -1;  // Step for x
    int sy = (y1 < y2) ? 1 : -1;  // Step for y
    int err = dx - dy;

    glBegin(GL_POINTS);
    while (true) {
        glVertex2i(x1, y1);  // Plot the point

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

// Wrapper function to measure time taken by Bresenham's algorithm
void timedBresenhamLine(Point p1, Point p2) {
    auto start = std::chrono::high_resolution_clock::now();  // Start time
    drawBresenhamLine(p1, p2);  // Draw the line
    auto end = std::chrono::high_resolution_clock::now();  // End time

    std::chrono::duration<double, std::micro> time_taken = end - start;  // Calculate duration
    std::cout << "Time taken to draw line from (" << p1.x << ", " << p1.y << ") to ("
              << p2.x << ", " << p2.y << ") is " << time_taken.count() << " microseconds." << std::endl;
}

// Display function to render all the lines
void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    Point p1 = {100, 100};
    Point p2 = {150, 200};
    Point p3 = {200, 300};
    Point p4 = {250, 200};
    Point p5 = {300, 100};

    // Draw the lines and measure time
    timedBresenhamLine(p1, p2);  // Line between p1 and p2
    timedBresenhamLine(p2, p3);  // Line between p2 and p3
    timedBresenhamLine(p3, p4);  // Line between p3 and p4
    timedBresenhamLine(p4, p5);  // Line between p4 and p5
    timedBresenhamLine(p2, p4);  // Line between p2 and p4 (horizontal)
}

// Initialize OpenGL
void init() {
    glClearColor(1.0, 1.0, 1.0, 1.0);  // Set background to white
    glColor3f(0.0, 0.0, 0.0);  // Set drawing color to black
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, 400, 0, 400);  // Set the orthographic view
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);  // Set the window size
    glutInitWindowPosition(100, 100);  // Set the window position
    glutCreateWindow("Bresenham Line Algorithm with Timing");
    init();
    glutDisplayFunc(display);
    glutMainLoop();  // Enter the GLUT event processing loop
    return 0;
}
