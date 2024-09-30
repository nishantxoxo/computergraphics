#include <GL/glut.h>
#include <math.h>

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    // Draw monitor (shape a)
    glColor3f(0.0, 0.0, 0.0);  // Set color to black

    // Monitor base

    // Draw house (shape b)
    glColor3f(0.0, 0.0, 0.0);  // Set color to black

    // House body
    glBegin(GL_LINE_LOOP);
    glVertex2f(-0.9, -0.5);
    glVertex2f(0.3, -0.5);
    glVertex2f(0.9, -0.5);
    glVertex2f(0.9, 0.1);
    glVertex2f(0.3, 0.1);
    glVertex2f(-0.9, 0.1);

    glEnd();

    glBegin(GL_LINE_STRIP);
    glVertex2f(0.3, 0.1);
    glVertex2f(0.3, -0.5);
    glEnd();

    glBegin(GL_LINE_STRIP);
    glVertex2f(-0.6, 0.5);
    glVertex2f(-0.9, 0.1);
    glEnd();
    glBegin(GL_LINE_STRIP);
    glVertex2f(-0.6, 0.5);
    glVertex2f(0.6, 0.5);
    glEnd();

    // House roof
    glBegin(GL_LINE_STRIP);
    glVertex2f(0.3, 0.1);
    glVertex2f(0.6, 0.5);
    glVertex2f(0.9, 0.1);
    glEnd();

    // House window (circle)
    float theta;
    glBegin(GL_LINE_LOOP);
    for(int i = 0; i < 360; i++) {
        theta = i * 3.14159 / 180;
        glVertex2f(0.6 + 0.2 * cos(theta), -0.2 + 0.2 * sin(theta));
    }
    glEnd();

    glFlush();
}

void init() {
    glClearColor(1.0, 1.0, 1.0, 1.0);  // Set background color to white
    gluOrtho2D(-1.0, 1.0, -1.0, 1.0);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutCreateWindow("Shapes Display");
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(50, 50);
    glutDisplayFunc(display);
    init();
    glutMainLoop();

}
