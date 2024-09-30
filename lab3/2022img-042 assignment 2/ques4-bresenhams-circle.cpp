#include <GL/glut.h>
#include <cmath> // For abs() function

// Function to plot a point
void plot(int x, int y) {
    glBegin(GL_POINTS);
    glVertex2i(x, y);
    glEnd();
}

// Bresenham's Circle Drawing Algorithm
void bresenhamCircle(int centerX, int centerY, int radius) {
    int x = radius;
    int y = 0;
    int p = 1 - radius;  // Initial decision parameter

    // Draw the eight octants
    while (x >= y) {
        // Plot all eight points
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

// Function to initialize OpenGL environment
void init() {
    glClearColor(0.0, 0.0, 0.0, 0.0);  // Set background color to black
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, 512.0, 0.0, 512.0);  // Set the orthographic projection
}

// Display callback function
void display() {
    glClear(GL_COLOR_BUFFER_BIT);  // Clear the window

    glColor3f(1.0, 1.0, 1.0);  // Set drawing color to white

    int centerX = 256;  // Center of the circle
    int centerY = 256;
    int radius = 100;   // Radius of the circle

    // Draw the circle using Bresenham's algorithm
    bresenhamCircle(centerX, centerY, radius);

    glFlush();  // Force execution of OpenGL commands
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(512, 512);  // Set window size
    glutCreateWindow("Bresenham's Circle Algorithm");  // Create window
    init();
    glutDisplayFunc(display);  // Register display callback
    glutMainLoop();  // Enter the GLUT event loop

    return 0;
}
