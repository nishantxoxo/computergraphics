#include <GL/glut.h>

void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // Set up the transformations and viewing angles
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    // Rotate the scene for better visibility
    glRotatef(30, 1.0, 0.0, 0.0);   // Rotate along the x-axis
    glRotatef(30, 0.0, 1.0, 0.0);   // Rotate along the y-axis

    // Global scaling to make the whole scene smaller
    glScalef(0.5, 0.5, 0.5);        // Scale down the entire scene to fit within the window

    // Draw a smaller Tetrahedron
    glPushMatrix();
    glTranslatef(-3.0, -1.0, 0.0);  // Translate to position (left)
    glutWireTetrahedron();
    glPopMatrix();

    // Draw a smaller Cube
    glPushMatrix();
    glTranslatef(0.0, -1.0, 0.0);   // No translation (center)
    glutWireCube(1.0);
    glPopMatrix();

    // Draw a smaller Octahedron
    glPushMatrix();
    glTranslatef(3.0, -1.0, 0.0);   // Move to the right
    glutWireOctahedron();
    glPopMatrix();

    // Draw a smaller Dodecahedron
    glPushMatrix();
    glTranslatef(-1.5, 2.0, 0.0);   // Move up and to the left
    glutWireDodecahedron();
    glPopMatrix();

    // Draw a smaller Icosahedron
    glPushMatrix();
    glTranslatef(1.5, 2.0, 0.0);    // Move up and to the right
    glutWireIcosahedron();
    glPopMatrix();

    glutSwapBuffers();
}

void reshape(int width, int height) {
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    // Adjust the field of view and viewing perspective
    gluPerspective(45.0, (double)width / (double)height, 1.0, 20.0);  // Field of view, aspect ratio, near and far planes

    // Move the camera back to view the entire scene
    gluLookAt(0.0, 0.0, 5.0,    // Camera position
              0.0, 0.0, 0.0,     // Look at origin
              0.0, 1.0, 0.0);    // Up direction
}

int main(int argc, char **argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Fitting Polyhedra");

    glEnable(GL_DEPTH_TEST);  // Enable depth testing for 3D rendering
    glutDisplayFunc(display);
    glutReshapeFunc(reshape); // Handle window resizing

    glutMainLoop();
    return 0;
}
