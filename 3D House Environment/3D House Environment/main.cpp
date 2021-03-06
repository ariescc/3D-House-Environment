#include "stdafx.h"
#include <stdlib.h>
#include "glut.h"
#include <math.h>
#include <iostream>

double camerax = 15.0;
double cameray = 20.0;
double cameraz = 15.0;

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
    glutSolidCube(1);
    glPopMatrix();
}

void Initialize() {
    glMatrixMode(GL_PROJECTION); // set the view volume shape
    glLoadIdentity();
//    glOrtho(-10.0,10.0,-10.0,10.0,-10.0,10.0);
    gluPerspective(45.0, 1.33, 0.5, 48.0);
    glMatrixMode(GL_MODELVIEW); // position and aim the camera
    glLoadIdentity();
//    gluLookAt(0.0,0.0,20.0, 0.0,0.0,0.0, 0.0,1.0,0.0); //look through z-axis
//    gluLookAt(20.0,0.0,0.0, 0.0,0.0,0.0, 0.0,1.0,0.0); //look through x-axis
//    gluLookAt(0.0,20.0,0.0, 0.0,0.0,0.0, 0.0,1.0,0.0); //look through y-axis
//    gluLookAt(0,30,0, 0.0,0.0,0.0, 0.0,0.0,1.0); //look 3D
    gluLookAt(camerax,cameray,cameraz, 0.0,0.0,0.0, 0.0,1.0,0.0); //look 3D

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
    glScaled(1.5, 1.0, 1.5);
    glTranslated(-2.0, 0.0, -2.0);
    glBegin(GL_QUADS);
    glColor3d(0.0, .390625, 0.0);
    glVertex3d(-4.0, 0.0, -4.0);
    glVertex3d(8.0, 0.0, -4.0);
    glVertex3d(8.0, 0.0, 8.0);
    glVertex3d(-4.0, 0.0, 8.0);
    glEnd();
    glPopMatrix();
}

void tableLeg(double thick,double len)
{
	glPushMatrix();
	glTranslated(0,len/2,0);
	glScaled(thick,len,thick);
	glutSolidCube(1.0);
	glPopMatrix();
}
void jackpart()
{ 
	glPushMatrix();
	glScaled(0.2,0.2,1.0);
	glutSolidSphere(1,15,15);
	glPopMatrix();
	glPushMatrix();
	glTranslated(0,0,1.2);
	glutSolidSphere(0.2,15,15);
	glTranslated(0,0,-2.4);
	glutSolidSphere(0.2,15,15);
	glPopMatrix();
}
void jack(){
	glPushMatrix();
	jackpart();
	glRotated(90.0,0,1,0);
	jackpart();
	glRotated(90.0,1,0,0);
	jackpart();
	glPopMatrix();
}

void table(double topWid,double topThick, double legThick,double legLen)
{
	//draw a table - atop and four legs
	glPushMatrix();
	glTranslated(0,legLen,0);
	glScaled(topWid,topThick,topWid);
	glutSolidCube(1.0);
	glPopMatrix();
	double dist=0.95*topWid/2.0-legThick/2.0;
	glPushMatrix(); glTranslated(dist,0,dist);
	tableLeg(legThick,legLen);
	glTranslated(0,0,-2*dist);
	tableLeg(legThick,legLen);
	glTranslated(-2*dist,0,2*dist);
	tableLeg(legThick,legLen);
	glTranslated(0,0,-2*dist);
	tableLeg(legThick,legLen);
	glPopMatrix();
}

