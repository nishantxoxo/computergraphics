#include <GL/glut.h>
#include <math.h>

// Pivot point coordinates
float pivotX = 10.0f;
float pivotY = 10.0f;
// Step counter to control transformations
int step = 0;

// Convert degrees to radians
float toRadians(float degrees) {
    return degrees * M_PI / 180.0f;
}

// Calculate transformed x coordinate
float getTransformedX(float x, float y, float angle) {
    // Calculate r and initial theta
    float dx = x - pivotX;
    float dy = y - pivotY;
    float r = sqrt(dx*dx + dy*dy);
    float theta = atan2(dy, dx);

    // Calculate new position using x = r*cos(theta + phi)
    float phi = toRadians(angle);
    return pivotX + r * cos(theta + phi);
}

// Calculate transformed y coordinate
float getTransformedY(float x, float y, float angle) {
    // Calculate r and initial theta
    float dx = x - pivotX;
    float dy = y - pivotY;
    float r = sqrt(dx*dx + dy*dy);
    float theta = atan2(dy, dx);

    // Calculate new position using y = r*sin(theta + phi)
    float phi = toRadians(angle);
    return pivotY + r * sin(theta + phi);
}

void drawTriangle(float angle) {
    glBegin(GL_TRIANGLES);
    // Original vertices
    float v1x = pivotX;
    float v1y = pivotY + 4.0f;
    float v2x = pivotX - 2.0f;
    float v2y = pivotY - 2.0f;
    float v3x = pivotX + 2.0f;
    float v3y = pivotY - 2.0f;

    if (step == 0) {
        // Original position
        glVertex2f(v1x, v1y);
        glVertex2f(v2x, v2y);
        glVertex2f(v3x, v3y);
    }
    else if (step == 1) {
        // Translate to origin
        glVertex2f(v1x - pivotX, v1y - pivotY);
        glVertex2f(v2x - pivotX, v2y - pivotY);
        glVertex2f(v3x - pivotX, v3y - pivotY);
    }
    else if (step == 2) {
        // Rotate at origin
        float angle = 90.0f;
        glVertex2f(getTransformedX(v1x, v1y, angle) - pivotX,
                   getTransformedY(v1x, v1y, angle) - pivotY);
        glVertex2f(getTransformedX(v2x, v2y, angle) - pivotX,
                   getTransformedY(v2x, v2y, angle) - pivotY);
        glVertex2f(getTransformedX(v3x, v3y, angle) - pivotX,
                   getTransformedY(v3x, v3y, angle) - pivotY);
    }
    else if (step == 3) {
        // Translate back after rotation
        float angle = 90.0f;
        glVertex2f(getTransformedX(v1x, v1y, angle),
                   getTransformedY(v1x, v1y, angle));
        glVertex2f(getTransformedX(v2x, v2y, angle),
                   getTransformedY(v2x, v2y, angle));
        glVertex2f(getTransformedX(v3x, v3y, angle),
                   getTransformedY(v3x, v3y, angle));
    }
    glEnd();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    // Draw the triangle
    drawTriangle(90.0f);  // 90 degrees rotation

    // Draw the pivot point
    glPointSize(5.0f);
    glBegin(GL_POINTS);
        glVertex2f(pivotX, pivotY);
    glEnd();

    glFlush();
}

void init() {
    glClearColor(1.0, 1.0, 1.0, 1.0);  // White background
    glColor3f(1.0f, 0.0f, 0.0f);       // Gray color for triangle
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(-20.0, 20.0, -20.0, 20.0);
}

void keyboard(unsigned char key, int x, int y) {
    if (key == 'n') {   // Press 'n' to go to next step
        step = (step + 1) % 4;
        glutPostRedisplay();
    }
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Object Transformation using Trigonometric Functions");
    init();
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutMainLoop();
    return 0;
}
