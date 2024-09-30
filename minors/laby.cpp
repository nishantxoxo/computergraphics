#include <GL/glut.h>
#include <cmath>


void displayWindow();

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);


    glutInitWindowSize(512, 512);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("512x512");
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
void rectangle(float x1, float y1,float x2, float y2,float x3, float y3,float x4, float y4){
        ddaLine(x1, y1, x2, y2);
        ddaLine(x1, y1, x4, y4);
        ddaLine(x2, y2, x3, y3);
        ddaLine(x4, y4, x3, y3);
}
void triangle(float x1, float y1, float x2, float y2, float x3, float y3){
    ddaLine(x1, y1, x2, y2);
    ddaLine(x2, y2, x3, y3);
    ddaLine(x1, y1, x3, y3);
}
void drawCircle(float centerX, float centerY, float radius, int numPoints) {
    glColor3f(0.0f, 0.0f, 0.0f);
    glPointSize(2.0f);

    glBegin(GL_POINTS);

    for (int i = 0; i < numPoints; ++i) {
        float theta = 2.0f * 3.1415926f * float(i) / float(numPoints);
        float x = centerX + radius * cos(theta);
        float y = centerY + radius * sin(theta);
        glVertex2f(x/256.0f, y/256.f );
    }

    glEnd();
}
void displayWindow() {
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    rectangle(-100, 100, -20, 100, -20, 50, -100, 50);
    rectangle(-120, 120, 0, 120, 0, 30, -120, 30);
    ddaLine(-120, 30, -150, 0);
    ddaLine(0, 30, 30, 0);
    rectangle(-150, 0,30, 0, 30, -20, -150, -20);

    rectangle(100, -200, 20, -200, 20, -250, 100, -250);
    triangle(100, -200, 140, -200, 120, -150);
    rectangle(100, -200, 140, -200, 140, -250, 100, -250);
    ddaLine(120, -150, 40, -150);

    ddaLine(40, -150, 20, -200);
    drawCircle(120, -225, 10, 200);
    glutSwapBuffers();
}
