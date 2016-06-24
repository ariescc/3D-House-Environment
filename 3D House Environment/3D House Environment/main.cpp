
#include <iostream>
#include <OpenGl/gl.h>
#include <OpenGl/glu.h>
#include <GLUT/glut.h>


void xaxis(double length)
{
    // draw a x-axis
    glPushMatrix();
    glBegin(GL_LINES);
    glVertex3d(0.0, 0.0, 0.0);
    glVertex3d(length,0.0,0.0); // along the x-axis
    glEnd();
    glTranslated(length -0.2, 0.0,0.0);
    glRotated(90.0, 0.0, 1.0, 0.0);
    glutWireCone(0.04, 0.2, 12.0, 9.0);
    glPopMatrix();
    
}

void yaxis(double length)
{
    // draw a z-axis
    glPushMatrix();
    glBegin(GL_LINES);
    glVertex3d(0.0, 0.0, 0.0);
    glVertex3d(0.0,length,0.0); // along the z-axis
    glEnd();
    glTranslated(0.0, length -0.2,0.0);
    glRotated(-90.0, 1.0, 0.0, 0.0);
    glutWireCone(0.04, 0.2, 12.0, 9.0);
    glPopMatrix();
    
}

void zaxis(double length)
{
    // draw a z-axis
    glPushMatrix();
    glBegin(GL_LINES);
    glVertex3d(0.0, 0.0, 0.0);
    glVertex3d(0.0,0.0,length); // along the z-axis
    glEnd();
    glTranslated(0.0, 0.0,length -0.2);
    glutWireCone(0.04, 0.2, 12.0, 9.0);
    glPopMatrix();
    
}


void wall(double thickness)
{
    glPushMatrix();
    glTranslated(0.5,.5*thickness,0.5);
    glScaled(1.0,thickness,1.0);
    glutSolidCube(1.0);
    glPopMatrix();
}

void Initialize() {
    glMatrixMode(GL_PROJECTION); // set the view volume shape
    glLoadIdentity();
    glOrtho(-10.0,10.0,-10.0,10.0,-10.0,10.0);
    gluPerspective(60.0, 1.0, 0.0, 20.0);
    glMatrixMode(GL_MODELVIEW); // position and aim the camera
    glLoadIdentity();
//    gluLookAt(0.0,0.0,1.0, 0.0,0.0,0.0, 0.0,1.0,0.0); //look through z-axis
//    gluLookAt(1.0,0.0,0.0, 0.0,0.0,0.0, 0.0,1.0,0.0); //look through x-axis
//    gluLookAt(0.0,1.0,0.0, 0.0,0.0,0.0, 0.0,1.0,0.0); //look through y-axis
    gluLookAt(1.0,1.0,1.0, 0.0,0.0,0.0, 0.0,1.0,0.0); //look 3D

    glClear(GL_COLOR_BUFFER_BIT);
    
    glPushMatrix();
    //draw x-axis in green
    glColor3d(0.0,1.0,0.0);
    xaxis(10.0);
    glPopMatrix();
    
    glPushMatrix();
    //draw y-axis in blue
    glColor3d(0.0,0.0,1.0);
    yaxis(10.0);
    glPopMatrix();

    glPushMatrix();
    //draw z-axis in red
    glColor3d(1.0,0.0,0.0);
    zaxis(10.0);
    glPopMatrix();
}

void DrawGround() {
    glPushMatrix();
    glBegin(GL_QUADS);
    glColor3d(0.0, .390625, 0.0);
    glVertex3d(0.0, 0.0, 0.0);
    glVertex3d(8.0, 0.0, 0.0);
    glVertex3d(8.0, 0.0, 8.0);
    glVertex3d(0.0, 0.0, 8.0);
    glEnd();
    glPopMatrix();
}

void DrawWalls() {
    glPushMatrix();
    glTranslated(1.5, 0.0, 0.0);

    //draw floor
    glPushMatrix();
    glColor3d(.625, .3203125, .17578125);
    glScaled(4.0,1.0,4.0);
    wall(.05);
    glPopMatrix();
    
    //draw back wall
    glPushMatrix();
    glColor3d(.82421875, .82421875, .82421875);
    glRotated(-90, 1.0, 0.0, 0.0);
    glScaled(4.0,1.0,3.0);
    wall(.05);
    glPopMatrix();

    //draw left wall
    glPushMatrix();
    glColor3d(2.0, .82421875, .82421875);
    glRotated(90.0, 0.0, 0.0, 1.0);
    glScaled(3.0,1.0,4.0);
    wall(.05);
    glPopMatrix();

    //draw right wall
    glPushMatrix();
    glColor3d(2.0, .82421875, .82421875);
    glRotated(90.0, 0.0, 0.0, 1.0);
    glScaled(3.0,1.0,4.0);
    glTranslated(0.0, -4, 0.0);
    wall(.05);
    glPopMatrix();
    
    //draw front wall
    glPushMatrix();
    glColor3d(.82421875, .82421875, .82421875);
    glRotated(-90.0, 1.0, 0.0, 0.0);
    glScaled(1.5,1.0,3.0);
    glTranslated(0.0, -4.0, 0.0);
    wall(.05);
    glPopMatrix();
    
    glPushMatrix();
    glColor3d(.82421875, .82421875, .82421875);
    glRotated(-90.0, 1.0, 0.0, 0.0);
    glScaled(1.5,1.0,3.0);
    glTranslated(1.6, -4.0, 0.0);
    wall(.05);
    glPopMatrix();
    
    //draw ceiling
    glPushMatrix();
    glColor3d(.625, .3203125, .17578125);
    glScaled(4.0,1.0,4.0);
    glTranslated(0.0, 3.0, 0.0);
    wall(.05);
    glPopMatrix();
    
    
    glPopMatrix();

}

void keyboard(unsigned char key, int x, int y) {
    //code goes here...
    //glutPostRedisplay();
}

void Display() {
    Initialize();
    DrawGround();
    DrawWalls();
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
    glutMainLoop();
    return 0;
}
