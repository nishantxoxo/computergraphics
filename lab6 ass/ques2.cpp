#include <GL/glut.h>
#include <math.h>
#include <string.h>

const int WIDTH = 800;
const int HEIGHT = 800;
const float PI = 3.14159265358979323846;

void renderText(float x, float y, const char* text) {
    glRasterPos2f(x, y);
    while (*text) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, *text);
        text++;
    }
}

void rotatePoint(float* x, float* y, float angle) {
    float rad = angle * PI / 180.0;
    float newX = (*x) * cos(rad) - (*y) * sin(rad);
    float newY = (*x) * sin(rad) + (*y) * cos(rad);
    *x = newX;
    *y = newY;
}

void drawCone(float apexX, float apexY, float baseRadius, float height) {
    float ellipseRatio = 0.3; // Adjust this value to change the "3D" effect

    // Draw the sides of the cone
    glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_LINES);
    glVertex2f(apexX, apexY);
    glVertex2f(apexX - baseRadius, apexY - height);
    glVertex2f(apexX, apexY);
    glVertex2f(apexX + baseRadius, apexY - height);
    glEnd();

    // Draw the base ellipse
    glBegin(GL_LINE_LOOP);
    for (float angle = 0; angle <= 2 * PI; angle += 0.01) {
        float x = apexX + baseRadius * cos(angle);
        float y = apexY - height + baseRadius * ellipseRatio * sin(angle);
        glVertex2f(x, y);
    }
    glEnd();

    // Draw the dashed part of the ellipse (back of the cone)
    glEnable(GL_LINE_STIPPLE);
    glLineStipple(1, 0x00FF);
    glBegin(GL_LINE_STRIP);
    for (float angle = 0; angle <= PI; angle += 0.01) {
        float x = apexX + baseRadius * cos(angle);
        float y = apexY - height - baseRadius * ellipseRatio * sin(angle);
        glVertex2f(x, y);
    }
    glEnd();
    glDisable(GL_LINE_STIPPLE);
}

void drawCircleSection(float centerX, float centerY, float radiusX, float radiusY, const char* label) {
    glColor3f(1.0, 0.4, 0.4);
    glBegin(GL_POLYGON);
    for (int i = 0; i <= 360; i++) {
        float angle = i * PI / 180;
        glVertex2f(centerX + cos(angle) * radiusX, centerY + sin(angle) * radiusY);
    }
    glEnd();

    glColor3f(1.0, 0.4, 0.4);
    renderText(centerX + radiusX + 10, centerY, label);
}

void drawEllipseSection(float rx, float ry, float centerX, float centerY, float angle) {
    glColor3f(0.7, 1.0, 0.7);
    glBegin(GL_POLYGON);
    for (int i = 0; i <= 360; i++) {
        float rad = i * PI / 180;
        float x = cos(rad) * rx;
        float y = sin(rad) * ry;
        rotatePoint(&x, &y, angle);
        glVertex2f(x + centerX, y + centerY);
    }
    glEnd();

    glColor3f(0.7, 1.0, 0.7);
    renderText(centerX + 80, centerY + 20, "ellipse");
}

void drawParabolaSection(float scale, float centerX, float centerY, float angle) {
    glColor3f(0.7, 0.7, 1.0);
    glBegin(GL_POLYGON);
    for (float t = -1; t <= 1; t += 0.01) {
        float x = t * 120;
        float y = scale * (t * t * 1.0) * 100;
        rotatePoint(&x, &y, angle);
        glVertex2f(x + centerX, y + centerY);
    }
    glEnd();

    glColor3f(0.7, 0.7, 1.0);
    renderText(centerX + 40, centerY, "parabola");
}

void drawHyperbolaSection(float scale, float centerX, float centerY, float angle) {
    glColor3f(1.0, 0.2, 1.0);
    glBegin(GL_POLYGON);
    for (float t = -1.2; t <= 0.9; t += 0.01) {
        float x = t * 38;
        float y = scale * (t * t * 1.0) * 45;
        rotatePoint(&x, &y, angle);
        glVertex2f(x + centerX, y + centerY);
    }
    glEnd();

    glColor3f(0.7, 0.7, 0.5);
    renderText(centerX + 40, centerY, "Hyperbola");
}


void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();

    // Draw the cone and the sections
    drawCone(0, 300, 200, 500);                    // Draw the cone
    drawCircleSection(0, 200, 37.8, 22, "circle");  // Circle at the top
    drawEllipseSection(75, 30, -5, 110, 12);        // Ellipse section
    drawParabolaSection(3, 87.5, 70, 158);        // Parabola section

    // Add a single branch of the hyperbola to the bottom right side of the parabola
    drawHyperbolaSection(2.0, 160, -100, 160);
  // Adjust the values for position and rotation

    glutSwapBuffers();
}


void init() {
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-300, 300, -300, 400, -1.0, 1.0);
    glMatrixMode(GL_MODELVIEW);
}

void reshape(int w, int h) {
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    float aspect = (float)w / (float)h;
    if (w <= h)
        glOrtho(-300, 300, -300/aspect, 400/aspect, -1.0, 1.0);
    else
        glOrtho(-300 * aspect, 300 * aspect, -300, 400, -1.0, 1.0);
    glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(WIDTH, HEIGHT);
    glutCreateWindow("Modular Conic Sections");

    init();

    glutDisplayFunc(display);
    glutReshapeFunc(reshape);

    glutMainLoop();
    return 0;
}
