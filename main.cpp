#include<windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <GL/glut.h>
#include <math.h>
#include <string.h>
#define ESCAPE 27

GLint window;
GLint window2;
GLint Xsize=1500;
GLint Ysize=800;
float i,theta;
GLint nml=0,day=1;

char name3[]="PROJECT:  3D CAR  ANIMATION";

GLfloat xt=0.0,yt=0.0,zt=0.0,xw=0.0;  /* x,y,z translation */
GLfloat tx=195,ty=62;
GLfloat xs=1.0,ys=1.0,zs=1.0;

GLfloat xangle=15.0,yangle=-60.0,zangle=0.0,angle=0.0;   /* axis angles */

GLfloat r=0,g=0,b=1;
GLint light=1;
int count=1,flg=1;
int view=0;
int flag1=0,aflag=1;            //to switch car driving mode
   //to switch fog effect
GLUquadricObj *t;

static void SpecialKeyFunc( int Key, int x, int y );

/* Simple  transformation routine */
GLvoid Transform(GLfloat Width, GLfloat Height)
{
  glViewport(0, 0, Width, Height);              /* Set the viewport */
  glMatrixMode(GL_PROJECTION);                  /* Select the projection matrix */
  glLoadIdentity();				/* Reset The Projection Matrix */
  gluPerspective(45.0,Width/Height,0.1,100.0);  /* Calculate The Aspect Ratio Of The Window */
  glMatrixMode(GL_MODELVIEW);                   /* Switch back to the modelview matrix */
}


/* A general OpenGL initialization function.  Sets all of the initial parameters. */
GLvoid InitGL(GLfloat Width, GLfloat Height)
{

  glClearColor(1.0, 1.0, 1.0, 1.0);
  glLineWidth(2.0);              /* Add line width,   ditto */
  Transform( Width, Height ); /* Perform the transformation */
  //newly added
  t=gluNewQuadric();
        gluQuadricDrawStyle(t, GLU_FILL);

glEnable(GL_LIGHTING);

glEnable(GL_LIGHT0);

// Create light components
GLfloat ambientLight[] = { 0.2f, 0.2f, 0.2f, 1.0f };
GLfloat diffuseLight[] = { 0.8f, 0.8f, 0.8, 1.0f };
GLfloat specularLight[] = { 0.5f, 0.5f, 0.5f, 1.0f };
GLfloat position[] = { 1.5f, 1.0f, 4.0f, 1.0f };

// Assign created components to GL_LIGHT0
glLightfv(GL_LIGHT0, GL_AMBIENT, ambientLight);
glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuseLight);
glLightfv(GL_LIGHT0, GL_SPECULAR, specularLight);
glLightfv(GL_LIGHT0, GL_POSITION, position);

}

void init()
{
    glClearColor(0,0,0,0);
	glPointSize(5.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0.0,900.0,0.0,600.0,50.0,-50.0);
	glutPostRedisplay(); 		// request redisplay
}


/* The main drawing function

   In here we put all the OpenGL and calls to routines which manipulate
   the OpenGL state and environment.

   This is the function which will be called when a "redisplay" is requested.
*/

void display_string(int x, int y, char *string, int font)
{
    int len,i;
	glColor3f(0.8,0.52,1.0);
	glRasterPos2f(x, y);
    len = (int) strlen(string);
    for (i = 0; i < len; i++) {
    //if(font==1)
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,string[i]);
    }
}

void display1(void)
{
	glClearColor(0.5,0.9,4.5,5.5);

    glBegin(GL_LINES);
    glVertex2d(310,330);
    glVertex2d(550,330);
    glEnd();

    glBegin(GL_LINES);
    glVertex2d(310,380);
    glVertex2d(550,380);
    glEnd();

    glBegin(GL_LINES);
    glVertex2d(310,330);
    glVertex2d(310,380);
    glEnd();

    glBegin(GL_LINES);
    glVertex2d(550,330);
    glVertex2d(550,380);
    glEnd();

     glBegin(GL_LINES);
    glVertex2d(305,325);
    glVertex2d(555,325);
    glEnd();

    glBegin(GL_LINES);
    glVertex2d(305,385);
    glVertex2d(555,385);
    glEnd();

    glBegin(GL_LINES);
    glVertex2d(305,325);
    glVertex2d(305,385);
    glEnd();

    glBegin(GL_LINES);
    glVertex2d(555,325);
    glVertex2d(555,385);
    glEnd();



	display_string(320,350,"PRESS SPACE BAR TO ENTER",1);
	glutPostRedisplay();
	glutSwapBuffers();
}

