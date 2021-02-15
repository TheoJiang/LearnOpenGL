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



	drawType = type;
	if (type == 0 || type == 2)
	{
		shader = ShaderHelper("Shader/1.triangle.vs", "Shader/1.triangle.fs");
		//LoadAllShader("Shader/1.triangle.vs", "Shader/1.triangle.fs", &shaderP);
		//glUseProgram(shaderP);
		shader.Use();

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
		ShaderHelper shader("Shader/1.triangle.vs", "Shader/1.triangle.fs");
		shader.Use();

		//LoadAllShader("Shader/1.triangle.vs", "Shader/1.triangle.fs", &shaderP);
		//glUseProgram(shaderP);

		InitRectangleData();
	}
	else if (type == 3)
	{
		ShaderHelper shader("Shader/1.3.MultipleAttributes.vs", "Shader/1.3.MultipleAttributes.fs");
		shader.Use();

		//LoadAllShader("Shader/1.3.MultipleAttributes.vs", "Shader/1.3.MultipleAttributes.fs", &shaderP);
		//glUseProgram(shaderP);

		InitMultipleAttributes();
	}
	glBindVertexArray(vao);
}

void DrawTriangle::InitRectangleData()
{
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

void DrawTriangle::InitMultipleAttributes()
{
	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);

	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(verticesWithColors), verticesWithColors, GL_STATIC_DRAW);

	// positions
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);
	// vertex colors
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
	glEnableVertexAttribArray(1);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}

void DrawTriangle::Draw()
{
	glBindVertexArray(vao);

	if (drawType == 0 || drawType == 3)
	{
		glDrawArrays(GL_TRIANGLES, 0, 3);
	}
	else if(drawType == 1)
	{
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
	}
	else if (drawType == 2)
	{
		float timeV = glfwGetTime();
		float colorV = sin(timeV)/2 + 0.5f;
		//GLuint location = glGetUniformLocation(shaderP, "changingColor");

		//glUniform4f(location, colorV, colorV, colorV, 1);
		shader.SetFloat4("changingColor", colorV, colorV, colorV, 1);

		glDrawArrays(GL_TRIANGLES, 0, 3);

		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
	}
	//glBindVertexArray(0);
}