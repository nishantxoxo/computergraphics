#include <GL/glut.h>
#include <cmath>
#include <string>

const int WINDOW_WIDTH = 800;
const int WINDOW_HEIGHT = 400;


void drawText(float x, float y, const std::string& text) {
    glRasterPos2f(x, y);
    for (char c : text) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, c);
    }
}
void dda_line(int x1, int y1, int x2, int y2) {
    float dx = x2 - x1;
    float dy = y2 - y1;
    float steps = std::max(std::abs(dx), std::abs(dy));
    float xInc = dx / steps;
    float yInc = dy / steps;
    float x = x1, y = y1;
    glBegin(GL_POINTS);
    for (int i = 0; i <= steps; i++) {
        glVertex2f(round(x), round(y));
        x += xInc;
        y += yInc;
    }
    glEnd();
}
void BresenhamLine(int x1, int y1, int x2, int y2) {
    int dx = abs(x2 - x1);
    int dy = abs(y2 - y1);
    int sx = (x1 < x2) ? 1 : -1;
    int sy = (y1 < y2) ? 1 : -1;
    int err = dx - dy;

    glBegin(GL_POINTS);
    while (true) {
        glVertex2f(x1, y1);

        if (x1 == x2 && y1 == y2)
            break;

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

void drawLeftShape() {
    int p1x = 50, p1y = 50;
    int p2x=100 ,p2y=100;
    glColor3f(0.0f, 0.0f, 0.0f);
    BresenhamLine(p1x, p1y, p2x, p2y);

}

void drawRightShape() {
   int p1x = 100, p1y = 50;
   int p2x= 200 ,p2y=100;
   glColor3f(1.0f, 0.0f, 0.0f);
   dda_line(p1x,p1y,p2x,p2y);
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    drawLeftShape();
    drawRightShape();
    glFlush();
}

void init() {
    glClearColor(0.9f, 0.9f, 0.8f, 1.0f);  // Light beige background color
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0, WINDOW_WIDTH, 0, WINDOW_HEIGHT, -1, 1);
    glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(WINDOW_WIDTH, WINDOW_HEIGHT);
    glutCreateWindow("Bresenham and dda Line Algorithm Shapes");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
