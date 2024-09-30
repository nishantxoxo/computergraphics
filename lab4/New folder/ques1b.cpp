#include <GL/glut.h>
#include <iostream>

// Function to implement the Midpoint Line Algorithm
void drawMidpointLine(int x1, int y1, int x2, int y2) {
    int dx = abs(x2 - x1);
    int dy = abs(y2 - y1);

    int sx = (x1 < x2) ? 1 : -1;
    int sy = (y1 < y2) ? 1 : -1;

    bool swap = false;

    if (dy > dx) {
        std::swap(dx, dy);
        swap = true;
    }

    int decisionParam = 2 * dy - dx;
    int x = x1, y = y1;

    glBegin(GL_POINTS);
    for (int i = 0; i <= dx; i++) {
        glVertex2i(x, y);  // Plot the point

        while (decisionParam >= 0) {
            if (swap) {
                x += sx;
            } else {
                y += sy;
            }
            decisionParam -= 2 * dx;
        }

        if (swap) {
            y += sy;
        } else {
            x += sx;
        }
        decisionParam += 2 * dy;
    }
    glEnd();
}

// Wrapper to convert from normalized device coordinates to pixel space
void drawLine(float x1, float y1, float x2, float y2) {
    // Scaling to screen coordinates (500 x 500 window)
    int screenX1 = (int)((x1 + 1) * 250);  // scale x from [-1, 1] to [0, 500]
    int screenY1 = (int)((y1 + 1) * 250);  // scale y from [-1, 1] to [0, 500]
    int screenX2 = (int)((x2 + 1) * 250);
    int screenY2 = (int)((y2 + 1) * 250);

    drawMidpointLine(screenX1, screenY1, screenX2, screenY2);
}

// Display function to draw the figure using the Midpoint Line Algorithm
void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    // Draw the triangle using Midpoint Line Algorithm
    drawLine(-0.5f, -0.5f, 0.0f, 0.5f);  // Line from P1 to P2
    drawLine(0.0f, 0.5f, 0.5f, -0.5f);   // Line from P2 to P3
    drawLine(0.5f, -0.5f, -0.5f, -0.5f); // Line from P3 to P1

    // Draw the horizontal line using Midpoint Line Algorithm
    drawLine(-0.3f, 0.0f, 0.3f, 0.0f);   // Line from P4 to P5

    glFlush();
}

// Initialize OpenGL
void init() {
    glClearColor(0.0, 0.0, 0.0, 1.0);  // Set background color to black
    glColor3f(1.0, 1.0, 1.0);          // Set drawing color to white
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, 500, 0, 500);  // Set the orthographic projection
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);      // Set the window size
    glutInitWindowPosition(100, 100);  // Set the window position
    glutCreateWindow("Midpoint Line Algorithm - Triangle and Line");

    init();
    glutDisplayFunc(display);  // Set the display function
    glutMainLoop();            // Enter the GLUT event processing loop

    return 0;
}
