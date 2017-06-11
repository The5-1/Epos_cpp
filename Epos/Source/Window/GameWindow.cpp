#include "GameWindow.h"

GameWindow::GameWindow(int * argc, char ** argv)
{
	initGlut(argc, argv, argv[0], this->Width, this->Height);
}

GameWindow::GameWindow(int * argc, char ** argv, std::string name, int width, int height)
{
	initGlut(argc, argv, name.c_str(), width, height);
}


void GameWindow::init()
{

}

void GameWindow::initGlut(int* argc, char** argv, std::string name, int width, int height)
{
	glutInit(argc, argv);
	glutInitWindowSize(width, height);
	glutInitWindowPosition(-1, -1);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);

	glutCreateWindow(name.c_str());
	this->WindowID = glutGetWindow();
}

GameWindow::~GameWindow()
{
}



void GameWindow::registerRenderFunction(void(*callback)(void))
{
	this->renderFunction = callback;

	int previousWindow = glutGetWindow(); //memorize the window context currently active
	glutSetWindow(this->WindowID); //set the glut context to this window
	glutDisplayFunc(callback); //assign the display function
	glutMainLoop();
	glutSetWindow(previousWindow);
}
