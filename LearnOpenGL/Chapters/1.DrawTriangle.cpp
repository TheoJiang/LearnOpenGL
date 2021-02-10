#include "1.DrawTriangle.h"

using namespace std;

DrawTriangle::DrawTriangle()
{
	Title = "DrawTriangle";
}

DrawTriangle::~DrawTriangle()
{
}
void DrawTriangle::InitData()
{
	string vsStr = LoadShader("Shader/1.triangle.vs");
	string fsStr = LoadShader("Shader/1.triangle.fs");

	const char* vs = vsStr.c_str();
	const char* fs = fsStr.c_str();

	unsigned int vshader;
	vshader = glCreateShader(GL_VERTEX_SHADER);

	glShaderSource(vshader, 1, &vs, NULL);
	glCompileShader(vshader);

	unsigned int fshader;
	fshader = glCreateShader(GL_FRAGMENT_SHADER);

	glShaderSource(fshader, 1, &fs, NULL);
	glCompileShader(fshader);

	if (!IsShaderCompiledSuc(vshader) || !IsShaderCompiledSuc(fshader))
	{
		return;
	}

	shaderP = glCreateProgram();

	glAttachShader(shaderP, vshader);
	glAttachShader(shaderP, fshader);
	glLinkProgram(shaderP);

	if (!IsShaderProgramLinkSuc(shaderP))
	{
		return;
	}


	glDeleteShader(vshader);
	glDeleteShader(fshader);

	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);

	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);

	glBindBuffer(GL_ARRAY_BUFFER, 0);

	glBindVertexArray(0);
}
void DrawTriangle::Draw()
{
	glUseProgram(shaderP);
	glBindVertexArray(vao);
	glDrawArrays(GL_TRIANGLES, 0, 3);
}