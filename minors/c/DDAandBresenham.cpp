#include <GL/glut.h>
#include <cmath>


void displayWindow();
void ddaLine(float x1, float y1, float x2, float y2);

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);


    glutInitWindowSize(512, 512);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("DDA Line Algorithm - 512x512");
    glutDisplayFunc(displayWindow);


    glutMainLoop();

    return 0;
}


void ddaLine(float x1, float y1, float x2, float y2) {
    float dx = x2 - x1;
    float dy = y2 - y1;


    float steps = (fabs(dx) > fabs(dy)) ? fabs(dx) : fabs(dy);


    float xIncrement = dx / steps;
    float yIncrement = dy / steps;


    float x = x1;
    float y = y1;

    glColor3f(0.0f, 0.0f, 0.0f);
    glPointSize(2.0f);
    glBegin(GL_POINTS);


    for (int i = 0; i <= steps; i++) {
        glVertex2f(x / 256.0f, y / 256.0f);
        x += xIncrement;
        y += yIncrement;
    }

    glEnd();
}
void bresenhamLine(int x1, int y1, int x2, int y2) {
    int dx = abs(x2 - x1);
    int dy = abs(y2 - y1);
    int sx = (x1 < x2) ? 1 : -1;
    int sy = (y1 < y2) ? 1 : -1;
    int err = dx - dy;

    glColor3f(0.0f, 0.0f, 0.0f);
    glPointSize(2.0f);
    glBegin(GL_POINTS);

    while (true) {

        glVertex2f(x1 / 256.0f, y1 / 256.0f);


        if (x1 == x2 && y1 == y2) break;

        int e2 = 2 * err;

        if (e2 > -dy) {
            err -= dy;
            x1 += sx;
        }
        if (e2 < dx) {
            err += dx;
            y1 += sy;
        }
    }

    glEnd();
}
void displayWindow() {
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    ddaLine(-50.0f, 0.0f, -50.0f, 100.0f);
    ddaLine(-100.0f, 0.0f, -100.0f, 500.0f);
    bresenhamLine(40.0f, 30.0f, 60.0f, 80.0f);
    bresenhamLine(40.0f, 30.0f, 160.0f, 80.0f);

    glutSwapBuffers();
}

