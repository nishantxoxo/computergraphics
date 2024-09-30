#include <GL/glut.h>
#include <cmath>


void displayWindow();
//void drawCircle(float x2, int y2);
//void drawEllipse(float a, float b, float x,  float y);
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
void drawCircle(float centerX, float centerY, float radius, int numPoints) {
    glColor3f(1.0f, 0.0f, 0.0f);
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
void drawEllipse(float a,float b, float cx, float cy) {



    glColor3f(1.0f, 0.0f, 0.0f);
     glPointSize(2.0f);

    glBegin(GL_POINTS);


    for (float theta = 0; theta < 2 * M_PI; theta += 0.001) {
        float x = a * cos(theta) + cx;
        float y = b * sin(theta) + cy;
        glVertex2f(x/256.0f, y/256.0f);
    }

    glEnd();

}
void displayWindow() {
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(1.0f, 0.0f, 0.0f);
    glPointSize(5.0f);
    glBegin(GL_POINTS);
    glVertex2f(0.0f, 0.0f);
    glEnd();
     glColor3f(1.0f, 0.0f, 0.0f);
    glPointSize(5.0f);
    glBegin(GL_POINTS);
    for(int i = 102; i<210; i++){
        glVertex2f(i/256.0f, i/256.0f);
    }
    glEnd();


    glColor3f(1.0f, 0.0f, 0.0f);
    glPointSize(5.0f);
    glBegin(GL_POINTS);
    for(int i = 102; i<210; i++){
        glVertex2f(i/256.0f, 0/256.0f);
    }
    for(int i = 0; i<50; i++){
        glVertex2f(102/256.0f, i/256.0f);
    }
    for(int i = 102; i<210; i++){
        glVertex2f(i/256.0f, 50/256.0f);
    }
    for(int i = 0; i<50; i++){
        glVertex2f(210/256.0f, i/256.0f);
    }
    glEnd();
    drawCircle(-100.0f, -100.0f, 50.0f, 200);
    drawEllipse(80.0f, 50.0f, -150.0f, 100.0f);
    glutSwapBuffers();
}
