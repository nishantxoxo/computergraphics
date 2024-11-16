#include <GL/glut.h>

// Transformation parameters
float translateX = 0.0f, translateY = 0.0f;
float scaleX = 1.0f, scaleY = 1.0f;
float rotateAngle = 0.0f;

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    // Apply transformations
    glPushMatrix();
    // glTranslatef(translateX, translateY, 0.0);
    // Draw triangle
    glBegin(GL_TRIANGLES);
    glVertex2f(10.0f + translateX, 5.0f + translateY);
    glVertex2f(15.0f + translateX, 10.0f + translateY);
    glVertex2f(20.0f + translateX, 5.0f + translateY);
    glEnd();

    glPopMatrix();

    glFlush();
}

void init() {
    glClearColor(1.0, 1.0, 1.0, 1.0); // Set background color to white
    glColor3f(0.3, 0.3, 0.3);         // Set triangle color to gray
    glOrtho(0.0, 25.0, 0.0, 15.0, -1.0, 1.0); // Set orthographic projection
}

void keyboard(unsigned char key, int x, int y) {
    switch (key) {
        case 'w': translateY += 1.0f; break; // Move up
        case 's': translateY -= 1.0f; break; // Move down
        case 'a': translateX -= 1.0f; break; // Move left
        case 'd': translateX += 1.0f; break; // Move right
        /*case '+': scaleX += 0.1f; scaleY += 0.1f; break; // Scale up
        case '-': scaleX -= 0.1f; scaleY -= 0.1f; break; // Scale down
        case 'r': rotateAngle += 10.0f; break; // Rotate clockwise
        case 'e': rotateAngle -= 10.0f; break; // Rotate counterclockwise
        case 27: exit(0); // Press ESC to exit */
    }
    glutPostRedisplay();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutCreateWindow("2D Transformations on a Triangle");
    init();
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutMainLoop();
    return 0;
}
