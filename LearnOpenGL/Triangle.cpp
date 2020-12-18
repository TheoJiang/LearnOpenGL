//#include "Triangle.h"
//#include <string>
//#include "Common.h"
//using namespace std;
//
//float vertices[] = {
//	-0.5, -0.5, 0.0,
//	0.5, -0.5, 0.0,
//	0.0, 0.5, 0.0
//};
//
//unsigned int vs;
//unsigned int fs;
//unsigned int sProgram;
//
//void CreateAndCompileShader(/*int &vs, int &fs*/)
//{
//	string vss =
//		"#version 330 core                                          \n"
//		"layout (location = 0) in vec3 aPos;                      \n"
//		"void main(){                                             \n"
//		"    gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);}    \n";
//
//	const char *vsc_str = vss.c_str();
//	vs = glCreateShader(GL_VERTEX_SHADER);
//	glShaderSource(vs, 1, &vsc_str, NULL);
//	glCompileShader(vs);
//
//	// check suc
//	int suc;
//	char infoLog[512];
//	// the iv of glGetShaderiv means a vector of ints
//	glGetShaderiv(vs, GL_COMPILE_STATUS, &suc);
//	if (!suc)
//	{
//		glGetShaderInfoLog(vs, 512, NULL, infoLog);
//		std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
//	}
//
//	string fss =
//		"#version 330 core\n"
//		"out vec4 FragColor;\n"
//		"void main()\n"
//		"{\n"
//		"		FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);\n"
//		"}\n";
//
//	const char *fsc_str = fss.c_str();
//	fs = glCreateShader(GL_FRAGMENT_SHADER);
//	glShaderSource(fs, 1, &fsc_str, NULL);
//	glCompileShader(fs);
//
//	// check suc
//	glGetShaderiv(fs, GL_COMPILE_STATUS, &suc);
//	if (!suc)
//	{
//		glGetShaderInfoLog(fs, 512, NULL, infoLog);
//		std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
//	}
//
//	// Link Shader
//	sProgram = glCreateProgram();
//
//	glAttachShader(sProgram, vs);
//	glAttachShader(sProgram, fs);
//	glLinkProgram(sProgram);
//
//	glGetProgramiv(sProgram, GL_LINK_STATUS, &suc);
//	if (!suc) {
//		glGetProgramInfoLog(sProgram, 512, NULL, infoLog);
//		std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
//	}
//
//	glUseProgram(sProgram);
//	glDeleteShader(vs);
//	glDeleteShader(fs);
//}
//
//unsigned int VBO;
//unsigned int VAO;
//void GenerateTriangle()
//{
//	//// use buffer id to generate a Buffer Object
//	//glGenBuffers(1, &VBO);
//	//// bind the buffer object VBO to GL_ARRARY_TARGET, it allows us to send lots data into memory
//	//glBindBuffer(GL_ARRAY_BUFFER, VBO);
//	//// cause the buffer object was bound, the buffer calls subsequence will configure this buffer object
//	//glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
//
//
//	//-----------------
//	// VAO
//	glGenVertexArrays(1, &VAO);
//	// Bind VAO
//	glBindVertexArray(VAO);
//	// Bind VBO
//	// Copy VA to Buffer
//	glGenBuffers(1, &VBO);
//	glBindBuffer(GL_ARRAY_BUFFER, VBO);
//	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
//	//-----------------
//
//
//	// vertext attribute pointer
//	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
//	glEnableVertexAttribArray(0);
//	CreateAndCompileShader();
//}
//
//void DrawTriangle()
//{
//	// Q: why one more time？
//	// A: 正常有多个VAO时要切换绑定, 此处只有一个, 所以不用每次都去绑定, 因为不需要切换绑定.
//	glBindVertexArray(VAO);
//
//	// Draw
//	//glDrawArrays(GL_POINTS, 0, 3);
//	//glDrawArrays(GL_LINE_LOOP, 0, 3);
//	glDrawArrays(GL_TRIANGLES, 0, 3);
//
//	// 不用每次都解绑
//	// glBindVertexArray(0); 
//}
//
//float verticesRectangle[] = {
//	0.5f, 0.5f, 0.0f,   // 右上角
//	0.5f, -0.5f, 0.0f,  // 右下角
//	-0.5f, -0.5f, 0.0f, // 左下角
//	-0.5f, 0.5f, 0.0f   // 左上角
//};
//
//unsigned int indices[] = { // 注意索引从0开始! 
//	0, 1, 3, // 第一个三角形
//	1, 2, 3  // 第二个三角形
//};
//
//unsigned int IBO;
//void GenerateRectangle()
//{
//	glGenBuffers(1, &IBO);
//	glGenBuffers(1, &VBO);
//	glGenVertexArrays(1, &VAO);
//
//	glBindVertexArray(VAO);
//	glBindBuffer(GL_ARRAY_BUFFER, VBO);
//	glBufferData(GL_ARRAY_BUFFER, sizeof(verticesRectangle), verticesRectangle, GL_STATIC_DRAW);
//
//	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, IBO);
//	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), &indices, GL_STATIC_DRAW);
//
//	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
//
//	glEnableVertexAttribArray(0);
//
//	CreateAndCompileShader();
//
//}
//
//void DrawRectangle()
//{
//	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, IBO);
//
//	glBindVertexArray(VAO);
//	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
//	glBindVertexArray(0);
//}
//
//void Triangle_ProcessInput()
//{
//	int Key = Common::GetKey();
//	if (Key == GLFW_KEY_1)
//	{
//		GenerateTriangle();
//		DrawTriangle();
//	}
//	if (Key == GLFW_KEY_2)
//	{
//		GenerateRectangle();
//		DrawRectangle();
//	}
//}