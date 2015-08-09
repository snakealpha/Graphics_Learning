#include "lineDraw.h"

#ifndef GL_INCLUDED
	#include <GL/glew.h>
	#include <GL/glut.h>
	#define GL_INCLUDED
#endif

void init(void)
{
	glClearColor(1.0, 1.0, 1.0, 0.0);
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0.0, 200.0, 0.0, 150.0);
}

void lineSegment(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0, 0.0, 0.0);

	/*
	int point1[] = { 50, 100 };
	int point2[] = { 75, 150 };
	int point3[] = { 100, 200 };

	glColor3f(1.0, 0.0, 0.0);
	glBegin(GL_LINES);
	{
		glVertex2i(180, 15);
		glVertex2i(10, 145);
	}
	glEnd();

	glBegin(GL_POINTS);
	{
		glVertex2iv(point1);
		glVertex2iv(point2);
		glVertex2iv(point3);
	}
	glEnd();
	*/

	lineDDA(180, 15, 10, 145);

	glFlush();
}

void main(int argc, char** argv)
{
	glewInit();

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition(50, 100);
	glutInitWindowSize(400, 300);
	glutCreateWindow("A example OpenGL Program");

	init();
	glutDisplayFunc(lineSegment);
	glutMainLoop();
}
