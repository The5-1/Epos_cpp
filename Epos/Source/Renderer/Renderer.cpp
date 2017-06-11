#include "Renderer.h"
#include "../include_GL.h"


Renderer::Renderer()
{
}


Renderer::~Renderer()
{
}

void Renderer::renderFunctionA()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glBegin(GL_TRIANGLES);
	glVertex3f(-0.5, -0.5, 0.0);
	glVertex3f(0.5, 0.0, 0.0);
	glVertex3f(0.0, 0.5, 0.0);
	glEnd();

	glutSwapBuffers();
}
