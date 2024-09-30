#include <GL/glut.h>
#include <cmath>

// Function to draw an ellipse using the Midpoint Ellipse Algorithm
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

// Display function to render the ellipse
void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    drawEllipse(60, 40, -20, -40);  // Draw ellipse with a=60, b=40, centered at (-20, -40)
}

// Initialize OpenGL
void init() {
    glClearColor(1.0, 1.0, 1.0, 1.0);  // Set background color to white
    glColor3f(0.0, 0.0, 0.0);          // Set drawing color to black
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-100, 100, -100, 100);  // Set the orthographic projection to fit the ellipse
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);  // Set the window size
    glutInitWindowPosition(100, 100);  // Set the window position
    glutCreateWindow("Midpoint Ellipse Algorithm");
    init();
    glutDisplayFunc(display);
    glutMainLoop();  // Enter the GLUT event processing loop
    return 0;
}
