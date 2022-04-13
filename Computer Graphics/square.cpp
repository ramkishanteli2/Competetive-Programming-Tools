
/*
ViewPort :- View port is a place where our content will be displayed
-----------
|         |
|         |
|         |
|         |
-----------
(0,0)
*/


#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
void display();
void reshape(int,int);

void init(){
    //Color mode is RGB and we can give the color in the range 0 - 1.0
    glClearColor(0.0,0.0,0,1.0);
}

int main(int argc,char ** argv){

    glutInit(&argc,argv); //Initialize the glut library
    glutInitDisplayMode(GLUT_RGB); // Initialize display color mode

    glutInitWindowPosition(200,100);
    glutInitWindowSize(700,600);

    glutCreateWindow("Learning OpenGL");

    //Used for clear the windows and redraw the stuff
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);

    init();
    glutMainLoop();
}
void display(){
    //Used to first clear the buffer
    //glClear function sets the default background color to black
    glClear(GL_COLOR_BUFFER_BIT);
    //Clear all rotations and things
    glLoadIdentity();
    //Used to draw the stuff again onto the screen
    //Whatever stored in the buffer will not automatically changed to the screen before calling the glFlush();
    //Everything work on vertex in openGL
    glLineWidth(4.0);
    //Parameter passed in glBegin() is called geometric primitives like GL_POINTS,GL_TRIANGLE
    glBegin(GL_LINE_LOOP);

    glVertex2f(25,25);
    glVertex2f(-25,25);
    glVertex2f(-25,-25);
    glVertex2f(25,-25);

    glEnd();


    glFlush();
}

void reshape(int w,int h){
    //Generally we work in ModelView matrix
    glViewport(0,0,w,h);
    //Used to change matrix mode from ModelView to Projection
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    gluOrtho2D(-30,30,-30,30);
    glMatrixMode(GL_MODELVIEW);
}
