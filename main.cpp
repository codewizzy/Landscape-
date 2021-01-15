#include<stdio.h>
#include<GL/glut.h>
#include <GL/gl.h>
#include <stdlib.h>
#define SPEED 30.0

float i=0.0,m=0.0,n=0.0,o=0.0,c=0.0,b=0.0;
float p=0.75,q=0.47,r=0.14;
float e=0.90,f=0.91,g=0.98;
int count=0;
char ch;

void declare(char *string)
{
     while(*string)
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, *string++);
}

void draw_pixel(GLint cx, GLint cy)
{

	glBegin(GL_POINTS);
		glVertex2i(cx,cy);
	glEnd();
}

void plotpixels(GLint h,GLint k, GLint x,GLint y)
{
	draw_pixel(x+h,y+k);
	draw_pixel(-x+h,y+k);
	draw_pixel(x+h,-y+k);
	draw_pixel(-x+h,-y+k);
	draw_pixel(y+h,x+k);
	draw_pixel(-y+h,x+k);
	draw_pixel(y+h,-x+k);
	draw_pixel(-y+h,-x+k);
}

void draw_circle(GLint h, GLint k, GLint r)
{
	GLint d=1-r, x=0, y=r;
	while(y>x)
	{
		plotpixels(h,k,x,y);
		if(d<0) d+=2*x+3;
		else
		{
			d+=2*(x-y)+5;
			--y;
		}
		++x;
	}
	plotpixels(h,k,x,y);
}