GLvoid DrawGLScene()
{
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);	/* Clear The Screen And The Depth Buffer */
if(view==0)
{
init();
display1();
}
else
{
  if(count==1)
	InitGL(Xsize,Ysize);
  if(aflag==1)// Initialize our window.
  glClearColor(1,1,1,1);
   else
	  glClearColor(0.1,0.1,0.1,0);
  glPushMatrix();
  glLoadIdentity();
  glTranslatef(-1.0,0.0,-3.5);
  glRotatef(xangle,1.0,0.0,0.0);
  glRotatef(yangle,0.0,1.0,0.0);
  glRotatef(zangle,0.0,0.0,1.0);
  glTranslatef(xt,yt,zt);
  glScalef(xs,ys,zs);
  glEnable(GL_COLOR_MATERIAL);
  glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);
  glColor3f(1.0,.75,0.0);
  glPointSize(30.0);
  glBegin(GL_POINTS);
  glVertex3f(0.2,0.3,0.3);
  glVertex3f(0.2,0.3,0.5);
  glEnd();
  glPointSize(200.0);
  glBegin(GL_QUADS);                /* OBJECT MODULE*/

  /* top of cube*/
  //************************FRONT BODY****************************************
  glColor3f(1,0,0);//garir enginer oporer onsho
  glVertex3f( 0.2, 0.4,0.6);
  glVertex3f(0.6, 0.5,0.6);
  glVertex3f(0.6, 0.5,0.2);
  glVertex3f( 0.2,0.4,0.2);

  /* bottom of cube*/
  glColor3f(0.1,0.9,0.6);// garir niche
  glVertex3f( 0.2,0.2,0.6);
  glVertex3f(0.6,0.2,0.6);
  glVertex3f(0.6,0.2,0.2);
  glVertex3f( 0.2,0.2,0.2);

  /* front of cube*/
  glColor3f(0,0,0.5);// garir samone
  glVertex3f( 0.2,0.2,0.6);
  glVertex3f(0.2, 0.4,0.6);
  glVertex3f(0.2,0.4,0.2);
  glVertex3f( 0.2,0.2,0.2);

  /* back of cube.*/
  glColor3f(1,1,1);// gair niche
  glVertex3f(0.6,0.2,0.6);
  glVertex3f(0.6,0.5,0.6);
  glVertex3f(0.6,0.5,0.2);
  glVertex3f( 0.6,0.2,0.2);

  /* left of cube*/
  glColor3f(0,0.8,0.5);// garir samone bam pashe
  glVertex3f(0.2,0.2,0.6);
  glVertex3f(0.6,0.2,0.6);
  glVertex3f(0.6,0.5,0.6);
  glVertex3f(0.2,0.4,0.6);

  /* Right of cube */
   glColor3f(0,0.8,0.5);//garir samone dan pashe
  glVertex3f(0.2,0.2,0.2);
  glVertex3f( 0.6,0.2,0.2);
  glVertex3f( 0.6,0.5,0.2);
  glVertex3f( 0.2,0.4,0.2);
//****************************************************************************
  glColor3f(1,0,0);//garir opore
  glVertex3f(0.7,0.65,0.6);
  glVertex3f(0.7,0.65,0.2);
  glVertex3f(1.7,0.65,0.2);        //top cover
  glVertex3f(1.7,0.65,0.6);
//***************************back guard******************************
  glColor3f(1,0,0); // garir pisone dalar opor      //////////////////////////////////////////     /* Set The Color To Blue*/
  glVertex3f( 1.8, 0.5,0.6);
  glVertex3f(1.8, 0.5,0.2);
  glVertex3f(2.1, 0.4, 0.2);
  glVertex3f(2.1,0.4,0.6);

  /* bottom of cube*/
  glColor3f(0,0,0);
  glVertex3f( 2.1,0.2,0.6);
  glVertex3f(2.1,0.2,0.2);
  glVertex3f(1.8,0.2,0.6);
  glVertex3f( 1.8,0.2,0.6);

  /* back of cube.*/
  glColor3f(0,0,0.5);// garir pisone niche///////////////////////////////////////////////////
  glVertex3f(2.1,0.4,0.6);
  glVertex3f(2.1,0.4,0.2);
  glVertex3f(2.1,0.2,0.2);
  glVertex3f(2.1,0.2,0.6);

  /* left of cube*/
   glColor3f(0,0.8,0.5);// garir pisone dan
  glVertex3f(1.8,0.2,0.2);
  glVertex3f(1.8,0.5,0.2);
  glVertex3f(2.1,0.4,0.2);
  glVertex3f(2.1,0.2,0.2);

  /* Right of cube */
   glColor3f(0,0.8,0.5);//garir pisone bam
  glVertex3f(1.8,0.2,0.6);
  glVertex3f(1.8,0.5,0.6);
  glVertex3f(2.1,0.4,0.6);
  glVertex3f(2.1,0.2,0.6);
