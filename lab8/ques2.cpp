#include <GL/glut.h>
#include <GL/glu.h>

GLUquadric *quadric;  // Quadric object for drawing the cylinder

void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // Set up the transformations and viewing angles
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    // Rotate the scene for better visibility
    glRotatef(30, 1.0, 0.0, 0.0);   // Rotate along the x-axis
    glRotatef(30, 0.0, 1.0, 0.0);   // Rotate along the y-axis

    // Draw the Sphere
    glPushMatrix();
    glTranslatef(-2.5, 0.0, 0.0);   // Move to the left
    glutWireTorus(1.0, 2.0 ,20, 20);    // Radius = 1.0, 20 slices, 20 stacks
    glPopMatrix();

    // Draw the Cone
    glPushMatrix();
    glTranslatef(0.0, 1.0, 1.0);    // Centered
    glutWireTeapot(1.0); // Base radius = 1.0, height = 2.0, 20 slices, 20 stacks
    glPopMatrix();

    // Draw the Cylinder using GLU quadrics
    glPushMatrix();
    glTranslatef(2.5, 0.0, 0.0);    // Move to the right
    glutSolidTetrahedron();  // Base radius = 1.0, top radius = 1.0, height = 2.0
    glPopMatrix();

    glutSwapBuffers();
}

void init() {
    quadric = gluNewQuadric();  // Create the quadric object for cylinder
    glEnable(GL_DEPTH_TEST);    // Enable depth testing for proper 3D rendering
}

void reshape(int width, int height) {
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0, (double)width / (double)height, 1.0, 20.0);  // Perspective projection
    gluLookAt(0.0, 0.0, 10.0,    // Camera position
              0.0, 0.0, 0.0,     // Look at the origin
              0.0, 1.0, 0.0);    // Up direction
}

int main(int argc, char **argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Quadric Surfaces - Sphere, Cone, Cylinder");

    init();  // Initialize quadric and other settings

    glutDisplayFunc(display);
    glutReshapeFunc(reshape);  // Handle window resizing

    glutMainLoop();
    return 0;
}
