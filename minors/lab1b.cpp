#include <GL/glut.h>

// Function to draw a line using Bresenham's Algorithm
void drawBresenhamLine(int x1, int y1, int x2, int y2) {
    int dx = abs(x2 - x1);
    int dy = abs(y2 - y1);

    int sx = x1 < x2 ? 1 : -1;
    int sy = y1 < y2 ? 1 : -1;

    int err = dx - dy;

    glBegin(GL_POINTS);
    while (true) {
        glVertex2i(x1, y1);  // Plot the point

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
    glEnd();
    glFlush();
}

// Display function for Bresenham
void displayBresenham() {
    glClear(GL_COLOR_BUFFER_BIT);
    drawBresenhamLine(-50, -50, 50, 50);  // Example: Drawing a line with Bresenham's algorithm
}

// OpenGL initialization
void initBresenham() {
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
    glutCreateWindow("Bresenham Line Drawing");
    initBresenham();
    glutDisplayFunc(displayBresenham);  // Use the Bresenham line drawing display
    glutMainLoop();
    return 0;
}
