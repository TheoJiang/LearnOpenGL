#include "1.DrawTriangle.h"

using namespace std;

DrawTriangle::DrawTriangle()
{
	Title = "DrawTriangle";
}

DrawTriangle::~DrawTriangle()
{
}
void DrawTriangle::InitData(int type)
{
	glDeleteBuffers(1, &vao);
	glDeleteBuffers(1, &vbo);
	glDeleteBuffers(1, &ebo);

	LoadAllShader("Shader/1.triangle.vs", "Shader/1.triangle.fs", &shaderP);
	glUseProgram(shaderP);
	drawType = type;
	if (type == 0 || type == 2)
	{
		useEbo = false;
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
	else if(type == 1)
	{
		InitRectangleData();
	}
	glBindVertexArray(vao);
}

void DrawTriangle::InitRectangleData()
{
	useEbo = true;
	//glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);

	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(rectangle), rectangle, GL_STATIC_DRAW);

	glGenBuffers(1, &ebo);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(rectangleIndices), rectangleIndices, GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}



void DrawTriangle::Draw()
{
	glBindVertexArray(vao);

	if (drawType == 1)
	{
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
	}
	else if(drawType == 0)
	{
		glDrawArrays(GL_TRIANGLES, 0, 3);
	}
	else if (drawType == 2)
	{

		float timeV = glfwGetTime();
		float colorV = sin(timeV)/2 + 0.5f;
		GLuint location = glGetUniformLocation(shaderP, "changingColor");
		glUniform4f(location, colorV, colorV, colorV, 1);

		glDrawArrays(GL_TRIANGLES, 0, 3);

		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
	}
	//glBindVertexArray(0);
}