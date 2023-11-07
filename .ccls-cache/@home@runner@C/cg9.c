#include <GL/glut.h>
#include <math.h>
double parr[8];
void init() {
    glClearColor(0, 0, 0, 1);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-500, 500, -500, 500);
    parr[0] = 10;
    parr[1] = 10;
    parr[2] = 200;
    parr[3] = 10;
    parr[4] = 200;
    parr[5] = 200;
    parr[6] = 10;
    parr[7] = 200;
}
double degreeToRad(double deg) {
    return M_PI * (deg / 180); // Use M_PI from math.h
}
void polygon() {
    glColor3f(1, 0, 0);
    glBegin(GL_LINE_LOOP);
    for (int i = 0; i < 8; i += 2) {
        glVertex2f(parr[i], parr[i + 1]);
    }
    glEnd();
    glFlush();
}
void drawCoordinates() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1, 1, 1);
    glPointSize(4);
    glBegin(GL_LINES);
    glVertex2f(-500, 0);
    glVertex2f(500, 0);
    glVertex2f(0, 500);
    glVertex2f(0, -500);
    glEnd();
    glColor3f(1, 0, 0);
    glBegin(GL_POINTS);
    glVertex2f(0, 0);
    glEnd();
    glFlush();
}
void translate2d() {
    int x = 40, y = 50;
    for (int i = 0; i < 8; i += 2) {
        parr[i] += x;
    }
    for (int i = 1; i < 8; i += 2) {
        parr[i] += y;
    }
    polygon();
}
void rotation() {
    double angle = 180;
    double rad = degreeToRad(angle);
    for (int i = 0; i < 8; i += 2) {
        double x = parr[i] * cos(rad) - parr[i + 1] * sin(rad);
        double y = parr[i] * sin(rad) + parr[i + 1] * cos(rad);
        parr[i] = x;
        parr[i + 1] = y;
    }
    polygon();
}
void scaling2d() {
    double x = 2.0, y = 2.0;
    for (int i = 0; i < 8; i += 2) {
        parr[i] *= x;
    }
    for (int i = 1; i < 8; i += 2) {
        parr[i] *= y;
    }
    polygon();
}
void menu(int ch) {
    drawCoordinates();
    switch (ch) {
        case 1: polygon();
                break;
        case 2: translate2d();
                break;
        case 3: scaling2d();
                break;
        case 4: rotation();
                break;
    }
}
int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("2D Transformation");
    init();
    glutDisplayFunc(drawCoordinates);
    glutCreateMenu(menu);
    glutAddMenuEntry("1 Display Polygon", 1);
    glutAddMenuEntry("2 Translate", 2);
    glutAddMenuEntry("3 Scaling", 3);
    glutAddMenuEntry("4 Rotation", 4);
    glutAttachMenu(GLUT_RIGHT_BUTTON); 
    glutMainLoop();
    return 0;
}
