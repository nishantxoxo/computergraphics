#include <GL/glut.h>

// Define the initial triangle vertices
float vertices[3][2] = {
    {10.0f, 5.0f},
    {15.0f, 10.0f},
    {20.0f, 5.0f}
};

// Scaling factors
float scaleX = 1.0f;
float scaleY = 1.0f;

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    // Draw scaled triangle
    glBegin(GL_TRIANGLES);
    for (int i = 0; i < 3; i++) {
        // Apply scaling to each vertex
        float xScaled = vertices[i][0] * scaleX;
        float yScaled = vertices[i][1] * scaleY;
        glVertex2f(xScaled, yScaled);
    }
    glEnd();

    glFlush();
}

void init() {
    glClearColor(1.0, 1.0, 1.0, 1.0); // Set background color to white
    glColor3f(0.3, 0.3, 0.3);         // Set triangle color to gray
    glOrtho(0.0, 25.0, 0.0, 15.0, -1.0, 1.0); // Set orthographic projection
}

void keyboard(unsigned char key, int x, int y) {
    switch (key) {
        case 'x': scaleX += 0.1f; break; // Increase scale along x-axis
        case 'z': scaleX -= 0.1f; break; // Decrease scale along x-axis
        case 'y': scaleY += 0.1f; break; // Increase scale along y-axis
        case 't': scaleY -= 0.1f; break; // Decrease scale along y-axis
        case 27: exit(0); // Press ESC to exit
    }
    glutPostRedisplay();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Scaling a Triangle with sx and sy");
    init();
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutMainLoop();
    return 0;
}
