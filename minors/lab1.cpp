#include <GL/glut.h>
#include <cmath>

// Function to draw a line using DDA Algorithm
void drawDDALine(int x1, int y1, int x2, int y2) {
    float dx = x2 - x1;
    float dy = y2 - y1;

    // Calculate the number of steps
    int steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy);

    // Calculate the increments for each step
    float xInc = dx / steps;
    float yInc = dy / steps;

    float x = x1;
    float y = y1;

    glBegin(GL_POINTS);
    for (int i = 0; i <= steps; i++) {
        glVertex2i(round(x), round(y));  // Plot the points
        x += xInc;
        y += yInc;
    }
    glEnd();
    glFlush();
}

// Display function for DDA
void displayDDA() {
    glClear(GL_COLOR_BUFFER_BIT);
    drawDDALine(20, 20, -50,50);  // Example: Drawing a line with DDA
}

// OpenGL initialization
void init() {
    glClearColor(1.0, 1.0, 1.0, 1.0);  // White background
    glColor3f(0.0, 0.0, 0.0);          // Black color
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-100, 100, -100, 100);  // Coordinate system from -100 to 100
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);  // Window size
    glutCreateWindow("DDA Line Drawing");
    init();
    glutDisplayFunc(displayDDA);   // Use the DDA line drawing display
    glutMainLoop();
    return 0;
}
