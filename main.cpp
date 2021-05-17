//Q 13. 3)	Write OpenGL program to draw Sun Rise and Sunset

#include<GL/glut.h>
#include<iostream>
using namespace std;
float x = 70;
float y = 70;
int flag = 1;
float colR = 1;
float colG = 0.4;
float colB = 0.1;
float bR = 0;
float bG = 0;
float bB = 0.5;

void init(void) {
	//glClearColor(bR , bG, bB ,1 );
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0, 1000, 0, 500);
}
void reshape(int w, int h) {
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, 1000, 0, 500);
	glMatrixMode(GL_MODELVIEW);
}
void scene() {
	glClearColor(bR, bG, bB, 1); // To change background
	glClear(GL_COLOR_BUFFER_BIT);
	glLoadIdentity();
	glPointSize(10.0);
	float angle;
	glBegin(GL_POLYGON); // For drawing circle by plotting every point of circle
	for (int i = 0; i < 360; i++)
	{
		angle = i * 3.142 / 180;
		glColor3f(colR, colG, colB);
		glVertex2f(x + 30 * cos(angle), y + 30 * sin(angle));
	}
	glEnd();
	glBegin(GL_TRIANGLES); // For drawing mountains
	glColor3f(0.5, 0.1, 0.1);
	glVertex2f(0, 0);
	glVertex2f(100, 250);
	glVertex2f(500, 0);
	glEnd();
	glBegin(GL_TRIANGLES);
	glColor3f(0.5, 0.1, 0.1);
	glVertex2f(400, 0);
	glVertex2f(750, 150);
	glVertex2f(950, 0);
	glEnd();
	glutSwapBuffers();
}
void onIdle() { // To change x and y to move Sun
	glutPostRedisplay();
	if (x < 450)
	{
		x += 0.05;
		y += 0.05;
		bG += 0.00002; // bG to change background colour
		bB += 0.000001;
		colG += 0.00003; // colG to change colour of Sun
		colB += 0.000002;
	}
	if (x > 449 && y > 50)
	{
		x += 0.05;
		y -= 0.05;
		bG += 0.00002;
		bB += 0.000001;
		colG += 0.00003;
		colB += 0.000002;
	}
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition(0, 0);
	glutInitWindowSize(1000, 500);
	glutCreateWindow("first gl program");
	glutDisplayFunc(scene);
	glutIdleFunc(onIdle);
	glutReshapeFunc(reshape);
	init();
	glutMainLoop();
}