#include <GL/glut.h>
#include <cmath>

float pivotX = 100.0f;   // Initial X-coordinate of the centroid
float pivotY = 75.0f;    // Initial Y-coordinate of the centroid
float rotationAngle = 0.0f;
float translateX = 0.0f;
float translateY = 0.0f;
float scale = 1.0f;
int stage = 0;
bool transformationComplete = false;

// Converts degrees to radians
float toRadians(float degrees) {
    return degrees * (M_PI / 180.0f);
}

// Function to draw a triangle with rotation and scaling around its centroid
void drawTriangle(float offsetX, float offsetY, float angle, float scale) {
    float angleRad = toRadians(angle);
    glBegin(GL_TRIANGLES);
        for (int i = 0; i < 3; ++i) {
            float localX = (i == 0 ? pivotX : (i == 1 ? pivotX - 50.0f : pivotX + 50.0f)) * scale;
            float localY = (i == 0 ? pivotY + 50.0f : pivotY - 50.0f) * scale;
            float rotatedX = (localX - pivotX) * cos(angleRad) - (localY - pivotY) * sin(angleRad) + pivotX + offsetX;
            float rotatedY = (localX - pivotX) * sin(angleRad) + (localY - pivotY) * cos(angleRad) + pivotY + offsetY;
            glVertex2f(rotatedX, rotatedY);
        }
    glEnd();
}

// Display callback for OpenGL
void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0f, 1.0f, 0.0f);
    drawTriangle(translateX, translateY, rotationAngle, scale);
    glFlush();
}

// Update function to manage translation, rotation, and scaling
void update(int value) {
    if (!transformationComplete) {
        if (stage == 0) {
            // Step 1: Translate upwards to the new position
            translateY += 1.0f;
            if (translateY >= 100.0f) {
                stage = 1;
            }
        } else if (stage == 1) {
            // Step 2: Rotate around the new centroid position
            rotationAngle += 2.0f;
            if (rotationAngle >= 90.0f) {
                rotationAngle = 90.0f;  // Stop rotation at 90 degrees
                stage = 2;
            }
        } else if (stage == 2) {
            // Step 3: Scale down slightly
            scale -= 0.01f;
            if (scale <= 0.9f) {  // Stop scaling when it reaches 90% of the original size
                scale = 0.9f;
                transformationComplete = true;
            }
        }

        glutPostRedisplay();
        glutTimerFunc(30, update, 0);
    }
}

// Initialization function
void init() {
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0, 300.0, 0.0, 300.0, -1.0, 1.0);
}

// Main function
int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Triangle Transformation with Scaling");
    init();
    glutDisplayFunc(display);
    glutTimerFunc(30, update, 0);
    glutMainLoop();
    return 0;
}
