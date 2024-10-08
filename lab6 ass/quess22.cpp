#include <GL/glut.h>
#include <cmath>

// Function to initialize the OpenGL environment
void init() {
    // Set the background color to white
    glClearColor(1.0, 1.0, 1.0, 1.0);
    // Set up the projection matrix
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-10.0, 10.0, -10.0, 10.0); // Define the 2D orthographic projection
}

// Function to draw an ellipse (base of the cone)
void drawEllipse(float xc, float yc, float rx, float ry) {
    int num_segments = 100; // Number of segments to approximate the ellipse
    glBegin(GL_LINE_LOOP);
    for (int i = 0; i < num_segments; i++) {
        float theta = 2.0f * 3.14159f * float(i) / float(num_segments); // Get the current angle
        float x = rx * cosf(theta); // Calculate x component
        float y = ry * sinf(theta); // Calculate y component
        glVertex2f(x + xc, y + yc); // Output vertex
    }
    glEnd();
}

// Function to draw the cone
void drawCone() {
    // Apex of the cone
    float apexX = 0.0f, apexY = 8.0f;

    // Draw the two lines connecting the ellipse to the apex of the cone
    glBegin(GL_LINES);
    // Left side of the cone
    glVertex2f(-3.0f, 2.0f);  // Left point of the ellipse
    glVertex2f(apexX, apexY);  // Apex of the cone

    // Right side of the cone
    glVertex2f(3.0f, 2.0f);   // Right point of the ellipse
    glVertex2f(apexX, apexY);  // Apex of the cone
    glEnd();
}

// Display callback function
void display() {
    // Clear the window
    glClear(GL_COLOR_BUFFER_BIT);

    // Set the color to black
    glColor3f(0.0, 0.0, 0.0);

    // Draw the cone
    drawCone();

    // Draw an ellipse at the bottom (base of the cone)
    drawEllipse(0.0f, 2.0f, 3.0f, 1.0f); // Center (0,2) and radii 3 (horizontal) and 1 (vertical)

    // Flush the drawing to the window
    glFlush();
}

int main(int argc, char** argv) {
    // Initialize GLUT
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);  // Single buffer and RGB mode
    glutInitWindowSize(600, 600);                 // Set window size
    glutCreateWindow("Cone with Ellipse Base");   // Create window with title
    init();  // Initialize OpenGL settings
    glutDisplayFunc(display);  // Set display callback
    glutMainLoop();  // Enter the GLUT event-processing loop
    return 0;
}
