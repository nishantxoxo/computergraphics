#include <GL/glut.h>
#include <cmath>

// Function to render Fig. 1a
void renderFigure1a() {
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_POINTS);
        glVertex2f(0.0f, 0.0f);  // p1
    glEnd();
    glFlush();
}

// Function to render Fig. 1b
void renderFigure1b() {
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_POINTS);
        glVertex2f(0.0f, 0.5f);  // p1
        glVertex2f(-0.5f, -0.5f);  // p2
        glVertex2f(0.5f, -0.5f);   // p3
    glEnd();
    glFlush();
}

// Function to render Fig. 1c
void displayLetters() {
    glClear(GL_COLOR_BUFFER_BIT);

    // Set the color for the points (black)
    glColor3f(0.0, 0.0, 0.0);

    glPointSize(5.0); // Set the size of the points

    // Draw the letter 'C' using points
    glBegin(GL_POINTS);
    for (float angle = 30.0; angle <= 330.0; angle += 30.0) { // Fewer points
        float rad = angle * 3.14159 / 180.0;
        glVertex2f(-0.6f + 0.3f * cos(rad), 0.0f + 0.3f * sin(rad));
    }
    glEnd();

    // Draw the letter 'G' using points
    glBegin(GL_POINTS);
    for (float angle = 30.0; angle <= 330.0; angle += 30.0) { // Fewer points
        float rad = angle * 3.14159 / 180.0;
        glVertex2f(0.6f + 0.3f * cos(rad), 0.0f + 0.3f * sin(rad));
    }
    // Add the segment to close the 'G'
    glVertex2f(0.75f, -0.15f); // The horizontal stroke inside the 'G'
    glEnd();

    glFlush();
}

// Initialization function
void init() {
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);  // Set background to white
    glColor3f(0.2f, 0.4f, 0.8f);  // Set point color to blue
    glPointSize(8.0f);  // Set point size
    gluOrtho2D(-1.0, 1.0, -1.0, 1.0);  // Set coordinate system
}

// Main function
int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

    // Create windows for each figure
    glutInitWindowSize(300, 300);
    glutCreateWindow("Fig. 1a");
    init();
    glutDisplayFunc(renderFigure1a);

    glutInitWindowSize(300, 300);
    glutCreateWindow("Fig. 1b");
    init();
    glutDisplayFunc(renderFigure1b);

    glutInitWindowSize(300, 300);
    glutCreateWindow("Fig. 1c");
    init();
    glutDisplayFunc(displayLetters);

    glutMainLoop();
}
