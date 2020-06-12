#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include "Triangle.h"

using namespace std;

void framebuffer_size_callback(GLFWwindow * win, int width, int height)
{
	glViewport(0, 0, width, height);
}

int key = GLFW_KEY_UNKNOWN;
// process all input, query GLFW whether relevant keys are pressed/release this frame and react accordingly
void processInput(GLFWwindow *win)
{
	if (glfwGetKey(win, GLFW_KEY_ESCAPE))
	{
		glfwSetWindowShouldClose(win, true);
	}
	
	if (glfwGetKey(win, GLFW_KEY_1) == GLFW_PRESS)
	{
		key = GLFW_KEY_1;		
	}

	if (key == GLFW_KEY_1)
	{
		DrawTriangle();
	}

	// 双缓冲， 交换缓冲区
	glfwSwapBuffers(win);
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

	// Trigger when Window Size changed
	glfwSetFramebufferSizeCallback(win, framebuffer_size_callback);

	GenerateTriangle();
	while (!glfwWindowShouldClose(win))
	{
		// Process Input Commands
		processInput(win);

		// Process Rendering Commands
		// X: This a State-using Function		√: This a State-Setting/Changing function
		glClearColor(.2, .3, .3, 1);
		// X: This a State-Changing Function		√: This a State-using function, it uses the current state to retrieve/find the clearing color from.
		glClear(GL_COLOR_BUFFER_BIT);

		// 触发按键事件					
		glfwPollEvents();		
	}

	glfwTerminate();

	return 0;
}

