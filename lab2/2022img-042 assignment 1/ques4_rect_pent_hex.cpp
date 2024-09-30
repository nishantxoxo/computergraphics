#include <GL/glut.h>

// Function to render Fig. 3a (Rectangle)
void renderFigure3a() {
    glClear(GL_COLOR_BUFFER_BIT);

    // Draw points
    glBegin(GL_POINTS);
        glVertex2f(-0.5f, -0.3f);  // p1
        glVertex2f(-0.5f, 0.3f);   // p2
        glVertex2f(0.5f, 0.3f);    // p3
        glVertex2f(0.5f, -0.3f);   // p4
    glEnd();

    // Draw rectangle
    glBegin(GL_LINE_LOOP);
        glVertex2f(-0.5f, -0.3f);  // p1
        glVertex2f(-0.5f, 0.3f);   // p2
        glVertex2f(0.5f, 0.3f);    // p3
        glVertex2f(0.5f, -0.3f);   // p4
    glEnd();

    glFlush();
}

// Function to render Fig. 3b (Pentagon)
void renderFigure3b() {
    glClear(GL_COLOR_BUFFER_BIT);

    // Draw points
    glBegin(GL_POINTS);
        glVertex2f(0.0f, 0.5f);    // p1
        glVertex2f(-0.47f, 0.15f); // p2
        glVertex2f(-0.29f, -0.4f); // p3
        glVertex2f(0.29f, -0.4f);  // p4
        glVertex2f(0.47f, 0.15f);  // p5
    glEnd();

    // Draw pentagon
    glBegin(GL_LINE_LOOP);
        glVertex2f(0.0f, 0.5f);    // p1
        glVertex2f(-0.47f, 0.15f); // p2
        glVertex2f(-0.29f, -0.4f); // p3
        glVertex2f(0.29f, -0.4f);  // p4
        glVertex2f(0.47f, 0.15f);  // p5
    glEnd();

    glFlush();
}

// Function to render Fig. 3c (Hexagon)
void renderFigure3c() {
    glClear(GL_COLOR_BUFFER_BIT);

    // Draw points
    glBegin(GL_POINTS);
        glVertex2f(0.0f, 0.5f);    // p1
        glVertex2f(-0.43f, 0.25f); // p2
        glVertex2f(-0.43f, -0.25f);// p3
        glVertex2f(0.0f, -0.5f);   // p4
        glVertex2f(0.43f, -0.25f); // p5
        glVertex2f(0.43f, 0.25f);  // p6
    glEnd();

    // Draw hexagon
    glBegin(GL_LINE_LOOP);
        glVertex2f(0.0f, 0.5f);    // p1
        glVertex2f(-0.43f, 0.25f); // p2
        glVertex2f(-0.43f, -0.25f);// p3
        glVertex2f(0.0f, -0.5f);   // p4
        glVertex2f(0.43f, -0.25f); // p5
        glVertex2f(0.43f, 0.25f);  // p6
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

    // Create window for Fig. 3a (Rectangle)
    glutInitWindowSize(300, 300);
    glutCreateWindow("Fig. 3a");
    init();
    glutDisplayFunc(renderFigure3a);

    // Create window for Fig. 3b (Pentagon)
    glutInitWindowSize(300, 300);
    glutCreateWindow("Fig. 3b");
    init();
    glutDisplayFunc(renderFigure3b);

    // Create window for Fig. 3c (Hexagon)
    glutInitWindowSize(300, 300);
    glutCreateWindow("Fig. 3c");
    init();
    glutDisplayFunc(renderFigure3c);

    glutMainLoop();
    return 0;
}
