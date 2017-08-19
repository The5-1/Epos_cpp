#pragma once
#include "include_GL.h"
#include "include_default.h"
//#include "include_containers.h"
#include "include_IO.h"
//#include "include_math.h"
#include "include_GUI.h"


#include <entityplus\entity.h>

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


void test_main(); //forward declaration

int main(int argc, char* argv[])
{
	printf("Running program: %s\n", argv[0]);

	//GameWindow* mainWindow = new GameWindow(&argc, argv);
	//mainWindow->registerRenderFunction(Renderer::renderFunctionA); 



	test_main();


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


void test_LocalFunctions()
{
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
}

void test_lambdas()
{

}

void test_RAII()
{
	/*
	Scope bound Ressources
	----------------------
	RAII = "Resource Acquisition is Initialisation"
	= RABITS = "Resources are bound irreversibly to scope"
	http://www.tomdalling.com/blog/software-design/resource-acquisition-is-initialisation-raii-explained/
	When you heap allocate something and a exception is thrown before the destructur, the distructor wont ever be called
	Same for opening a file and never closing it.

	Instead do:
	- allocate on the stack
	- in the constructor, allocate everything, not later (if possible)
	- the destructor releases all resources
	*/

	class OpenFile {
	public:
		OpenFile(const char* filename) {
			//throws an exception on failure
			_file.open(filename);
		}

		~OpenFile() {
			//free resources
			_file.close();
		}

		std::string readLine() {
			return "hello";
		}

	private:
		std::fstream _file;
	};

	struct local
	{
		static std::string firstLineOf_save(const char* filename) {
			OpenFile f("boo.txt"); //stack allocated
			return f.readLine();
			//File closed here. `f` goes out of scope and destructor is run.
		}

		static std::string firstLineOf_unsave(const char* filename) {
			OpenFile* f = new OpenFile("boo.txt"); //heap allocated
			return f->readLine();
			//DANGER! Destructor is never run, because `f` is never deleted
		}
	};
}

void test_Pointers()
{
	class Dummy
	{
		int a;
	};


}


void test_MemoryLeak()
{
	std::cout << __FUNCTION__ << std::endl;
	class Dummy
	{
	public:
		long x;
		Dummy() : x(x) {} 
		//Dummy() : x(100) {}
		Dummy(double in) : x(in) {} //"member initializer list"
	};

	class DummyA : Dummy
	{
	public:
		int i;
		DummyA(int in = 0 ) : i(in), Dummy() {}

	};

	fprintf(stdout, "See the RAM filling! (In Task Manager)\n");
	for (int i = 0; i < 10000000; i++)
	{
		Dummy* d = new Dummy(i); //initialize on the heap
		d = nullptr; //bend the pointer elsewhere, we cant go back
		delete d; //wont work since we already messed up the pointer
	}
	fprintf(stdout, "Event though the scope of the loop ended, the stuff on the heap is still there.\n");

	fprintf(stdout, "And now without messing up the pointer...\n");
	for (int i = 0; i < 10000000; i++)
	{
		DummyA* da = new DummyA(); //uses DummyA(int in = 0 )
		delete da; //call destructor
		da = nullptr; //set the pointer to null just so everyone knows its not there anymore
	}
	fprintf(stdout, "...RAM did not change this time!\n");

	fprintf(stdout, "Using the Stack rather than the heap...\n");
	for (int i = 0; i < 10000000; i++)
	{
		Dummy s(i); //initialize a class on the stack
	}
	fprintf(stdout, "...frees itself when it goes out of scope!\n");


}

void test_SmartPointers()
{
	/*
	https://stackoverflow.com/questions/569775/smart-pointers-boost-explained
	https://stackoverflow.com/questions/677653/does-delete-call-the-destructor
	Normally, 

	Smartpointers have a "onwership" concept:
	- no ownership at all
	- transfer of ownership
	- share of ownership

	*/
}


void test_main()
{
	test_MemoryLeak();

}

