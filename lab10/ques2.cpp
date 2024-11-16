#include <GL/glut.h>
#include <cmath>

// Convert degrees to radians
#define DEG2RAD (M_PI/180.0)

void rotatePoint(float& x, float& y) {
    float angle = 30.0f * DEG2RAD; // 30 degrees in radians
    float newX = x * cos(angle) - y * sin(angle);
    float newY = x * sin(angle) + y * cos(angle);
    x = -newX; // Apply the original reflection
    y = -newY; // Apply the original reflection
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    // Draw the cheese slice (quarter circle) in grey color
    glColor3f(0.5f, 0.5f, 0.5f); // Grey color for the cheese
    glBegin(GL_POLYGON);
    for (int i = 0; i <= 100; ++i) {
        float angle = M_PI / 2 * i / 100.0f; // Quarter circle
        float x = 2.0f * cos(angle);
        float y = 2.0f * sin(angle);
        rotatePoint(x, y); // Rotate the point
        glVertex2f(x, y);
    }
    glVertex2f(0.0f, 0.0f); // Center point
    glEnd();

    // Draw the oval hole (cut-out area)
    glColor3f(1.0f, 1.0f, 1.0f); // White color to represent the hole
    glBegin(GL_POLYGON);
    for (int i = 0; i <= 100; ++i) {
        float angle = 2 * M_PI * i / 100.0f;
        float x = 0.8f + 0.5f * cos(angle);
        float y = 1.0f + 0.3f * sin(angle);
        rotatePoint(x, y);
        glVertex2f(x, y);
    }
    glEnd();

    // Draw the top semi-circular indentation
    glBegin(GL_POLYGON);
    for (int i = 0; i <= 100; ++i) {
        float angle = M_PI * i / 100.0f; // Half-circle
        float x = 1.0f + 0.4f * cos(angle);
        float y = 2.0f + 0.4f * sin(angle);
        rotatePoint(x, y);
        glVertex2f(x, y);
    }
    glEnd();

    // Draw the boundary semi-circular indentation (outer edge)
    glBegin(GL_POLYGON);
    for (int i = 0; i <= 100; ++i) {
        float angle = M_PI * i / 100.0f; // Half-circle
        float x = 1.5f + 0.2f * cos(angle);
        float y = 0.2f * sin(angle);
        rotatePoint(x, y);
        glVertex2f(x, y);
    }
    glEnd();

    glFlush();
}

void init() {
    glClearColor(1.0, 1.0, 1.0, 1.0); // Set background color to white
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(-3.0, 3.0, -3.0, 3.0); // Set coordinate system for display
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(600, 600);
    glutCreateWindow("Rotated Cheese-like Shape with Multiple Cut-outs");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
