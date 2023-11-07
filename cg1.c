#include<stdio.h>
#include<GL/glut.h>
void display()
{
glClear(GL_COLOR_BUFFER_BIT);
glColor3f(0.0,0.0,1.0);
glClearColor(0.0,0.0,0.0,1.0); 
glLineWidth(10);
glBegin(GL_LINES); 
glVertex2f(0.0, 0.0); 
glVertex2f(0.0, 0.5); 
glEnd(); 
glFlush(); 
}
int main(int argc, char** argv)
{
glutInit(&argc, argv); 
glutInitWindowSize(650,420);
glutInitWindowPosition(200,200);
glutCreateWindow("Simple line"); 
glutDisplayFunc(display); 
glutMainLoop(); 
}