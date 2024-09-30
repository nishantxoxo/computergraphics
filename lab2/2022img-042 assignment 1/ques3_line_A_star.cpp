#include <GL/glut.h>

// Function to render Fig. 2a
void renderFigure2a() {
    glClear(GL_COLOR_BUFFER_BIT);

    // Draw points
    glBegin(GL_POINTS);
        glVertex2f(-0.5f, -0.5f);  // p1
        glVertex2f(0.5f, 0.5f);    // p2
    glEnd();

    // Draw line segment
    glBegin(GL_LINES);
        glVertex2f(-0.5f, -0.5f);  // p1
        glVertex2f(0.5f, 0.5f);    // p2
    glEnd();

    glFlush();
}

// Function to render Fig. 2b
void renderFigure2b() {
    glClear(GL_COLOR_BUFFER_BIT);

    // Draw points
    glBegin(GL_POINTS);
        glVertex2f(-0.5f, -0.5f);  // p1
        glVertex2f(-0.3f, 0.3f);   // p2
        glVertex2f(0.0f, 0.6f);    // p3
        glVertex2f(0.3f, 0.3f);    // p4
        glVertex2f(0.5f, -0.5f);   // p5
    glEnd();

    // Draw line segments
   glBegin(GL_LINES);
        glVertex2f(-0.5f, -0.5f);  // p1
        glVertex2f(-0.3f, 0.3f);   // p2

        glVertex2f(-0.3f, 0.3f);   // p2
        glVertex2f(0.0f, 0.6f);    // p3

        glVertex2f(0.0f, 0.6f);    // p3
        glVertex2f(0.3f, 0.3f);    // p4

        glVertex2f(0.3f, 0.3f);    // p4
        glVertex2f(0.5f, -0.5f);   // p5

        // Orange horizontal line
        glColor3f(1.0f, 0.5f, 0.0f);  // Orange
        glVertex2f(-0.3f, 0.3f);   // p2
        glVertex2f(0.3f, 0.3f);    // p4
    glEnd();

    glFlush();
}

// Function to render Fig. 2c
void renderFigure2c() {
    glClear(GL_COLOR_BUFFER_BIT);

    // Draw points
    glBegin(GL_POINTS);
        glVertex2f(-0.5f, -0.3f);  // p1
        glVertex2f(0.5f, -0.3f);   // p2
        glVertex2f(0.0f, 0.6f);    // p3
        glVertex2f(-0.3f, -0.6f);  // p4
        glVertex2f(0.0f, -0.9f);   // p5
        glVertex2f(0.3f, -0.6f);   // p6
    glEnd();

    // Draw star (overlapping triangles)
    glBegin(GL_LINES);
        glVertex2f(-0.5f, -0.3f);  // p1
        glVertex2f(0.5f, -0.3f);   // p2

        glVertex2f(0.5f, -0.3f);   // p2
        glVertex2f(0.0f, 0.6f);    // p3

        glVertex2f(0.0f, 0.6f);    // p3
        glVertex2f(-0.5f, -0.3f);  // p1

        glVertex2f(-0.3f, -0.6f);  // p4
        glVertex2f(0.3f, -0.6f);   // p6

        glVertex2f(0.3f, -0.6f);   // p6
        glVertex2f(0.0f, -0.9f);   // p5

        glVertex2f(0.0f, -0.9f);   // p5
        glVertex2f(-0.3f, -0.6f);  // p4
    glEnd();

    glFlush();
}

void displayStar() {
    glClear(GL_COLOR_BUFFER_BIT);

    // Set the color of the star
    glColor3f(0.0, 0.0, 1.0);

   // Begin drawing the star using lines
    glBegin(GL_LINES);

    // Define points for the star
    glVertex2f(0.0f, 0.5f);   // P1
    glVertex2f(0.2f, -0.5f);  // P4

    glVertex2f(0.2f, -0.5f);  // P4
    glVertex2f(-0.5f, 0.2f);  // P2

    glVertex2f(-0.5f, 0.2f);  // P2
    glVertex2f(0.5f, 0.2f);   // P5

    glVertex2f(0.5f, 0.2f);   // P5
    glVertex2f(-0.2f, -0.5f); // P3

    glVertex2f(-0.2f, -0.5f); // P3
    glVertex2f(0.0f, 0.5f);   // P1

    glEnd();

    glFlush();
}


// Initialization function
void init() {
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);  // Set background to white
    glColor3f(0.2f, 0.4f, 0.8f);  // Set point and line color to blue
    glPointSize(8.0f);  // Set point size
    gluOrtho2D(-1.0, 1.0, -1.0, 1.0);  // Set coordinate system
}

// Main function
int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

    // Create window for Fig. 2a
    glutInitWindowSize(300, 300);
    glutCreateWindow("Fig. 2a");
    init();
    glutDisplayFunc(renderFigure2a);

    // Create window for Fig. 2b
    glutInitWindowSize(300, 300);
    glutCreateWindow("Fig. 2b");
    init();
    glutDisplayFunc(renderFigure2b);

    // Create window for Fig. 2c
    glutInitWindowSize(300, 300);
    glutCreateWindow("Fig. 2c");
    init();
    glutDisplayFunc(displayStar);

    glutMainLoop();
    return 0;
}
