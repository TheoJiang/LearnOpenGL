

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
// Include glfw3.h after our OpenGL definitions
#include <GLFW/glfw3.h>
#include <stdio.h>

#include "imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"

// --------------------
#include "Chapters/0.ListAll.h"

using namespace std;

// [Win32] Our example includes a copy of glfw3.lib pre-compiled with VS2010 to maximize ease of testing and compatibility with old VS compilers.
// To link with VS2010-era libraries, VS2015+ requires linking with legacy_stdio_definitions.lib, which we do using this pragma.
// Your own project should not be affected, as you are likely to link with a newer binary of GLFW that is adequate for your version of Visual Studio.
#if defined(_MSC_VER) && (_MSC_VER >= 1900) && !defined(IMGUI_DISABLE_WIN32_FUNCTIONS)
#pragma comment(lib, "legacy_stdio_definitions")
#endif

static void glfw_error_callback(int error, const char* description)
{
	fprintf(stderr, "Glfw Error %d: %s\n", error, description);
}


void framebuffer_size_callback(GLFWwindow* win, int width, int height)
{
	glViewport(0, 0, width, height);
}
int key_levl1 = -1;
// process all input, query GLFW whether relevant keys are pressed/release this frame and react accordingly
void processInput(GLFWwindow* win)
{
	if (glfwGetKey(win, GLFW_KEY_ESCAPE))
	{
		glfwSetWindowShouldClose(win, true);
	}

	//if (key_levl1 == GLFW_KEY_1)
	//{
	//	Triangle_ProcessInput();
	//}



}

void key_callback(GLFWwindow* win, int key, int scancode, int action, int mods)
{
	if (action != GLFW_RELEASE)
	{
		return;
	}
	if (key_levl1 == -1 && key != GLFW_KEY_BACKSPACE)
	{
		key_levl1 = key;
	}
	else if (key == GLFW_KEY_BACKSPACE)
	{
		key_levl1 = -1;
	}
	else
	{
		//Common::SetKey(key);
	}

}

ImVec4 clear_color = ImVec4(0.45f, 0.55f, 0.60f, 1.00f);

// Rendering IMGUI
void RenderIMGUI(GLFWwindow* window)
{
	// Rendering
	ImGui::Render();
	int display_w, display_h;
	glfwGetFramebufferSize(window, &display_w, &display_h);
	glViewport(0, 0, display_w, display_h);
	glClearColor(clear_color.x, clear_color.y, clear_color.z, clear_color.w);
	glClear(GL_COLOR_BUFFER_BIT);
	ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
}

void ImguiContext();
// Core Loop
int main()
{
	glfwSetErrorCallback(glfw_error_callback);
	if (!glfwInit())
		return 1;

	// GL 3.0 + GLSL 130
	const char* glsl_version = "#version 130";
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	GLFWwindow* window = glfwCreateWindow(800, 600, "LearnOpenGL", NULL, NULL);
	if (window == NULL)
	{
		std::cout << "Create Window Error" << std::endl;
		return -1;
	}

	glfwMakeContextCurrent(window);
	glfwSwapInterval(1); // Enable vsync


	// Initialize OpenGL loader
#if defined(IMGUI_IMPL_OPENGL_LOADER_GLAD)
	bool err = gladLoadGL() == 0;
	if (err)
	{
		fprintf(stderr, "Failed to initialize OpenGL loader!\n");
		return 1;
	}
	//// 初始化GLAD
	//// Load All OpenGL Function pointers
	//if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	//{
	//	std::cout << "Init GLAD Error" << std::endl;
	//	return -1;
	//}
#endif

	// Setup Dear ImGui context
	IMGUI_CHECKVERSION();
	ImGui::CreateContext();
	ImGuiIO& io = ImGui::GetIO(); (void)io;

	ImGui::StyleColorsDark();
	//ImGui::StyleColorsClassic();

	// Setup Platform/Renderer backends
	ImGui_ImplGlfw_InitForOpenGL(window, true);
	ImGui_ImplOpenGL3_Init(glsl_version);

	//glfwSetKeyCallback(window, key_callback);
	// Trigger when Window Size changed
	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

	while (!glfwWindowShouldClose(window))
	{
		processInput(window);

		// Process Rendering Commands
		glClearColor(.2, .3, .3, 1);
		glClear(GL_COLOR_BUFFER_BIT);

		// 触发按键事件					
		glfwPollEvents();

		// Start the Dear ImGui frame
		ImGui_ImplOpenGL3_NewFrame();
		ImGui_ImplGlfw_NewFrame();
		ImGui::NewFrame();

		ImguiContext();

		RenderIMGUI(window);
		// 双缓冲， 交换缓冲区
		glfwSwapBuffers(window);
	}

	// Cleanup
	ImGui_ImplOpenGL3_Shutdown();
	ImGui_ImplGlfw_Shutdown();
	ImGui::DestroyContext();

	glfwDestroyWindow(window);

	glfwTerminate();
	return 0;
}

void ImguiContext()
{
	bool show_another_window = true;
	if (show_another_window)

	{

		ImGui::Begin("Another Window", &show_another_window);   // Pass a pointer to our bool variable (the window will have a closing button that will clear the bool when clicked)
		ImGui::Text("Hello from another window!");
		if (ImGui::Button("Close Me"))
			show_another_window = false;

		if (ImGui::CollapsingHeader("Help"))
		{
			ImGui::Text("ABOUT THIS DEMO:");
			ImGui::BulletText("Sections below are demonstrating many aspects of the library.");
			ImGui::BulletText("The \"Examples\" menu above leads to more demo contents.");
			ImGui::BulletText("The \"Tools\" menu above gives access to: About Box, Style Editor,\n"
				"and Metrics/Debugger (general purpose Dear ImGui debugging tool).");
			ImGui::Separator();

			ImGui::Text("PROGRAMMER GUIDE:");
			ImGui::BulletText("See the ShowDemoWindow() code in imgui_demo.cpp. <- you are here!");
			ImGui::BulletText("See comments in imgui.cpp.");
			ImGui::BulletText("See example applications in the examples/ folder.");
			ImGui::BulletText("Read the FAQ at http://www.dearimgui.org/faq/");
			ImGui::BulletText("Set 'io.ConfigFlags |= NavEnableKeyboard' for keyboard controls.");
			ImGui::BulletText("Set 'io.ConfigFlags |= NavEnableGamepad' for gamepad controls.");
			ImGui::Separator();

			ImGui::Text("USER GUIDE:");
			ImGui::ShowUserGuide();
		}
		ImGui::End();

	}
}
