#include <GL/glut.h>

// Variables to store rotation angles
float cubeAngle = 0.0f;
float pyramidAngle = 0.0f;

// Function to draw the cube
void drawCube() {
    glBegin(GL_QUADS);

    // Front face (red)
    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex3f(-1.0f, -1.0f, 1.0f);
    glVertex3f( 1.0f, -1.0f, 1.0f);
    glVertex3f( 1.0f,  1.0f, 1.0f);
    glVertex3f(-1.0f,  1.0f, 1.0f);

    // Back face (green)
    glColor3f(0.0f, 1.0f, 0.0f);
    glVertex3f(-1.0f, -1.0f, -1.0f);
    glVertex3f(-1.0f,  1.0f, -1.0f);
    glVertex3f( 1.0f,  1.0f, -1.0f);
    glVertex3f( 1.0f, -1.0f, -1.0f);

    // Left face (blue)
    glColor3f(0.0f, 0.0f, 1.0f);
    glVertex3f(-1.0f, -1.0f, -1.0f);
    glVertex3f(-1.0f, -1.0f,  1.0f);
    glVertex3f(-1.0f,  1.0f,  1.0f);
    glVertex3f(-1.0f,  1.0f, -1.0f);

    // Right face (yellow)
    glColor3f(1.0f, 1.0f, 0.0f);
    glVertex3f(1.0f, -1.0f, -1.0f);
    glVertex3f(1.0f,  1.0f, -1.0f);
    glVertex3f(1.0f,  1.0f,  1.0f);
    glVertex3f(1.0f, -1.0f,  1.0f);

    // Top face (cyan)
    glColor3f(0.0f, 1.0f, 1.0f);
    glVertex3f(-1.0f,  1.0f, -1.0f);
    glVertex3f(-1.0f,  1.0f,  1.0f);
    glVertex3f( 1.0f,  1.0f,  1.0f);
    glVertex3f( 1.0f,  1.0f, -1.0f);

    // Bottom face (magenta)
    glColor3f(1.0f, 0.0f, 1.0f);
    glVertex3f(-1.0f, -1.0f, -1.0f);
    glVertex3f( 1.0f, -1.0f, -1.0f);
    glVertex3f( 1.0f, -1.0f,  1.0f);
    glVertex3f(-1.0f, -1.0f,  1.0f);

    glEnd();
}

// Function to draw the pyramid
void drawPyramid() {
    glBegin(GL_TRIANGLES);

    // Front face (blue)
    glColor3f(0.0f, 0.0f, 1.0f);
    glVertex3f( 0.0f,  1.0f,  0.0f);
    glVertex3f(-1.0f, -1.0f,  1.0f);
    glVertex3f( 1.0f, -1.0f,  1.0f);

    // Right face (green)
    glColor3f(0.0f, 1.0f, 0.0f);
    glVertex3f( 0.0f,  1.0f,  0.0f);
    glVertex3f( 1.0f, -1.0f,  1.0f);
    glVertex3f( 1.0f, -1.0f, -1.0f);

    // Back face (red)
    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex3f( 0.0f,  1.0f,  0.0f);
    glVertex3f( 1.0f, -1.0f, -1.0f);
    glVertex3f(-1.0f, -1.0f, -1.0f);

    // Left face (yellow)
    glColor3f(1.0f, 1.0f, 0.0f);
    glVertex3f( 0.0f,  1.0f,  0.0f);
    glVertex3f(-1.0f, -1.0f, -1.0f);
    glVertex3f(-1.0f, -1.0f,  1.0f);

    glEnd();
}

// Function to handle rendering
void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    // Rotate and draw the cube
    glPushMatrix();
    glTranslatef(-1.5f, 0.0f, -7.0f);
    glRotatef(cubeAngle, 1.0f, 1.0f, 1.0f);  // Rotate around multiple axes
    drawCube();
    glPopMatrix();

    // Rotate and draw the pyramid
    glPushMatrix();
    glTranslatef(2.0f, 0.0f, -7.0f);
    glRotatef(pyramidAngle, 1.0f, 1.0f, 0.0f);  // Rotate around X and Y axes
    drawPyramid();
    glPopMatrix();

    glutSwapBuffers();
}

// Function to handle the animation and update the angles
void update(int value) {
    cubeAngle += 1.0f;    // Increment cube's rotation angle
    if (cubeAngle > 360) {
        cubeAngle -= 360;
    }

    pyramidAngle += 1.5f; // Increment pyramid's rotation angle
    if (pyramidAngle > 360) {
        pyramidAngle -= 360;
    }

    glutPostRedisplay();  // Redraw the scene
    glutTimerFunc(16, update, 0);  // Schedule the next update in ~16ms (~60 FPS)
}

// Function to handle window resizing
void reshape(int w, int h) {
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    float aspect = (float)w / (float)h;
    glFrustum(-aspect, aspect, -1.0, 1.0, 1.5, 200.0);

    glMatrixMode(GL_MODELVIEW);
}

// Initialize OpenGL settings
void init() {
    glEnable(GL_DEPTH_TEST);  // Enable depth testing
}

int main(int argc, char** argv) {
    // Initialize GLUT and create a window
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Rotating 3D Cube and Pyramid");

    // Initialize OpenGL
    init();

    // Set callback functions
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutTimerFunc(16, update, 0);  // Call the update function every ~16ms

    // Start the main loop
    glutMainLoop();

    return 0;
}
