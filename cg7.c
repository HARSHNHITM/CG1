#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>

typedef struct pixel {
    GLubyte red, green, blue;
} pixel;

void boundaryFill(float x, float y, pixel fill, pixel boundary) {
    pixel c;
    glReadPixels(x, y, 1, 1, GL_RGB, GL_UNSIGNED_BYTE, &c);
    if ((c.red != boundary.red) && (c.green != boundary.green) && (c.blue != boundary.blue) &&
        (c.red != fill.red) && (c.green != fill.green) && (c.blue != fill.blue) && (x <= 400)) {
        glBegin(GL_POINTS);
        glColor3ub(fill.red, fill.green, fill.blue);
        glVertex2f(x, y);
        glEnd();
        glFlush();
        glReadPixels(x, y, 1, 1, GL_RGB, GL_UNSIGNED_BYTE, &c);
        printf("\nCOLOR %d,%d,%d", (int)c.red, (int)c.green, (int)c.blue);
        printf("\nx=%f, y=%f", x, y);
        boundaryFill(x + 1, y, fill, boundary);
        boundaryFill(x - 1, y, fill, boundary);
        boundaryFill(x, y + 1, fill, boundary);
        boundaryFill(x, y - 1, fill, boundary);
    }
}

void floodFill(int x, int y, float fillColor[3], float interiorColor[3]) {
    float currentColor[3];
    glReadPixels(x, y, 1, 1, GL_RGB, GL_FLOAT, currentColor);
    if (currentColor[0] == interiorColor[0] && currentColor[1] == interiorColor[1] && currentColor[2] == interiorColor[2]) {
        glColor3fv(fillColor);
        glBegin(GL_POINTS);
        glVertex2i(x, y);
        glEnd();
        glFlush();
        floodFill(x + 1, y, fillColor, interiorColor);
        floodFill(x - 1, y, fillColor, interiorColor);
        floodFill(x, y + 1, fillColor, interiorColor);
        floodFill(x, y - 1, fillColor, interiorColor);
    }
}

void mydisplay(int choice) {
    glClear(GL_COLOR_BUFFER_BIT);

    if (choice == 1) {
        glBegin(GL_POLYGON);
        glColor3ub(10, 0, 10);
        glVertex2f(200, 50);
        glVertex2f(100, 100);
        glVertex2f(400, 100);
        glVertex2f(100, 50);
        glEnd();

        pixel fill, boundary;
        fill.red = 0;
        fill.green = 255;
        fill.blue = 255;
        boundary.red = 255;
        boundary.green = 255;
        boundary.blue = 255;
        boundaryFill(300, 75, fill, boundary);
    } else if (choice == 2) {
        glColor3f(0.0, 0.0, 0.0);
        glBegin(GL_POLYGON);
        glVertex2i(100, 100);
        glVertex2i(200, 100);
        glVertex2i(200, 200);
        glVertex2i(100, 200);
        glEnd();

        float fillColor[3] = {1.0, 0.0, 1.0};
        int seedx = 150;
        int seedy = 150;
        float borderColor[3] = {0.0, 0.0, 0.0};
        floodFill(seedx, seedy, fillColor, borderColor);
    }

    glFlush();
}

void menu(int num) {
    if (num == 0) {
        glClear(GL_COLOR_BUFFER_BIT);
        glFlush();
    }
    if (num == 1 || num == 2) {
        mydisplay(num);
    }
}

