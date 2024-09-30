#include <GL/glut.h>

// Define coordinates for points based on the image
float p1[] = {100, 100};  // Coordinates for p1
float p2[] = {150, 150};  // Coordinates for p2
float p3[] = {100, 200};  // Coordinates for p3
float p4[] = {200, 200};  // Coordinates for p4
float p5[] = {250, 150};  // Coordinates for p5
float p6[] = {200, 100};  // Coordinates for p6

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    // Set the color to draw lines (blue in this case)
    glColor3f(0.0, 0.0, 1.0);

    // Draw lines between points p1 -> p2 -> p3 -> p4 -> p5 -> p6 -> p1
    glBegin(GL_LINE_LOOP);
        glVertex2f(p1[0], p1[1]);
        glVertex2f(p2[0], p2[1]);
        glVertex2f(p3[0], p3[1]);
        glVertex2f(p4[0], p4[1]);
        glVertex2f(p5[0], p5[1]);
        glVertex2f(p6[0], p6[1]);
    glEnd();

    glFlush();
}

void init() {
    glClearColor(1.0, 1.0, 1.0, 1.0);  // Background color (white)
    glColor3f(0.0, 0.0, 0.0);          // Default draw color (black)
    gluOrtho2D(0.0, 300.0, 0.0, 300.0); // Set coordinate system (adjust to fit shape)
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Zigzag Shape");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
