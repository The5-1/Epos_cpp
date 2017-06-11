#pragma once
#include "include_GL.h"
#include "include_default.h"
//#include "include_containers.h"
#include "include_IO.h"
//#include "include_math.h"
//#include "include_GUI.h"

#include "Window\GameWindow.h"
#include "Renderer\Renderer.h"

//http://www.lighthouse3d.com/tutorials/glut-tutorial/initialization/
//https://learnopengl.com/
//http://ogldev.atspace.co.uk/

int main(int argc, char* argv[])
{
	printf("Running program: %s\n", argv[0]);

	GameWindow* mainWindow = new GameWindow(&argc, argv);

	//callback issue:
	//!!! explaination https://stackoverflow.com/a/5009648
	//http://www.cplusplus.com/forum/general/19552/#msg101369
	//https://www.opengl.org/discussion_boards/showthread.php/161803-Using-a-class-method-as-a-callback-function?p=1145123&viewfull=1#post1145123
	//https://stackoverflow.com/questions/2670501/how-to-pass-non-static-member-function-into-glutdisplayfunc
	//https://stackoverflow.com/questions/1000663/using-a-c-class-member-function-as-a-c-callback-function
	//https://stackoverflow.com/questions/19808054/convert-c-function-pointer-to-c-function-pointer/19809787
	//https://stackoverflow.com/questions/19339374/most-elegant-way-to-wrap-freeglut-callbacks-inside-a-class

	mainWindow->registerRenderFunction(Renderer::renderFunctionA); 
	return 0;
}