//******************MIDDLE BODY************************************
   glColor3f(0,.8,.5);// garir body bam pase
  glVertex3f( 0.6, 0.5,0.6);
  glVertex3f(0.6, 0.2,0.6);
  glVertex3f(1.8, 0.2, 0.6);
  glVertex3f(1.8,0.5,0.6);

  /* bottom of cube*/
  glColor3f(0,0,0);// garir niche
  glVertex3f( 0.6,0.2,0.6);
  glVertex3f(0.6,0.2,0.2);
  glVertex3f(1.8,0.2,0.2);
  glVertex3f( 1.8,0.2,0.6);

  /* back of cube.*/
   glColor3f(0,.8,.5);// garir body dan pase
  glVertex3f(0.6,0.5,0.2);
  glVertex3f(0.6,0.2,0.2);
  glVertex3f(1.8,0.2,0.2);
  glVertex3f(1.8,0.5,0.2);
//*********************ENTER WINDOW**********************************
  glColor3f(0.3,0.3,0.3);
  glVertex3f( 0.77, 0.63,0.2);
  glVertex3f(0.75, 0.5,0.2);        //quad front window
  glVertex3f(1.2, 0.5, 0.2);
  glVertex3f( 1.22,0.63,0.2);

  glVertex3f(1.27,0.63,.2);
  glVertex3f(1.25,0.5,0.2);        //quad back window
  glVertex3f(1.65,0.5,0.2);
  glVertex3f(1.67,0.63,0.2);

  glColor3f(r,g,b);
  glVertex3f(0.7,0.65,0.2);
  glVertex3f(0.7,0.5,.2);       //first separation
  glVertex3f(0.75,0.5,0.2);
  glVertex3f(0.77,0.65,0.2);

  glVertex3f(1.2,0.65,0.2);
  glVertex3f(1.2,0.5,.2);       //second separation
  glVertex3f(1.25,0.5,0.2);
  glVertex3f(1.27,0.65,0.2);

  glVertex3f(1.65,0.65,0.2);
  glVertex3f(1.65,0.5,.2);     //3d separation
  glVertex3f(1.7,0.5,0.2);
  glVertex3f(1.7,0.65,0.2);

  glVertex3f( 0.75, 0.65,0.2);
  glVertex3f(0.75, 0.63,0.2);        //line strip
  glVertex3f(1.7, 0.63, 0.2);
  glVertex3f( 1.7,0.65,0.2);

  glVertex3f( 0.75, 0.65,0.6);
  glVertex3f(0.75, 0.63,0.6);        //line strip
  glVertex3f(1.7, 0.63, 0.6);
  glVertex3f( 1.7,0.65,0.6);

  glColor3f(0.3,0.3,0.3);
  glVertex3f( 0.77, 0.63,0.6);
  glVertex3f(0.75, 0.5,0.6);        //quad front window
  glVertex3f(1.2, 0.5, 0.6);
  glVertex3f( 1.22,0.63,0.6);

  glVertex3f(1.27,0.63,.6);
  glVertex3f(1.25,0.5,0.6);        //quad back window
  glVertex3f(1.65,0.5,0.6);
  glVertex3f(1.67,0.63,0.6);

  glColor3f(r,g,b);
  glVertex3f(0.7,0.65,0.6);
  glVertex3f(0.7,0.5,.6);       //first separation
  glVertex3f(0.75,0.5,0.6);
  glVertex3f(0.77,0.65,0.6);

  glVertex3f(1.2,0.65,0.6);
  glVertex3f(1.2,0.5,.6);       //second separation
  glVertex3f(1.25,0.5,0.6);
  glVertex3f(1.27,0.65,0.6);

  glVertex3f(1.65,0.65,0.6);
  glVertex3f(1.65,0.5,.6);
  glVertex3f(1.7,0.5,0.6);
  glVertex3f(1.7,0.65,0.6);
  glEnd();
 //**************************************************************
  glBegin(GL_QUADS);
  /* top of cube*/
  glColor3f(0.3,0.3,0.3);
  glVertex3f( 0.6, 0.5,0.6);
  glVertex3f(0.6, 0.5,0.2);        //quad front window
  glVertex3f(0.7, 0.65, 0.2);
  glVertex3f( 0.7,0.65,0.6);

  glVertex3f(1.7,0.65,.6);
  glVertex3f(1.7,0.65,0.2);        //quad back window
  glVertex3f(1.8,0.5,0.2);
  glVertex3f(1.8,0.5,0.6);

