#include <cstdlib>
#include <cmath>

#ifndef GL_INCLUDED
	#include <GL/glew.h>
	#include <GL/glut.h>
	#define GL_INCLUDED
#endif

inline int roundFloat (const float a)
{
	return int(a + 0.5);
}

inline void lineDDA(int x0, int y0, int xEnd, int yEnd)
{
	int dx = xEnd - x0, dy = yEnd - y0, steps, k;
	float xIncrement, yIncrement, x = x0, y = y0;

	if (fabs(dx) > fabs(dy))
		steps = fabs(dx);
	else
		steps = fabs(dy);

	xIncrement = float(dx) / float(steps);
	yIncrement = float(dy) / float(steps);
	
	glBegin(GL_POINTS);
	{
		glVertex2i(roundFloat(x), roundFloat(y));
		for (k = 0; k < steps; k++)
		{
			x += xIncrement;
			y += yIncrement;
			glVertex2i(roundFloat(x), roundFloat(y));
		}
	}
	glEnd();
}

