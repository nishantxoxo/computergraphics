#include <GL/glut.h>
#include <cmath>

struct Point {
    float x, y;
};

// Define control points for each curve (based on your image)
Point curve1[] = { {100, 400}, {150, 450}, {200, 350} };          // (a)
Point curve2[] = { {100, 300}, {150, 350}, {200, 250}, {250, 300} }; // (b)
Point curve3[] = { {100, 200}, {150, 300}, {200, 100}, {250, 200} }; // (c)
Point curve4[] = { {100, 70}, {150, 200}, {200, 200}, {270, 120} }; // (d)
Point curve5[] = { {100, 50}, {150, 100}, {200, 0}, {250, 100}, {300, 50} }; // (e)

void bezierCurve(Point* points, int numPoints) {
    glBegin(GL_LINE_STRIP);
    for (float t = 0; t <= 1.0; t += 0.01) {
        float x = 0, y = 0;
        for (int i = 0; i < numPoints; i++) {
            float binomialCoeff = tgamma(numPoints) / (tgamma(i + 1) * tgamma(numPoints - i));
            float blend = binomialCoeff * pow(t, i) * pow(1 - t, numPoints - i - 1);
            x += points[i].x * blend;
            y += points[i].y * blend;
        }
        glVertex2f(x, y);
    }
    glEnd();
}

void drawControlPoints(Point* points, int numPoints) {
    glPointSize(5);
    glBegin(GL_POINTS);
    for (int i = 0; i < numPoints; i++) {
        glVertex2f(points[i].x, points[i].y);
    }
    glEnd();
}

// Display functions for each window
void displayCurve1() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 0.0, 0.0); // Red for control points
    drawControlPoints(curve1, 3);
    glColor3f(0.0, 1.0, 0.0); // Green for curve
    bezierCurve(curve1, 3);
    glFlush();
}

void displayCurve2() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 0.0, 0.0);
    drawControlPoints(curve2, 4);
    glColor3f(0.0, 1.0, 0.0);
    bezierCurve(curve2, 4);
    glFlush();
}

void displayCurve3() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 0.0, 0.0);
    drawControlPoints(curve3, 4);
    glColor3f(0.0, 1.0, 0.0);
    bezierCurve(curve3, 4);
    glFlush();
}

void displayCurve4() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 0.0, 0.0);
    drawControlPoints(curve4, 4);
    glColor3f(0.0, 1.0, 0.0);
    bezierCurve(curve4, 4);
    glFlush();
}

void displayCurve5() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 0.0, 0.0);
    drawControlPoints(curve5, 5);
    glColor3f(0.0, 1.0, 0.0);
    bezierCurve(curve5, 5);
    glFlush();
}

void init() {
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, 400.0, 0.0, 500.0);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);

    // Window 1 for Curve (a)
    int window1 = glutCreateWindow("Bezier Curve 1");
    init();
    glutDisplayFunc(displayCurve1);

    // Window 2 for Curve (b)
    int window2 = glutCreateWindow("Bezier Curve 2");
    init();
    glutDisplayFunc(displayCurve2);

    // Window 3 for Curve (c)
    int window3 = glutCreateWindow("Bezier Curve 3");
    init();
    glutDisplayFunc(displayCurve3);

    // Window 4 for Curve (d)
    int window4 = glutCreateWindow("Bezier Curve 4");
    init();
    glutDisplayFunc(displayCurve4);

    // Window 5 for Curve (e)
    int window5 = glutCreateWindow("Bezier Curve 5");
    init();
    glutDisplayFunc(displayCurve5);

    glutMainLoop();
    return 0;
}