int main(in#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>

typedef struct pixel {
    GLubyte red, green, blue;
} pixel;

void boundaryFill(float x, float y, pixel fill, pixel boundary) {
    pixel c;
    glReadPixels(x, y, 1, 1, GL_RGB, GL_UNSIGNED_BYTE, &c);
    if ((c.red != boundary.red) && (c.green != boundary.green) && (c.blue != boundary.blue) &&
        (c.red != fill.red) && (c.green != fill.green) && (c.blue != fill.blue) && (x <= 400)) {
        glBegin(GL_POINTS);
        glColor3ub(fill.red, fill.green, fill.blue);
        glVertex2f(x, y);
        glEnd();
        glFlush();
        glReadPixels(x, y, 1, 1, GL_RGB, GL_UNSIGNED_BYTE, &c);
        printf("\nCOLOR %d,%d,%d", (int)c.red, (int)c.green, (int)c.blue);
        printf("\nx=%f, y=%f", x, y);
        boundaryFill(x + 1, y, fill, boundary);
        boundaryFill(x - 1, y, fill, boundary);
        boundaryFill(x, y + 1, fill, boundary);
        boundaryFill(x, y - 1, fill, boundary);
    }
}

void floodFill(int x, int y, float fillColor[3], float interiorColor[3]) {
    float currentColor[3];
    glReadPixels(x, y, 1, 1, GL_RGB, GL_FLOAT, currentColor);
    if (currentColor[0] == interiorColor[0] && currentColor[1] == interiorColor[1] && currentColor[2] == interiorColor[2]) {
        glColor3fv(fillColor);
        glBegin(GL_POINTS);
        glVertex2i(x, y);
        glEnd();
        glFlush();
        floodFill(x + 1, y, fillColor, interiorColor);
        floodFill(x - 1, y, fillColor, interiorColor);
        floodFill(x, y + 1, fillColor, interiorColor);
        floodFill(x, y - 1, fillColor, interiorColor);
    }
}

void mydisplay(int choice) {
    glClear(GL_COLOR_BUFFER_BIT);

    if (choice == 1) {
        glBegin(GL_POLYGON);
        glColor3ub(10, 0, 10);
        glVertex2f(200, 50);
        glVertex2f(100, 100);
        glVertex2f(400, 100);
        glVertex2f(100, 50);
        glEnd();

        pixel fill, boundary;
        fill.red = 0;
        fill.green = 255;
        fill.blue = 255;
        boundary.red = 255;
        boundary.green = 255;
        boundary.blue = 255;
        boundaryFill(300, 75, fill, boundary);
    } else if (choice == 2) {
        glColor3f(0.0, 0.0, 0.0);
        glBegin(GL_POLYGON);
        glVertex2i(100, 100);
        glVertex2i(200, 100);
        glVertex2i(200, 200);
        glVertex2i(100, 200);
        glEnd();

        float fillColor[3] = {1.0, 0.0, 1.0};
        int seedx = 150;
        int seedy = 150;
        float borderColor[3] = {0.0, 0.0, 0.0};
        floodFill(seedx, seedy, fillColor, borderColor);
    }

    glFlush();
}

void menu(int num) {
    if (num == 0) {
        glClear(GL_COLOR_BUFFER_BIT);
        glFlush();
    }
    if (num == 1 || num == 2) {
        mydisplay(num);
    }
}

int main(int argc, char **argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition(540, 320);
    glutInitWindowSize(400, 400);
    glutCreateWindow("Boundary and Flood Fill");
    glClearColor(1.0f, 1.0f, 1.0f, 0.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    gluOrtho2D(0.0, 400.0, 0.0, 400.0);

    glutCreateMenu(menu);
    glutAddMenuEntry("Clear", 0);
    glutAddMenuEntry("Boundary Fill", 1);
    glutAddMenuEntry("Flood Fill", 2);
    glutAttachMenu(GLUT_RIGHT_BUTTON);

    glutDisplayFunc(mydisplay);
    glutMainLoop();
    return 0;
}


t argc, char **argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition(540, 320);
    glutInitWindowSize(400, 400);
    glutCreateWindow("Boundary and Flood Fill");
    glClearColor(1.0f, 1.0f, 1.0f, 0.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    gluOrtho2D(0.0, 400.0, 0.0, 400.0);

    glutCreateMenu(menu);
    glutAddMenuEntry("Clear", 0);
    glutAddMenuEntry("Boundary Fill", 1);
    glutAddMenuEntry("Flood Fill", 2);
    glutAttachMenu(GLUT_RIGHT_BUTTON);

    glutDisplayFunc(mydisplay);
    glutMainLoop();
    return 0;
}


