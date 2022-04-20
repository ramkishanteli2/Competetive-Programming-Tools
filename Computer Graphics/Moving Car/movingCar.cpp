
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

void timer(int);
void init(){
    //Color mode is RGB and we can give the color in the range 0 - 1.0
    glClearColor(0.0,0.0,0,1.0);
}

int main(int argc,char ** argv){

    glutInit(&argc,argv); //Initialize the glut library
    //Using GLUT_DOUBLE we are using two buffer memory for drawing
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE); // Initialize display color mode

    glutInitWindowPosition(200,100);
    glutInitWindowSize(700,600);

    glutCreateWindow("Learning OpenGL");

    //Used for clear the windows and redraw the stuff
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);

    glutTimerFunc(0,timer,0);
    init();
    glutMainLoop();
}
float i = 0;
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
	    glColor3f(1.0,0.0,0.0);
	    glBegin(GL_POLYGON);

	    glVertex2f(i+5,5);
	    glVertex2f(i+20,5);
	    glVertex2f(i+20,10);
	    glVertex2f(i+5,10);

	    glEnd();

	    glColor3f(1.0,1.0,1.0);
	    glBegin(GL_TRIANGLES);

	    glVertex2f(i+7,10);
	    glVertex2f(i+9,15);
	    glVertex2f(i+9,10);

	    glEnd();

	    glBegin(GL_TRIANGLES);

	    glVertex2f(i+16,10);
	    glVertex2f(i+16,15);
	    glVertex2f(i+18,10);

	    glEnd();


	    glColor3f(1.0,1.0,0.0);
	    glBegin(GL_POLYGON);

	    glVertex2f(i+9,10);
	    glVertex2f(i+16,10);
	    glVertex2f(i+16,15);
	    glVertex2f(i+9,15);

	    glEnd();

	    glColor3f(0.0,1.0,0.0);
	    float theta;
	    glBegin(GL_POLYGON);
	    int r = 2;
	    for(int j = 0;j<360;j++){
		//Degree to radius converter 1deg = pi/180
		theta = j*3.142 / 180;
		glVertex2f(i+8+r*cos(theta),5+r*sin(theta));
	    }
	    glEnd();

	    glBegin(GL_POLYGON);
	    r = 2;
	    for(int j = 0;j<360;j++){
		//Degree to radius converter 1deg = pi/180
		theta = j*3.142 / 180;
		glVertex2f(i+17+r*cos(theta),5+r*sin(theta));
	    }
	    glEnd();
    //Here we are just clearing the buffers
    //glFlush();
    //This will change buffer from front to back and back to front
    glutSwapBuffers();
}

void reshape(int w,int h){
    //Generally we work in ModelView matrix
    glViewport(0,0,w,h);
    //Used to change matrix mode from ModelView to Projection
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    gluOrtho2D(0,60,0,60);
    glMatrixMode(GL_MODELVIEW);
}

void timer(int){
    glutPostRedisplay();
    glutTimerFunc(1000/60,timer,0);
    
    if(i < 40){
    	i += 0.15;
    }   
}
