#pragma once
#include "include_GL.h"
#include "include_default.h"
//#include "include_containers.h"
#include "include_IO.h"
//#include "include_math.h"
#include "include_GUI.h"

#include "Window\GameWindow.h"
#include "Renderer\Renderer.h"

//http://www.lighthouse3d.com/tutorials/glut-tutorial/initialization/
//https://learnopengl.com/
//http://ogldev.atspace.co.uk/
//https://gamedev.stackexchange.com/questions/25733/object-oriented-opengl

//GlutDrawFunction callback issue:
//!!! explaination https://stackoverflow.com/a/5009648
//http://www.cplusplus.com/forum/general/19552/#msg101369
//https://www.opengl.org/discussion_boards/showthread.php/161803-Using-a-class-method-as-a-callback-function?p=1145123&viewfull=1#post1145123
//https://stackoverflow.com/questions/2670501/how-to-pass-non-static-member-function-into-glutdisplayfunc
//https://stackoverflow.com/questions/1000663/using-a-c-class-member-function-as-a-c-callback-function
//https://stackoverflow.com/questions/19808054/convert-c-function-pointer-to-c-function-pointer/19809787
//https://stackoverflow.com/questions/19339374/most-elegant-way-to-wrap-freeglut-callbacks-inside-a-class


void error_callback(int error, const char* description)
{
	fprintf(stderr, "Error: %s\n", description);
}

#if WINDOW_LIBRARY == 3
static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
		glfwSetWindowShouldClose(window, GLFW_TRUE);
}
#endif

int main(int argc, char* argv[])
{
	printf("Running program: %s\n", argv[0]);

	//GameWindow* mainWindow = new GameWindow(&argc, argv);
	//mainWindow->registerRenderFunction(Renderer::renderFunctionA); 


#if WINDOW_LIBRARY == 1
	printf("WINDOW_LIBRARY = SDL2\n");




#elif WINDOW_LIBRARY == 2
	printf("WINDOW_LIBRARY = freeglut\n");




#elif WINDOW_LIBRARY == 3
	printf("WINDOW_LIBRARY = glfw\n");
	if (!glfwInit())
	{
		// Initialization failed
	}
	glfwSetErrorCallback(error_callback);

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 5);
	GLFWwindow* window = glfwCreateWindow(640, 480, "My Title", NULL, NULL);
	if (!window)
	{
		// Window or OpenGL context creation failed
	}
	glfwSetKeyCallback(window, key_callback);
	glfwMakeContextCurrent(window);
#endif


#if EXTENSION_LIBRARY == 1
	printf("EXTENSION_LIBRARY = glew\n");
	glewInit(); //init glew when GL context stands
#elif EXTENSION_LIBRARY == 2
	printf("EXTENSION_LIBRARY = glad\n");
	gladLoadGL();
#endif



#if false
	float test = 0.0f;
	float test2 = 1.0f;
	struct local
	{
		static void testfunct(float f)
		{
			fprintf(stdout, "test is %f\n", f);
		}
	};
	local::testfunct(test);
	local::testfunct(test2);
#endif

#if WINDOW_LIBRARY == 1



#elif WINDOW_LIBRARY == 2



#elif WINDOW_LIBRARY == 3
	while (!glfwWindowShouldClose(window))
	{
		float ratio;
		int width, height;

		glm::mat4 m, p, mvp;
		glfwGetFramebufferSize(window, &width, &height);
		ratio = width / (float)height;
		glViewport(0, 0, width, height);
		glClear(GL_COLOR_BUFFER_BIT);
		/*
		m = glm::mat4(1.0);
		glm::rotate(m, m, (float)glfwGetTime());
		mat4x4_ortho(p, -ratio, ratio, -1.f, 1.f, 1.f, -1.f);
		mat4x4_mul(mvp, p, m);
		glUseProgram(program);
		glUniformMatrix4fv(mvp_location, 1, GL_FALSE, (const GLfloat*)mvp);
		glDrawArrays(GL_TRIANGLES, 0, 3);
		*/
		glfwSwapBuffers(window);
		glfwPollEvents();
	}



	glfwDestroyWindow(window);

	glfwTerminate();
#endif

	return 0;
}