void draw_object()
{
int l;
//sky
glColor3f(0.0,0.5,0.9);
glBegin(GL_POLYGON);
glVertex2f(0,380);
glVertex2f(0,700);
glVertex2f(1100,700);
glVertex2f(1100,380);
glEnd();

//river

glColor3f(1.0,1.0,1.0);
glBegin(GL_POLYGON);
glVertex2f(0,0);
glVertex2f(1100,0);
glVertex2f(1100,200);
glVertex2f(0,380);
glEnd();

//sun


	for(l=0;l<=35;l++)
{
		glColor3f(1.0,0.9,0.0);
		draw_circle(100,625,l);
}


//cloud1


	for(l=0;l<=20;l++)
	{
		glColor3f(1.0,1.0,1.0);
		draw_circle(560,625,l);

	}


	for(l=0;l<=35;l++)
	{
		glColor3f(1.0,1.0,1.0);
		draw_circle(600,625,l);
		draw_circle(625,625,l);
	}

	for(l=0;l<=20;l++)
	{
		glColor3f(1.0,1.0,1.0);
		draw_circle(665,625,l);
	}

//cloud2


	for(l=0;l<=20;l++)
	{
		glColor3f(1.0,1.0,1.0);
		draw_circle(370,615,l);
}

	for(l=0;l<=35;l++)
	{

		glColor3f(1.0,1.0,1.0);
		draw_circle(410,615,l);
		draw_circle(435,615,l);
		draw_circle(470,615,l);
	}

for(l=0;l<=20;l++)
	{
		glColor3f(1.0,1.0,1.0);
		draw_circle(500,615,l);
}

//cloud3


	for(l=0;l<=20;l++)
	{
		glColor3f(1.0,1.0,1.0);
		draw_circle(960,625,l);

	}


	for(l=0;l<=35;l++)
	{
		glColor3f(1.0,1.0,1.0);
		draw_circle(1000,625,l);
		draw_circle(1025,625,l);
	}

	for(l=0;l<=20;l++)
	{
		glColor3f(1.0,1.0,1.0);
		draw_circle(1065,625,l);
	}


//grass
glColor3f(0.141,0.89,0.0627);
glBegin(GL_POLYGON);
glVertex2f(0,160);
glVertex2f(0,380);
glVertex2f(1100,380);
glVertex2f(1100,160);
glEnd();



//Ground
	glColor3f(0.0,0.3,0.0);
	glBegin(GL_POLYGON);
		glVertex2f(-600,0);
		glVertex2f(-600,185);
		glVertex2f(1100,185);
		glVertex2f(1100,0);
	glEnd();

	//foilage.

glColor3f(0.9,0.2,0.0);
glBegin(GL_POLYGON);
glVertex2f(400,375);
glVertex2f(400,445);
glVertex2f(415,445);
glVertex2f(415,375);
glEnd();

glColor3f(0.9,0.2,0.0);
glBegin(GL_POLYGON);
glVertex2f(410,445);
glVertex2f(420,445);
glVertex2f(430,485);
glVertex2f(420,485);
glEnd();

glColor3f(0.9,0.2,0.0);
glBegin(GL_POLYGON);
glVertex2f(400,445);
glVertex2f(410,445);
glVertex2f(400,495);
glVertex2f(390,495);
glEnd();

//fence

glColor3f(0.9,0.2,0.0);
glBegin(GL_POLYGON);
glVertex2f(500,170);
glVertex2f(500,380);
glVertex2f(510,380);
glVertex2f(510,170);
glEnd();

glColor3f(0.9,0.2,0.0);
glBegin(GL_POLYGON);
glVertex2f(1075,170);
glVertex2f(1075,380);
glVertex2f(1085,380);
glVertex2f(1085,170);
glEnd();

glColor3f(0.9,0.2,0.0);
glBegin(GL_POLYGON);
glVertex2f(500,170);
glVertex2f(1075,170);
glVertex2f(1075,180);
glVertex2f(500,180);
glEnd();



//tree
glColor3f(0.9,0.2,0.0);
glBegin(GL_POLYGON);
glVertex2f(280,150);
glVertex2f(280,255);
glVertex2f(295,255);
glVertex2f(295,150);
glEnd();


	for(l=0;l<=30;l++)
	{
		glColor3f(0.0,0.5,0.0);
		draw_circle(270,250,l);
		draw_circle(310,250,l);
	}

	for(l=0;l<=25;l++)
	{
		glColor3f(0.0,0.5,0.0);
		draw_circle(280,290,l);
		draw_circle(300,290,l);
	}

	for(l=0;l<=20;l++)
	{
		glColor3f(0.0,0.5,0.0);
		draw_circle(290,315,l);
	}


//tree 1
glColor3f(0.9,0.2,0.0);
glBegin(GL_POLYGON);
glVertex2f(100,155);
glVertex2f(100,305);
glVertex2f(140,305);
glVertex2f(140,155);
glEnd();


	for(l=0;l<=40;l++)
	{
		glColor3f(0.0,0.5,0.0);
		draw_circle(40,280,l);
		draw_circle(90,280,l);
		draw_circle(150,280,l);
		draw_circle(210,280,l);
		draw_circle(65,340,l);
		draw_circle(115,340,l);
		draw_circle(175,340,l);

	}

	for(l=0;l<=55;l++)
	{
		glColor3f(0.0,0.5,0.0);
		draw_circle(115,360,l);


	}

 	//chim

	glColor3f(0.9,0.28,0.134);
	glBegin(GL_POLYGON);

		glVertex2f(540,380);
		glVertex2f(540,480);
		glVertex2f(960,480);
		glVertex2f(960,380);

	glEnd();

	//chimney
	glColor3f(0.9,0.28,0.134);
	glBegin(GL_POLYGON);

		glVertex2f(880,480);
		glVertex2f(880,520);
		glVertex2f(910,520);
		glVertex2f(910,480);

	glEnd();

	//smoke

	for(l=0;l<=20;l++)
	{
		glColor3f(0.564,0.564,0.564);
		draw_circle(880,540,l);

	}


	for(l=0;l<=35;l++)
	{
		glColor3f(0.564,0.564,0.564);
		draw_circle(920,540,l);
		draw_circle(945,540,l);
	}

	for(l=0;l<=20;l++)
	{
		glColor3f(0.564,0.564,0.564);
		draw_circle(885,540,l);
	}

	//home

	glColor3f(0.965,0.3,0.67);
	glBegin(GL_POLYGON);

		glVertex2f(550,225);
		glVertex2f(550,400);
		glVertex2f(950,400);
		glVertex2f(950,225);
		glVertex2f(850,225);
		glVertex2f(850,300);
		glVertex2f(650,300);
		glVertex2f(650,225);

	glEnd();

	//window border

	glColor3f(0.35,0.0,0.0);
	glBegin(GL_POLYGON);

		glVertex2f(595,305);
		glVertex2f(595,365);
		glVertex2f(675,365);
		glVertex2f(675,305);

	glEnd();

	glBegin(GL_POLYGON);

		glVertex2f(825,305);
		glVertex2f(825,365);
		glVertex2f(905,365);
		glVertex2f(905,305);

	glEnd();

	glBegin(GL_POLYGON);

		glVertex2f(845,305);
		glVertex2f(845,365);
		glVertex2f(850,365);
		glVertex2f(850,305);

	glEnd();

    //tree
glColor3f(0.9,0.2,0.0);
glBegin(GL_POLYGON);
glVertex2f(1000,185);
glVertex2f(1000,255);
glVertex2f(1020,255);
glVertex2f(1020,185);
glEnd();


	for(l=0;l<=30;l++)
	{
		glColor3f(0.0,0.5,0.0);
		draw_circle(990,250,l);
		draw_circle(1030,250,l);
	}

	for(l=0;l<=25;l++)
	{
		glColor3f(0.0,0.5,0.0);
		draw_circle(1000,290,l);
		draw_circle(1025,290,l);
	}

	for(l=0;l<=20;l++)
	{
		glColor3f(0.0,0.5,0.0);
		draw_circle(1015,315,l);
	}

//fence
glColor3f(1,0.0,0.0);
glBegin(GL_POLYGON);
glVertex2f(500,160);
glVertex2f(510,380);
glVertex2f(510,380);
glVertex2f(500,160);
glEnd();

	//door
	glColor3f(e,f,g);
	glBegin(GL_POLYGON);

		glVertex2f(800,230);
		glVertex2f(800,320);
		glVertex2f(700,320);
		glVertex2f(700,230);

	glEnd();

	glColor3f(0.35,0.0,0.0);
	glBegin(GL_POLYGON);

		glVertex2f(760,240);
		glVertex2f(760,300);
		glVertex2f(700,320);
		glVertex2f(700,230);

	glEnd();


 //river

glColor3f(0.0,0.0,1.0);
glBegin(GL_POLYGON);
glVertex2f(0,0);
glVertex2f(1100,0);

glVertex2f(1100,150);

glVertex2f(300,165);

glVertex2f(0,150);
glEnd();
	//boat

	glColor3f(0.5,0.0,0.0);
	glBegin(GL_POLYGON);

		glVertex2f(400,100);
		glVertex2f(500,100);
		glVertex2f(530,140);
		glVertex2f(370,140);

	glEnd();


	//window
	glColor3f(e,f,g);
	glBegin(GL_POLYGON);

		glVertex2f(600,300);
		glVertex2f(600,360);
		glVertex2f(670,360);
		glVertex2f(670,300);

	glEnd();

	glBegin(GL_POLYGON);

		glVertex2f(830,300);
		glVertex2f(830,360);
		glVertex2f(900,360);
		glVertex2f(900,300);

	glEnd();

	glColor3f(0.35,0.0,0.0);
	glBegin(GL_POLYGON);

		glVertex2f(620,300);
		glVertex2f(620,360);
		glVertex2f(625,360);
		glVertex2f(625,300);

	glEnd();

	glBegin(GL_POLYGON);

		glVertex2f(650,300);
		glVertex2f(650,360);
		glVertex2f(655,360);
		glVertex2f(655,300);

	glEnd();



	glColor3f(0.35,0.0,0.0);
	glBegin(GL_POLYGON);

		glVertex2f(850,295);
		glVertex2f(850,365);
		glVertex2f(855,365);
		glVertex2f(855,295);

	glEnd();

	glBegin(GL_POLYGON);

		glVertex2f(880,295);
		glVertex2f(880,365);
		glVertex2f(885,365);
		glVertex2f(885,295);

	glEnd();

glFlush();
}


void myinit()
{
glClearColor(1.0,1.0,1.0,1.0);
glColor3f(0.0,0.0,1.0);
glPointSize(2.0);
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
gluOrtho2D(0.0,1100.0,0.0,700.0);
}



void display()
{

glClear(GL_COLOR_BUFFER_BIT);
draw_object();
glFlush();
}


int main(int argc,char** argv)
{
    int c_menu;
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowSize(1100.0,700.0);
	glutInitWindowPosition(0,0);
	glutCreateWindow("My Village");
	glutDisplayFunc(display);



	myinit();


	glutAttachMenu(GLUT_RIGHT_BUTTON);
	glutMainLoop();
	return 0;
}
