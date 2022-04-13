
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
#include <iostream>
#include <algorithm>
#include <math.h>

using namespace std;

void display();
void reshape(int,int);
void init(){
    //Color mode is RGB and we can give the color in the range 0 - 1.0
    glClearColor(0.0,0.0,0,1.0);
}
int sx,sy,ex,ey;
void DDAAlgorithm(int x1,int y1,int x2,int y2){
    /*
        Algorithm:
            find dx = x2-x1
                 dy = y2-y1
                 steps = max(dx,dy)
                 m = dy/dx
                 xin = dx/steps
                 yin = dy/steps

            for(int i = 0;i<=steps;i++){
                putpixel(x1,y1);
                x1 = x1 + xin;
                y1 = y1 + yin;
            }

    */
    int dx = x2-x1, dy = y2-y1;
    int steps = max(abs(dx),abs(dy));
    float xin = dx*1.0/steps;
    float yin = dy*1.0/steps;
    float sx = x1;
    float sy = y1;

    glPointSize(6.0);
    //Parameter passed in glBegin() is called geometric primitives like GL_POINTS,GL_TRIANGLE
    glBegin(GL_POINTS);

    for(int i = 0;i<steps;i++){

        glVertex2i(round(sx),round(sy));

        sx = sx + xin;
        sy = sy + yin;
    }

    glEnd();

}

int main(int argc,char ** argv){

    glutInit(&argc,argv); //Initialize the glut library
    glutInitDisplayMode(GLUT_RGB); // Initialize display color mode

    glutInitWindowPosition(200,100);
    glutInitWindowSize(700,600);

    glutCreateWindow("Learning OpenGL");


    cout << "Enter First Points Coordinates (x1,y1): ";
    cin >> sx >> sy;

    cout << "Enter Second Points Coordinates (x2,y2): ";
    cin >> ex >> ey;
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


    DDAAlgorithm(sx,sy,ex,ey);

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
