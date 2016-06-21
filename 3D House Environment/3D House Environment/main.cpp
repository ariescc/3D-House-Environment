
#include <iostream>
#include <OpenGl/gl.h>
#include <OpenGl/glu.h>
#include <GLUT/glut.h>

void keyboard(unsigned char key, int x, int y) {
    //code goes here...
    //glutPostRedisplay();
}

void Display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glPushMatrix();
    //code goes here...
    glPopMatrix();
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
