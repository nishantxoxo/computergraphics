#include <GL/glut.h>
#include <cmath>

// Define the initial triangle vertices
float vertices[3][2] = {
    {10.0f, 5.0f},
    {15.0f, 10.0f},
    {20.0f, 5.0f}
};

float rotateAngle = 0.0f; // Rotation angle in degrees

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    // Calculate the rotation angle in radians
    float angleRad = rotateAngle * (M_PI / 180.0f);

    // Calculate cosine and sine once for the given angle
    float cosTheta = cos(angleRad);
    float sinTheta = sin(angleRad);

    // Draw rotated triangle
    glBegin(GL_TRIANGLES);
    for (int i = 0; i < 3; i++) {
        // Apply rotation to each vertex
        float x = vertices[i][0];
        float y = vertices[i][1];
        float xRotated = x * cosTheta - y * sinTheta;
        float yRotated = x * sinTheta + y * cosTheta;
        glVertex2f(xRotated, yRotated);
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
        case 'r': rotateAngle += 10.0f; break; // Rotate clockwise
        case 'e': rotateAngle -= 10.0f; break; // Rotate counterclockwise
        case 27: exit(0); // Press ESC to exit
    }
    glutPostRedisplay();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Manual Rotation of a Triangle Using Cosine and Sine");
    init();
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutMainLoop();
    return 0;
}
