#pragma once
#include "../include_IO.h"
#include "../include_GL.h"
#include "../Renderer/Renderer.h"

//https://stackoverflow.com/questions/10465462/multiple-windows-opengl-glut

class GameWindow
{
public:
	GameWindow(int* argc, char** argv);
	GameWindow(int * argc, char ** argv, std::string name, int width, int height);

	~GameWindow();

	void registerRenderFunction(void(*callback)(void));

	static void startWindowLoop();

	static void callback_thunk();

protected:
	int Width = 1280;
	int Height = 720;

	void (*renderFunction)();
	
	GLint WindowID = -1;

	void init();

	void initGlut(int* argc, char** argv, std::string name, int width, int height);

};

