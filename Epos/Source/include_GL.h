#pragma once //better than include guards

//include guards example:
//#ifndef INCLUDE_GL
//#define INCLUDE_GL
//... inclusions here
//#endif /*INCLUDE_GL*/


/************************************************************************
The "OpenGL32.lib" does __NOT__ go into our D:/Dev/... folder!
It needs the real System OpenGL32.lib so you have to add only
	"OpenGL32.lib" 
without GL/OpenGL32.lib to the Linker Input.
This way it searches for it, but in the system path.
**************************************************************************
If you use one x64 library you have to build in x64 mode and also use
- x64 .dll files
- x64 .lib files
... this does not seem to apply to all libraries... but some.
If you get linker errors that something can not be found it might be this!
**************************************************************************/


//https://stackoverflow.com/questions/19719055/what-are-the-differences-between-glu-glew-glut-qt-sdl-opengl-and-webgl

//*****************************
//OpenGL Platform Compatibility
//-----------------------------
//GL Extension Wrangler
//gets those OpenGL functions that are available on the current platform
//http://glew.sourceforge.net/basic.html
#define GLEW_STATIC  //we use the glew32s.lib (static library) to include GLEW right into our exe, we need to tell this to GLEW
#include <GL/glew.h> 
//#include <GL/wglew.h> //platform specific extensions ("WGL extensions")
//#include <GL/glxew.h> //platform specific extensions ("GLX extensions")
//#include <GL/eglew.h> //no info found on this one...

//***************************
//OpenGL Window Libraries
#define WINDOW_LIBRARY 2
//---------------------------
#if WINDOW_LIBRARY == 1
//Simple Directmedia Layer:
//Platform and Graphics API independent (works on DirectX too)
//As soon as you use openGL directly SDL does not help much anymore...
//when creating a new window you can use SDL_WINDOW_OPENGL to make the window use OpenGL
//medium level library for creating windows, handling input, loading textures, etc., abstracts some from OpenGL
#include <SDL2/SDL.h> 

#elif WINDOW_LIBRARY == 2
//FreeGLUT - GL Utility Toolkit:
//low level library for creating windows, has extensions that allow the same control as GLFW3
#include <GL/glut.h>  

#elif WINDOW_LIBRARY == 3
//GL Window Framework:
//low level library that only creates windows, direct control over OpenGL
#include <GL/glfw3.h> 

#endif
//***************************


