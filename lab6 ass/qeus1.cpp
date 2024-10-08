#include <GL/glut.h>
#include <cmath>
#include <iostream>

// Function to initialize the OpenGL environment
void init() {
    glClearColor(0.0, 0.0, 0.0, 0.0);  // Set background color
    glMatrixMode(GL_PROJECTION);       // Set up the projection matrix
    gluOrtho2D(-500.0, 500.0, -500.0, 500.0);  // Define coordinate system
}

// Function to plot a point
void plotPoint(float x, float y) {
    glBegin(GL_POINTS);
    glVertex2f(x, y);
    glEnd();
}

// Function to draw parabola using midpoint algorithm
void drawParabola(float a) {
    // Initial decision parameter
    float x = 0.0;
    float y = 0.0;

    float p = 1 - 2 * a;  // Initial decision parameter for midpoint algorithm

    // First region where slope < 1 (y increment is slower)
    while (x <= 2 * a) {  // Arbitrarily decide to limit to 2a along x
        plotPoint(x, y);
        plotPoint(-x, y);  // Symmetry

        if (p < 0) {
            x += 1;
            p += 2 * x + 1;
        } else {
            x += 1;
            y += 1;
            p += 2 * x + 1 - 4 * a;
        }
    }

    // Second region where slope > 1 (y increment is faster)
    while (y <= 500) {  // Limit to an arbitrary y value
        plotPoint(x, y);
        plotPoint(-x, y);  // Symmetry

        if (p > 0) {
            y += 1;
            p -= 4 * a;
        } else {
            x += 1;
            y += 1;
            p += 2 * x + 1 - 4 * a;
        }
    }

    glFlush();
}

// Display callback function
void display() {
    glClear(GL_COLOR_BUFFER_BIT);  // Clear the display
    glColor3f(1.0, 1.0, 1.0);      // Set color to white

    // Call the draw parabola function with a=50 (adjust as needed)
    drawParabola(50.0);

    glFlush();
}

int main(int argc, char** argv) {
    // Initialize GLUT
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);  // Single buffer, RGB mode
    glutInitWindowSize(800, 800);                 // Set the window size
    glutCreateWindow("Parabola Drawing");         // Create the window with title

    init();  // Call initialization routine

    // Register the display callback function
    glutDisplayFunc(display);

    // Enter the GLUT main loop
    glutMainLoop();

    return 0;
}
