#include "stdafx.h"
#include <stdlib.h>
#include "glut.h"
#include <math.h>
#include <iostream>

void xaxis(double length)
{
    // draw a x-axis
    glPushMatrix();
    glBegin(GL_LINES);
    glVertex3d(0, 0, 0);
    glVertex3d(length,0,0); // along the x-axis
    glEnd();
    glTranslated(length -0.2, 0,0);
    glRotated(90, 0, 1, 0);
    glutWireCone(0.04, 0.2, 12, 9);
    glPopMatrix();
    
}

void yaxis(double length)
{
    // draw a z-axis
    glPushMatrix();
    glBegin(GL_LINES);
    glVertex3d(0, 0, 0);
    glVertex3d(0,length,0); // along the z-axis
    glEnd();
    glTranslated(0, length -0.2,0);
    glRotated(-90, 1, 0, 0);
    glutWireCone(0.04, 0.2, 12, 9);
    glPopMatrix();
    
}

void zaxis(double length)
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


void wall(double thickness)
{
    glPushMatrix();
    glTranslated(0.5,.5*thickness,0.5);
    glScaled(1.0,thickness,1.0);
    glutSolidCube(1);
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

void Initialize() {
    glMatrixMode(GL_PROJECTION); // set the view volume shape
    glLoadIdentity();
    glOrtho(-10,10,-10,10,-10,10);
	gluPerspective(60, 1, 0.0, 20);
    glMatrixMode(GL_MODELVIEW); // position and aim the camera
    glLoadIdentity();
//    gluLookAt(0,0,1, 0,0,0, 0.0,1.0,0.0); //look through z-axis
//    gluLookAt(1,0,0, 0,0,0, 0.0,1.0,0.0); //look through x-axis
//	  gluLookAt(0,1,0, 0,0,0, 0.0,1.0,0.0); //look through y-axis
    
	gluLookAt(5,8,5,0,0,0, 0.0,0,-1.0); //my lookat
//	gluLookAt(1.0,1.0,1.0, 0.0,0.0,0.0, 0.0,1.0,0.0); //your lookat


    glClear(GL_COLOR_BUFFER_BIT);
    
    glPushMatrix();
    //draw x-axis in green
    glColor3d(0,1,0);
    xaxis(10.0);
    glPopMatrix();
    
    glPushMatrix();
    //draw y-axis in blue
    glColor3d(0,0,1);
    yaxis(10.0);
    glPopMatrix();

    glPushMatrix();
    //draw z-axis in red
    glColor3d(1,0,0);
    zaxis(10.0);
    glPopMatrix();
}

void DrawGround() {
    glPushMatrix();
    glBegin(GL_QUADS);
    glColor3d(0.0, .390625, 0.0);
    glVertex3d(0.0, 0, 0.0);
    glVertex3d(8.0, 0, 0.0);
    glVertex3d(8.0, 0, 8.0);
    glVertex3d(0.0, 0, 8.0);
    glEnd();
    glPopMatrix();
}

void DrawWalls() {
    glPushMatrix();
    glTranslated(1.5, 0, 0);

    //draw floor
    glPushMatrix();
    glColor3d(.625, .3203125, .17578125);
    glScaled(4,1,4);
    wall(.05);
    glPopMatrix();
    
    //draw back wall
    glPushMatrix();
    glColor3d(.82421875, .82421875, .82421875);
    glRotated(-90, 1, 0, 0);
    glScaled(4,1,3);
    wall(.05);
    glPopMatrix();

    //draw left wall
    glPushMatrix();
    glColor3d(2, .82421875, .82421875);
    glRotated(90, 0, 0, 1);
    glScaled(3,1,4);
    wall(.05);
    glPopMatrix();

    //draw right wall
    glPushMatrix();
    glColor3d(2, .82421875, .82421875);
    glRotated(90, 0, 0, 1);
    glScaled(3,1,4);
    glTranslated(0, -4, 0);
    wall(.05);
    glPopMatrix();
    
    //draw front wall
    glPushMatrix();
    glColor3d(.82421875, .82421875, .82421875);
    glRotated(-90, 1, 0, 0);
    glScaled(1.5,1,3);
    glTranslated(0, -4, 0);
    wall(.05);
    glPopMatrix();
    
    glPushMatrix();
    glColor3d(.82421875, .82421875, .82421875);
    glRotated(-90, 1, 0, 0);
    glScaled(1.5,1,3);
    glTranslated(1.6, -4, 0);
    wall(.05);
    glPopMatrix();

	glPushMatrix();//  vertical wall in blue part 2
    glColor3d(0,0,1);
    glRotated(90, 0, 0, 1);
    glScaled(3,1,2);
    glTranslated(0, -2, 0);
    wall(.05);
    glPopMatrix();

    //draw in between horizontal wall in light blue ( 4 parts 3lshan el doors )
    glPushMatrix();//1
    glColor3d(0,1,1);
    glRotated(-90, 1, 0, 0);
    glScaled(0.8,1,3);
    glTranslated(0, -2, 0);
    wall(.05);
    glPopMatrix();

	// table in room 1
	glPushMatrix();//table in red
	glColor3d(1,0,0);
	glScaled(0.5,0.5,0.5);
	glTranslated(2,2,2);
	table(1,0.5,0.1,1);
	//table(0.1,0.05,0.01,0.1);
	glPopMatrix();



	glPushMatrix();//door 1,2 in black
    glColor3d(0,0,0);
    glRotated(-90, 1, 0, 0);
    glScaled(0.3,1,3);
    glTranslated(2.73, -2, 0);
    wall(.05);
    glPopMatrix();

	glPushMatrix();//okret el bab
	glColor3d(1,1,0);
	glScaled(0.5,0.5,0.5);
	glTranslated(2.0,-2,4);
	glutSolidSphere(1,2,2);
	glPopMatrix();


	glPushMatrix();//2
    glColor3d(0,1,1);
    glRotated(-90, 1, 0, 0);
    glScaled(0.8,1,3);
    glTranslated(1.4, -2, 0);
    wall(.05);
    glPopMatrix(); 

	
	glPushMatrix();//  vertical wall in blue part 1
    glColor3d(0,0,1);
    glRotated(90, 0, 0, 1);
    glScaled(3,1,2);
    glTranslated(0, -2, 1.0);
    wall(.05);
    glPopMatrix();

	glPushMatrix();//3
    glColor3d(0,1,1);
    glRotated(-90, 1, 0, 0);
    glScaled(0.8,1,3);
    glTranslated(2.5, -2, 0);
    wall(.05);
    glPopMatrix();

	glPushMatrix();//door 3,4 in black
    glColor3d(0,0,0);
    glRotated(-90, 1, 0, 0);
    glScaled(0.3,1,3);
    glTranslated(9.4, -2, 0);
    wall(.05);
    glPopMatrix();

	glPushMatrix();//4
    glColor3d(0,1,1);
    glRotated(-90, 1, 0, 0);
    glScaled(0.8,1,3);
    glTranslated(3.9, -2, 0);
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

