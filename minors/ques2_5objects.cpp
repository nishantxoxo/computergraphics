#include <GL/glut.h>
#include <cmath>
void renderFigure1a() {
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_POINTS);
        glVertex2f(0.0f, 0.0f);  // p1
    glEnd();
    glFlush();
}

void renderFigure2a() {
    glClear(GL_COLOR_BUFFER_BIT);

    // Draw points
    glBegin(GL_POINTS);
        glVertex2f(-0.5f, -0.5f);  // p1
        glVertex2f(0.5f, 0.5f);    // p2
    glEnd();

    // Draw line segment
    glBegin(GL_LINES);
        glVertex2f(-0.5f, -0.5f);  // p1
        glVertex2f(0.5f, 0.5f);    // p2
    glEnd();

    glFlush();
}

void drawCircle(int xc, int yc, int r) {


    glBegin(GL_POINTS);
    for (int i = 0; i < 360; i++) {
        float theta = i * M_PI / 180; // Convert degree to radian
        float x = r * cos(theta);
        float y = r * sin(theta);
        glVertex2f(xc + x, yc + y);
    }
    glEnd();
}
void renderFigure3a() {
    glClear(GL_COLOR_BUFFER_BIT);

    // Draw points
    glBegin(GL_POINTS);
        glVertex2f(-0.5f, -0.3f);  // p1
        glVertex2f(-0.5f, 0.3f);   // p2
        glVertex2f(0.5f, 0.3f);    // p3
        glVertex2f(0.5f, -0.3f);   // p4
    glEnd();

    // Draw rectangle
    glBegin(GL_LINE_LOOP);
        glVertex2f(-0.5f, -0.3f);  // p1
        glVertex2f(-0.5f, 0.3f);   // p2
        glVertex2f(0.5f, 0.3f);    // p3
        glVertex2f(0.5f, -0.3f);   // p4
    glEnd();

    glFlush();
}
void drawEllipse(int a, int b, int xc, int yc) {
    int x = 0;
    int y = b;

    // Initial decision parameters
    float d1 = (b * b) - (a * a * b) + (0.25 * a * a);
    int dx = 2 * b * b * x;
    int dy = 2 * a * a * y;

    // Region 1
    glBegin(GL_POINTS);
    while (dx < dy) {
        // Plot points in all four quadrants
        glVertex2i(x + xc, y + yc);
        glVertex2i(-x + xc, y + yc);
        glVertex2i(x + xc, -y + yc);
        glVertex2i(-x + xc, -y + yc);

        if (d1 < 0) {
            x++;
            dx = dx + (2 * b * b);
            d1 = d1 + dx + (b * b);
        } else {
            x++;
            y--;
            dx = dx + (2 * b * b);
            dy = dy - (2 * a * a);
            d1 = d1 + dx - dy + (b * b);
        }
    }

    // Region 2
    float d2 = ((b * b) * ((x + 0.5) * (x + 0.5))) + ((a * a) * ((y - 1) * (y - 1))) - (a * a * b * b);
    while (y >= 0) {
        // Plot points in all four quadrants
        glVertex2i(x + xc, y + yc);
        glVertex2i(-x + xc, y + yc);
        glVertex2i(x + xc, -y + yc);
        glVertex2i(-x + xc, -y + yc);

        if (d2 > 0) {
            y--;
            dy = dy - (2 * a * a);
            d2 = d2 + (a * a) - dy;
        } else {
            y--;
            x++;
            dx = dx + (2 * b * b);
            dy = dy - (2 * a * a);
            d2 = d2 + dx - dy + (a * a);
        }
    }
    glEnd();
    glFlush();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    drawEllipse(60, 40, -20, -40);  // Draw ellipse with a=60, b=40, centered at (-20, -40)
}

void init() {
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);  // Set background to white
    glColor3f(0.2f, 0.4f, 0.8f);  // Set point and line color to blue
    glPointSize(8.0f);  // Set point size
    gluOrtho2D(-1.0, 1.0, -1.0, 1.0);  // Set coordinate system
}

// Main function
int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

    // Create window for Fig. 3a (Rectangle)
    glutInitWindowSize(512, 512);
    glutCreateWindow("Fig. 3a");
    init();
    glutDisplayFunc(renderFigure3a);

    glutInitWindowSize(512, 512);
    glutCreateWindow("Fig. 3a");
    init();
    glutDisplayFunc(renderFigure3a);

    glutInitWindowSize(512, 512);
    glutCreateWindow("Fig. 3a");
    init();
    glutDisplayFunc(renderFigure3a);

    glutInitWindowSize(512, 512);
    glutCreateWindow("Fig. 3a");
    init();
    glutDisplayFunc(renderFigure3a);

    glutInitWindowSize(512, 512);
    glutCreateWindow("Fig. 3a");
    init();
    glutDisplayFunc(renderFigure3a);


    glutMainLoop();
    return 0;
}


