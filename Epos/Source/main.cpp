//#include "include_containers.h"
#include "include_IO.h"
//#include "include_math.h"
#include "include_GL.h"

#include "RessourcePathHelper.h"


//int main(int argc, const char * argv[]) //this const will NOT work with SDL!!
int main(int argc, char* argv[])
{
	printf("Running program: %s\n", argv[0]);



	int posX = 100;
	int posY = 200;
	int sizeX = 300;
	int sizeY = 400;
	SDL_Window* window;
	SDL_Renderer* renderer;

	// Initialize SDL
	// ==========================================================
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
	{
		// Something failed, print error and exit.
		std::cout << " Failed to initialize SDL : " << SDL_GetError() << std::endl;
		return -1;
	}
	else printf("SDL_INIT_EVERYTHING successfull!\n");

	std::cout << "Resource path is: " << getResourcePath() << std::endl;

	// Create and init the window
	// ==========================================================
	window = SDL_CreateWindow("Server", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, sizeX, sizeY, SDL_WINDOW_OPENGL);

	SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE); //use OpenGL core profile
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 4); //Version 4.5
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 5); //Version 4.5
	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1); //enable double buffering, to draw to an offscreen target and then swap buffers
	SDL_GLContext SDL_GL_CreateContext(SDL_Window* window); //create the GL context --> next its GLEWs turn
	glewExperimental = GL_TRUE; //lets glew search for experimental functions
	glewInit(); //GLEW __must__ init after the OpenGL context was created!!


	if (window == nullptr)
	{
		std::cout << "Failed to create window : " << SDL_GetError();
		return -1;
	}

	// Create and init the renderer
	// ==========================================================
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

	if (renderer == nullptr)
	{
		std::cout << "Failed to create renderer : " << SDL_GetError();
		return -1;
	}

	// Render something
	// ==========================================================

	// Set size of renderer to the same as window
	SDL_RenderSetLogicalSize(renderer, sizeX, sizeY);

	// Set color of renderer to red
	SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);

	// Clear the window and make it all red
	SDL_RenderClear(renderer);

	// Render the changes above ( which up until now had just happened behind the scenes )
	SDL_RenderPresent(renderer);

	// Pause program so that the window doesn't disappear at once.
	// This willpause for 4000 milliseconds which is the same as 4 seconds
	SDL_Delay(1000);
	
	
	return 0;
}