//*****************************road and surrounding development***********************************

  {
	glPushMatrix();
	glTranslatef(xw,0,0);
  glColor3f(0,1,0);
  glVertex3f(-100,0.1,-100);
  glVertex3f(-100,0.1,0);         //a green surroundings
  glVertex3f(100,0.1,0);
  glVertex3f(100,0.1,-100);

  glColor3f(0.7,0.7,0.7);
  glVertex3f(-100,0.1,0);
  glVertex3f(-100,0.1,0.50);         //a long road
  glVertex3f(100,0.1,0.50);
  glVertex3f(100,0.1,0);

  glColor3f(1.0,0.75,0.0);
  glVertex3f(-100,0.1,0.50);       //a median
  glVertex3f(-100,0.1,0.55);
  glVertex3f(100,0.1,0.55);
  glVertex3f(100,0.1,0.50);

  glColor3f(0.7,0.7,0.7);
  glVertex3f(-100,0.1,0.55);
  glVertex3f(-100,0.1,1);         //a long road
  glVertex3f(100,0.1,1);
  glVertex3f(100,0.1,0.55);

  glColor3f(0,1,0);
  glVertex3f(-100,0.1,1);
  glVertex3f(-100,0.1,100);         //a green surroundings
  glVertex3f(100,0.1,100);
  glVertex3f(100,0.1,1);
    glPopMatrix();
  }
  glEnd();


  {
	  glPushMatrix();
	  glTranslatef(xw,0,0);
	  glColor3f(0.2,.1,0.1);
	  glBegin(GL_QUADS);

	  for(i=0;i<200;i+=0.2)
	  {
		  glVertex3f(-100+i,0,1);
		  glVertex3f(-99.9+i,0,1);
		  glVertex3f(-99.9+i,0.2,1);
		  glVertex3f(-100+i,0.2,1);
		  i+=0.5;
	  }
	  for(i=0;i<200;i+=0.2)
	  {
		  glVertex3f(-100+i,0,0);
		  glVertex3f(-99.9+i,0,0);
		  glVertex3f(-99.9+i,0.2,0);
		  glVertex3f(-100+i,0.2,0);
		  i+=0.5;
	  }
	  glEnd();
	  glPopMatrix();
  }
  /**********************************************************************************/
glBegin(GL_TRIANGLES);                /* start drawing the cube.*/

  /* top of cube*/
  glColor3f(0.3,0.3,0.3);
  glVertex3f( 0.6, 0.5,0.6);
  glVertex3f( 0.7,0.65,0.6);       //tri front window
  glVertex3f(0.7,0.5,0.6);

  glVertex3f( 0.6, 0.5,0.2);
  glVertex3f( 0.7,0.65,0.2);       //tri front window
  glVertex3f(0.7,0.5,0.2);

  glVertex3f( 1.7, 0.65,0.2);
  glVertex3f( 1.8,0.5,0.2);       //tri back window
  glVertex3f( 1.7,0.5,0.2);

  glVertex3f( 1.7, 0.65,0.6);
  glVertex3f( 1.8,0.5,0.6);       //tri back window
  glVertex3f(1.7,0.5,0.6);

glEnd();
//************IGNITION SYSTEM**********************************
glPushMatrix();
   glColor3f(0.7,0.7,0.7);
   glTranslatef(1.65,0.2,0.3);
   glRotatef(90.0,0,1,0);
   gluCylinder(t,0.01,0.01,.5,10,10);
