
#include <iostream>
#include <OpenGl/gl.h>
#include <OpenGl/glu.h>
#include <GLUT/glut.h>

void axis(double length)
{
    // draw a z-axis
    glPushMatrix();
    glBegin(GL_LINES);
    glVertex3d(0, 0, 0);
    glVertex3d(0,0,length); // along the z-axis
    glEnd();
    glTranslated(0, 0,length -0.2);
    glutWireCone(0.04, 0.2, 12, 9);
    glPopMatrix();
    
}

void Initialize() {
    glMatrixMode(GL_PROJECTION); // set the view volume shape
    glLoadIdentity();
    glOrtho(-2.0*10/6.0, 2.0*10/6.0, -2.0, 2.0, 0.1, 100);
    glMatrixMode(GL_MODELVIEW); // position and aim the camera
    glLoadIdentity();
    gluLookAt(1.0,1.0, 2.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
    glClear(GL_COLOR_BUFFER_BIT);
    glTranslatef(-1.5f, 1.0f, .75f);
    glPushMatrix();
    //draw z-axis in red
    glColor3d(1,0,0);
    axis(2.0);
    //draw x-axis in green
    glColor3d(0,1,0);
    glRotated(90, 0,1.0, 0);
    axis(4.0);
    //draw y-axis in blue
    glColor3d(0,0,1);
    glRotated(-90.0, 1, 0, 0);
    axis(1.0);
    glPopMatrix();
}

void DrawGround() {
    glPushMatrix();
    glBegin(GL_QUADS);
    glColor3d(0.0, .390625, 0.0);
    glVertex3d(0.1, 0, 0.1);
    glVertex3d(3.0, 0, 0.1);
    glVertex3d(3.0, 0, 2.0);
    glVertex3d(0.1, 0, 2.0);
    glEnd();
    glPopMatrix();
    
}

void keyboard(unsigned char key, int x, int y) {
    //code goes here...
    //glutPostRedisplay();
}

void Display() {
    Initialize();
    DrawGround();
    glFlush();
}

int main(int argc, char ** argv) {
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowSize(1000,600);
    glutInitWindowPosition(200,90);
    glutCreateWindow("3D House Environment");
    glutDisplayFunc(Display);
    glClearColor(1.0f,1.0f,1.0f,1.0f);
    glutKeyboardFunc(keyboard);
    gluOrtho2D(0.0,1000.0,0.0,600.0);
    glutMainLoop();
    return 0;
}
