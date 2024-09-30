//QUESTION 3 b
#include <GL/glut.h>
#include <stdio.h>
#include <math.h>
#define PI 3.14159265358979323846

void setPixel(int x, int y) {
    glBegin(GL_POINTS);
    glVertex2i(x, y);
    glEnd();
}

void bresenhamLine(int x1, int y1, int x2, int y2) {
    int dx = abs(x2 - x1);
    int dy = abs(y2 - y1);
    int sx = (x1 < x2) ? 1 : -1;
    int sy = (y1 < y2) ? 1 : -1;
    int err = dx - dy;

    while (1) {
        setPixel(x1, y1);
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
}

// Function to draw a circle using GL_POINTS
void drawCirclePoints(float radius, float x_center, float y_center) {
    int num_segments = 100;
    glBegin(GL_POINTS);
    for (int i = 0; i < num_segments; i++) {
        float theta = 2.0f * PI * float(i) / float(num_segments);
        float x = radius * cosf(theta);  // Calculate x position
        float y = radius * sinf(theta);  // Calculate y position
        glVertex2f(x + x_center, y + y_center);  // Output the vertex
    }
    glEnd();
}

// Function to draw an ellipse using the Midpoint Ellipse Algorithm
void midpointEllipse(int xc, int yc, int rx, int ry) {
    float dx, dy, d1, d2, x, y;
    x = 0;
    y = ry;

    d1 = (ry * ry) - (rx * rx * ry) + (0.25 * rx * rx);
    dx = 2 * ry * ry * x;
    dy = 2 * rx * rx * y;


    while (dx < dy) {
        setPixel(xc + x, yc + y);
        setPixel(xc - x, yc + y);
        setPixel(xc + x, yc - y);
        setPixel(xc - x, yc - y);
        if (d1 < 0) {
            x++;
            dx += 2 * ry * ry;
            d1 += dx + (ry * ry);
        } else {
            x++;
            y--;
            dx += 2 * ry * ry;
            dy -= 2 * rx * rx;
            d1 += dx - dy + (ry * ry);
        }
    }


    d2 = ((ry * ry) * ((x + 0.5) * (x + 0.5))) + ((rx * rx) * ((y - 1) * (y - 1))) - (rx * rx * ry * ry);


    while (y >= 0) {
        setPixel(xc + x, yc + y);
        setPixel(xc - x, yc + y);
        setPixel(xc + x, yc - y);
        setPixel(xc - x, yc - y);
        if (d2 > 0) {
            y--;
            dy -= 2 * rx * rx;
            d2 += (rx * rx) - dy;
        } else {
            y--;
            x++;
            dx += 2 * ry * ry;
            dy -= 2 * rx * rx;
            d2 += dx - dy + (rx * rx);
        }
    }
}


void drawLines() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0, 0.0, 0.0);

    drawCirclePoints(50.0f, 400.0f, 400.0);
    drawCirclePoints(10.0f, 370.0f, 400.0);
    drawCirclePoints(10.0f, 430.0f, 400.0);

    bresenhamLine(375, 370, 425, 370);
    bresenhamLine(250, 200, 350, 300);
    bresenhamLine(550, 200, 450, 300);


    midpointEllipse(400, 250, 50, 100);

    glFlush();
}

void init() {
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glOrtho(0, 812, 0, 512, -1, 1);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(812, 512);
    glutCreateWindow("Bresenham Line Drawing with Ellipse");
    init();
    glutDisplayFunc(drawLines);
    glutMainLoop();
    return 0;
}