void DrawWalls() {
    glPushMatrix();
    glTranslated(-4.0, 0.0, -5.3);
    glScaled(2.0, 2.0, 2.0);
   
    //draw floor
    glPushMatrix();
    glColor3d(.625, .3203125, .17578125);
    glScaled(4.0,1.0,5.5);
    wall(.05);

	glPushMatrix();//red table in 2nd room
	glColor3d(1.0, 0.0, 0.0);
    glScaled(0.25,1,0.2);
	glTranslated(1.5,0,1.5);
	table(1,0.5,0.1,1);
	glPopMatrix();

    //draw back wall
    glPushMatrix();
    glColor3d(.0, .0, .0);
    glRotated(-90, 1.0, 0.0, 0.0);
    glScaled(1.0, 0.1, 3.0);
    wall(.05);

    //draw middle wall
    glPushMatrix();
    glColor3d(.82421875, .82421875, .82421875);
    glTranslated(0.0, -4.8, 0.0);
    wall(.05);
    
    //draw middle door
    glPushMatrix();
    glColor3d(0.0, 0.0, .82421875);
    glTranslated(.4, 0.0, 0.0);
    glScaled(0.2, 1.0, 0.65);
    wall(.05);
    glPopMatrix();
    
	glPushMatrix();//ball in room 1
	glColor3d(1.0, 0.0, 0.0);
    glScaled(1.28,5,2);
	glTranslated(0.2,-0.5,0.1);
	glutSolidSphere(0.1,10,10);
	glPopMatrix();

	glPushMatrix();//teapot in room 1
	glColor3d(0.0, 0.0, 1.0);
	glRotated(90, 1.0, 0.0, 0.0);
    glScaled(0.6,2,3);
	glTranslated(1.4,0.08,1.5);
	glutSolidTeapot(0.1);
	glPopMatrix();

	glPushMatrix();//shwyet le3ab atfal kda :D
	glColor3d(0.0, 1.0, 0.0);
	glRotated(90, 1.0, 0.0, 0.0);
    glScaled(0.1,0.2,0.4);
	glTranslated(1.3,1.0,2.0);
	jack();
	glPopMatrix();

	glPushMatrix();
	glColor3d(0.0, 1.0, 0.0);
	glRotated(90, 1.0, 0.0, 0.0);
    glScaled(0.1,0.2,0.4);
	glTranslated(4.3,1.0,2.0);
	jack();
	glPopMatrix();

	glPushMatrix();
	glColor3d(0.0, 1.0, 0.0);
	glRotated(90, 1.0, 0.0, 0.0);
    glScaled(0.1,0.2,0.4);
	glTranslated(5.3,1.0,4.0);
	jack();
	glPopMatrix();

    //draw left wall
    glPushMatrix();
    glColor3d(2.0, .82421875, .82421875);
    glRotated(90.0, 0.0, 0.0, 1.0);
    glTranslated(-5.2, 0.0, .0);
    glScaled(10.1, 0.2, 1.0);
    wall(.05);
    
    //draw right wall
    glPushMatrix();
    glColor3d(2.0, .82421875, .82421875);
    glTranslated(0.0, -5.0, 0.0);
    wall(.05);
    
    glPopMatrix();
    glPopMatrix();

    
    //draw front wall
    glPushMatrix();
    glColor3d(.82421875, .82421875, .82421875);
    glTranslated(0.0, -5.25, 0.0);
    wall(.05);
    
    //draw front door
    glPushMatrix();
    glColor3d(0.0, 0.0, .82421875);
    glTranslated(.4, 0.0, 0.0);
    glScaled(0.2, 1.0, 0.65);
    wall(.05);
    glPopMatrix();
    
    glPopMatrix(); //front wall
    
    glPopMatrix(); //middle wall
    
    glPopMatrix(); //back wall
    
    ////draw ceiling
    //glPushMatrix();
    //glColor3d(.625, .3203125, .17578125);
    //glTranslated(0.0, 3.0, 0.0);
    //wall(.05);
    //glPopMatrix(); //ceiling
    
    glPopMatrix(); //floor
    glPopMatrix();

	
}



void keyboard(unsigned char key, int x, int y) {
    if(key == 'l' || key == 'L') {
            camerax -= 0.2;
    }
    if(key == 'r' || key == 'R') {
            camerax += 0.2;
    }
    if(key == 'd' || key == 'D') {
        if (cameray > 1.0) {
            cameray -= 0.2;
        }
    }
    if(key == 'u' || key == 'U') {
        if (cameray < 20.0) {
            cameray += 0.2;
        }
    }
    if(key == 'f' || key == 'F') {
            cameraz -= 0.2;
    }
    if(key == 'b' || key == 'B') {
        if (cameraz < 20.0) {
            cameraz += 0.2;
        }
    }
    

    glutPostRedisplay();
}

void Display() {
    Initialize();
    DrawGround();
    DrawWalls();
    glFlush();
}

void main(int argc, char ** argv) {
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowSize(1000,600);
    glutInitWindowPosition(200,90);
    glutCreateWindow("3D House Environment");
    glutDisplayFunc(Display);
    glClearColor(1.0f,1.0f,1.0f,1.0f);
    glutKeyboardFunc(keyboard);
    glutMainLoop();
}

