#include <GL/glut.h>
#include <GL/glu.h>

GLUquadricObj *quadric;
float rotationAngle = 0.0f;

void init() {
    glClearColor(0.2f, 0.2f, 0.2f, 1.0f);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);

    // Set up light position and properties
    GLfloat light_position[] = { 1.0, 1.0, 1.0, 0.0 };
    GLfloat white_light[] = { 1.0, 1.0, 1.0, 1.0 };
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, white_light);

    // Initialize quadric object
    quadric = gluNewQuadric();
    gluQuadricNormals(quadric, GLU_SMOOTH);
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    // Position camera
    gluLookAt(0.0, 4.0, 10.0,  // Eye position
              0.0, 0.0, 0.0,   // Look at point
              0.0, 1.0, 0.0);  // Up vector

    // Rotate entire scene
    // glRotatef(rotationAngle, 0.0f, 1.0f, 0.0f);

    // Set material properties
    GLfloat material[] = { 0.7f, 0.7f, 0.7f, 1.0f };
    glMaterialfv(GL_FRONT, GL_DIFFUSE, material);

    // Draw sphere
    glPushMatrix();
    glTranslatef(-3.0f, 0.0f, 0.0f);
    glColor3f(1.0f, 0.0f, 0.0f);
    gluSphere(quadric, 1.0, 6, 6);
    glPopMatrix();

    // Draw cylinder
    glPushMatrix();
    glTranslatef(0.0f, 0.0f, 0.0f);
    glColor3f(0.0f, 1.0f, 0.0f);
    gluCylinder(quadric, 1.0, 1.0, 2.0, 6, 6);
    glPopMatrix();

    // Draw cone
    glPushMatrix();
    glTranslatef(3.0f, 0.0f, 0.0f);
    glRotatef(-90.0f, 1.0f, 0.0f, 0.0f);
    glColor3f(0.0f, 0.0f, 1.0f);
    gluCylinder(quadric, 1.0, 0.0, 2.0, 6, 6);
    glPopMatrix();

    glutSwapBuffers();
}

void reshape(int w, int h) {
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0, (float)w/(float)h, 0.1, 100.0);
}

void update(int value) {
    rotationAngle += 1.0f;
    if (rotationAngle > 360.0f) {
        rotationAngle -= 360.0f;
    }

    glutPostRedisplay();
    glutTimerFunc(16, update, 0);  // 60 FPS
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(800, 600);
    glutCreateWindow("OpenGL Quadric Shapes");

    init();

    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutTimerFunc(0, update, 0);

    glutMainLoop();
    return 0;
}
