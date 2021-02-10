#pragma once
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
// Include glfw3.h after our OpenGL definitions
#include <GLFW/glfw3.h>
#include <stdio.h>

#include "imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"


#include <vector>
#include <string>

#include <fstream> 
#include <iostream> 
#include <sstream> 

using namespace std;

struct ChapterInfo
{
	char *chapterName;
};

class Chapter
{
public:
	Chapter();
	~Chapter();
	virtual void Draw();
	virtual void InitData();
	string Title;
protected:
	string LoadShader(string shaderPath);
	bool IsShaderCompiledSuc(int shaderID);
	bool IsShaderProgramLinkSuc(int shaderProgramID);
private:
};
