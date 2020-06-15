#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include "Triangle.h"

using namespace std;

void framebuffer_size_callback(GLFWwindow * win, int width, int height)
{
	glViewport(0, 0, width, height);
}

int trigeredKey = GLFW_KEY_UNKNOWN;
// process all input, query GLFW whether relevant keys are pressed/release this frame and react accordingly
void processInput(GLFWwindow *win)
{
	if (glfwGetKey(win, GLFW_KEY_ESCAPE))
	{
		glfwSetWindowShouldClose(win, true);
	}

	if (trigeredKey == GLFW_KEY_1)
	{
		GenerateTriangle();
		DrawTriangle();
	}
	if (trigeredKey == GLFW_KEY_2)
	{
		GenerateRectangle();
		DrawRectangle();
	}

	// Ë«»º³å£¬ ½»»»»º³åÇø
	glfwSwapBuffers(win);
}

void key_callback(GLFWwindow* win, int key, int scancode, int action, int mods)
{
	if (action != GLFW_RELEASE)
	{
		return;
	}

	trigeredKey = key;
	//if (key == GLFW_KEY_1)
	//{
	//	DrawTriangle();
	//}
	//if (key == GLFW_KEY_8)
	//{
	//	DrawTriangle();
	//}
		
	// Ë«»º³å£¬ ½»»»»º³åÇø
	//glfwSwapBuffers(win);
}

int main()
{
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	GLFWwindow* win = glfwCreateWindow(800, 600, "LearnOpenGL", NULL, NULL);
	if (win == NULL)
	{
		std::cout << "Create Window Error" << std::endl;
		return -1;
	}

	glfwMakeContextCurrent(win);

	// Load All OpenGL Function pointers
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		std::cout << "Init GLAD Error" << std::endl;
		return -1;
	}

	glViewport(0, 0, 400, 300);
	glfwSetKeyCallback(win, key_callback);
	// Trigger when Window Size changed
	glfwSetFramebufferSizeCallback(win, framebuffer_size_callback);

	//glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	//GenerateTriangle();
	//GenerateRectangle();
	while (!glfwWindowShouldClose(win))
	{
		// Process Input Commands
		processInput(win);

		// Process Rendering Commands
		// X: This a State-using Function		¡Ì: This a State-Setting/Changing function
		glClearColor(.2, .3, .3, 1);
		// X: This a State-Changing Function		¡Ì: This a State-using function, it uses the current state to retrieve/find the clearing color from.
		glClear(GL_COLOR_BUFFER_BIT);

		// ´¥·¢°´¼üÊÂ¼þ					
		glfwPollEvents();		
	}

	glfwTerminate();

	return 0;
}

