#include <GL/glut.h>


void drawRectangle(float x1, float y1, float x2, float y2) {
    glBegin(GL_LINE_LOOP);
    glVertex2f(x1, y1);
    glVertex2f(x2, y1);
    glVertex2f(x2, y2);
    glVertex2f(x1, y2);
    glEnd();
}

// Function to draw a trapezoid
void drawTrapezoid(float x1, float y1, float x2, float y2, float x3, float y3, float x4, float y4) {
    glBegin(GL_LINE_LOOP);  // Start drawing the outline of a trapezoid
    glVertex2f(x1, y1);  // Bottom-left
    glVertex2f(x2, y2);  // Bottom-right
    glVertex2f(x3, y3);  // Top-right
    glVertex2f(x4, y4);  // Top-left
    glEnd();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    // Base rectangle (bottom part)
    drawRectangle(-0.7f, -0.5f, 0.7f, -0.2f);

    // Trapezoid (middle part)
    drawTrapezoid(-0.7f, -0.2f, 0.7f, -0.2f, 0.4f, 0.2f, -0.4f, 0.2f);

    // Outer rectangle (top part)
    drawRectangle(-0.4f, 0.2f, 0.4f, 0.5f);

    // Inner rectangle (top inner part)
    drawRectangle(-0.3f, 0.3f, 0.3f, 0.4f);

    glFlush();  // Ensure all OpenGL commands are executed
}

void init() {
    glClearColor(1.0, 1.0, 1.0, 1.0);  // Set background color to white
    glColor3f(0.0, 0.0, 0.0);          // Set drawing color to black
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-1, 1, -1, 1);  // Set the coordinate system
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);  // Window size
    glutInitWindowPosition(100, 100);  // Window position
    glutCreateWindow("Geometric Shape Drawing");
    init();
    glutDisplayFunc(display);  // Set the display function
    glutMainLoop();  // Enter the GLUT event loop
    return 0;
}
