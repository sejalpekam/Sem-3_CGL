
//*******************************Assignment 14**********************************************
//c)	Write C++ program to draw man walking in the rain with an umbrella. 
//Apply the concept of polymorphism.



#include <Windows.h>
#include <GL\glew.h>
#include <GL\freeglut.h>
#include <iostream>

using namespace std;
float x = 0;
float y = 0;

void init()
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, 600, 0, 600);
	glMatrixMode(GL_MODELVIEW);

}

void draw() {

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	glColor3f(1, 1, 1);
	glBegin(GL_LINES);
	glVertex2i(0, 100);  //ground
	glVertex2i(600, 100);
	glVertex2i(x + 10, 100);   //leftleg
	glVertex2i(x + 30, 150);
	glVertex2d(x + 30, 150);   //right leg
	glVertex2d(x + 50, 100);
	glVertex2d(x + 30, 150);   //body
	glVertex2d(x + 30, 250);
	glVertex2d(x + 30, 200); //left hand
	glVertex2d(x + 10, 175);
	glVertex2d(x + 30, 200); //right hand
	glVertex2d(x + 50, 225);
	glVertex2d(x + 50, 225); //umbrella stick
	glVertex2d(x + 50, 300);
	glEnd();

	glBegin(GL_POLYGON);//umbrella
	for (int i = 0; i < 180; i++)
	{
		float angle = i * 3.142 / 180;
		glColor3f(1, 1, 1);
		glVertex2f((x + 50) + 50 * cos(angle), (y + 300) + 50 * sin(angle));
	}
	glEnd();
	float angle2;
	glBegin(GL_POLYGON);//head
	for (int i = 0; i < 360; i++)
	{
		angle2 = i * 3.142 / 180;
		glColor3f(1, 1, 1);
		glVertex2f((x + 30) + 18 * cos(angle2), (y + 250) + 18 * sin(angle2));
	}
	glEnd();

	glBegin(GL_LINES);
	for (int t = 0; t < 10; t++) {
		int x1 = rand() % 1000;
		int y1 = rand() % 499;
		glColor3f(1, 1, 1);
		glVertex2d(x1, y1);
		glVertex2d(x1, y1 + 15);
	}
	glEnd();
	glFlush();
	glutSwapBuffers();
}

void onidle() {
	glutPostRedisplay();
	if (x < 600) {
		x += 0.05;
	}
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(600, 600);
	glutCreateWindow("man in rain");
	glutDisplayFunc(draw);
	glutIdleFunc(onidle);
	init();
	glutMainLoop();
	return 0;
}