glPopMatrix();
//********************WHEEL*********************************************
glColor3f(0.7,0.7,0.7);
glPushMatrix();
  glBegin(GL_LINE_STRIP);
	  for(theta=0;theta<360;theta=theta+20)
	  {
  glVertex3f(0.6,0.2,0.62);
  glVertex3f(0.6+(0.08*(cos(((theta+angle)*3.14)/180))),0.2+(0.08*(sin(((theta+angle)*3.14)/180))),0.62);
	  }
glEnd();

glBegin(GL_LINE_STRIP);
	  for(theta=0;theta<360;theta=theta+20)
	  {
  glVertex3f(0.6,0.2,0.18);
  glVertex3f(0.6+(0.08*(cos(((theta+angle)*3.14)/180))),0.2+(0.08*(sin(((theta+angle)*3.14)/180))),0.18);
	  }
glEnd();

glBegin(GL_LINE_STRIP);
for(theta=0;theta<360;theta=theta+20)
	  {
  glVertex3f(1.7,0.2,0.18);
  glVertex3f(1.7+(0.08*(cos(((theta+angle)*3.14)/180))),0.2+(0.08*(sin(((theta+angle)*3.14)/180))),0.18);
	  }
glEnd();

glBegin(GL_LINE_STRIP);
for(theta=0;theta<360;theta=theta+20)
	  {
  glVertex3f(1.7,0.2,0.62);
 glVertex3f(1.7+(0.08*(cos(((theta+angle)*3.14)/180))),0.2+(0.08*(sin(((theta+angle)*3.14)/180))),0.62);
	  }
 glEnd();
  glTranslatef(0.6,0.2,0.6);
  glColor3f(0,0,0);
  glutSolidTorus(0.025,0.07,10,25);

  glTranslatef(0,0,-0.4);
  glutSolidTorus(0.025,0.07,10,25);

  glTranslatef(1.1,0,0);
  glutSolidTorus(0.025,0.07,10,25);

  glTranslatef(0,0,0.4);
  glutSolidTorus(0.025,0.07,10,25);
  glPopMatrix();
//*************************************************************
  glPopMatrix();
  glEnable(GL_DEPTH_TEST);
  glutPostRedisplay();
  glutSwapBuffers();
 }
}
/*  The function called whenever a "normal" key is pressed. */
void NormalKey(GLubyte key, GLint x, GLint y)
{

    switch ( key )    {
     case ESCAPE : printf("escape pressed. exit.\n");
	               glutDestroyWindow(window);	/* Kill our window */
	               exit(0);
                   break;

      case ' ':    view=1;
                   DrawGLScene();
                   break;

      case 'x': xangle += 5.0;
                      glutPostRedisplay();
                      break;

       case 'X':xangle -= 5.0;
                       glutPostRedisplay();
                       break;

      case 'y':
        yangle += 5.0;
        glutPostRedisplay();
        break;

     case 'Y':
        yangle -= 5.0;
        glutPostRedisplay();
        break;

     case 'z':
        zangle += 5.0;
        glutPostRedisplay();
        break;

     case 'Z':
        zangle -= 5.0;
        glutPostRedisplay();
        break;

      default:
          break;
    }
}
static void SpecialKeyFunc( int Key, int x, int y )
{
	switch ( Key ) {
	    case GLUT_KEY_UP:
		angle+=5;
		xw+=0.1;
	    glutPostRedisplay();
		break;
        case GLUT_KEY_DOWN:
		angle+=5;
		xw-=0.1;
        glutPostRedisplay();
		break;
	}
}
//*************************** Main ***************************************************************
int main(int argc, char **argv)
{
/* Initialisation and window creation */
  glutInit(&argc, argv);               /* Initialize GLUT state. */
  glutInitDisplayMode(GLUT_RGBA |      /* RGB and Alpha */
                      GLUT_DOUBLE|     /* double buffer */
                      GLUT_DEPTH);     /* Z buffer (depth) */
  glutInitWindowSize(Xsize,Ysize);     /* set initial window size. */
  glutInitWindowPosition(0,0);         /* upper left corner of the screen. */
  glutCreateWindow("3D CAR ANIMATION"); /* Open a window with a title. */
/* Now register the various callback functions */
  glutDisplayFunc(DrawGLScene);        /* Function to do all our OpenGL drawing. */
  glutKeyboardFunc(NormalKey);         /*Normal key is pressed */
  glutSpecialFunc( SpecialKeyFunc );
  InitGL(Xsize,Ysize);
  /* Now drop into the event loop from which we never return */
  glutMainLoop();                      /* Start Event Processing Engine. */
  return 1;
}

