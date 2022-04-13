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
#include <math.h>
void display();
void reshape(int,int);

void init(){
    //Color mode is RGB and we can give the color in the range 0 - 1.0
    glClearColor(247.0/255,157.0/255,12.0/255,1.0);
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
    glColor3f(56/255.0, 29/255.0, 11/255.0);
    glBegin(GL_POLYGON);

    glVertex2f(10,10);
    glVertex2f(90,10);
    glVertex2f(90,60);
    glVertex2f(10,60);

    glEnd();

    glColor3f(240/255.0, 12/255.0, 54/255.0);
    glBegin(GL_POLYGON);

    glVertex2f(30,10);
    glVertex2f(50,10);
    glVertex2f(50,40);
    glVertex2f(30,40);

    glEnd();
   
    glColor3f(92/255.0, 64/255.0, 51/255.0);
    glBegin(GL_TRIANGLES);

    glVertex2f(5,60);
    glVertex2f(50,90);
    glVertex2f(95,60);

    glEnd();
   
    glColor3f(240/255.0, 12/255.0, 54/255.0);
    glBegin(GL_POLYGON);

    glVertex2f(60,20);
    glVertex2f(80,20);
    glVertex2f(80,35);
    glVertex2f(60,35);

    glEnd();
   
    glColor3f(56/255.0, 29/255.0, 11/255.0);
    glBegin(GL_LINES);

    glVertex2f(60,25);
    glVertex2f(80,25);
    glVertex2f(60,30);
    glVertex2f(80,30);

    glEnd();

    glColor3f(240/255.0, 12/255.0, 54/255.0);
    float theta;
    glBegin(GL_POLYGON);
    for(int i = 0;i<360;i++){
        //Degree to radius converter 1deg = pi/180
        theta = i*3.142 / 180;
        glVertex2f(50+5*cos(theta),70+5*sin(theta));
    }
    glEnd();

    glFlush();
}

void reshape(int w,int h){
    //Generally we work in ModelView matrix
    glViewport(0,0,w,h);
    //Used to change matrix mode from ModelView to Projection
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    gluOrtho2D(0,100,0,100);
    glMatrixMode(GL_MODELVIEW);
}