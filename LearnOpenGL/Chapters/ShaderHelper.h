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

class ShaderHelper
{
public:
	ShaderHelper();
	ShaderHelper(string vsp, string fsp);
	~ShaderHelper();
	void LoadAllShader(string vsp, string fsp);
	int ID;
	void Use();
	// uniform¹¤¾ßº¯Êý
	void SetBool(const string& name, bool value) const;
	void SetInt(const string& name, int value) const;
	void SetFloat(const string& name, float value) const;
	void SetFloat4(const string& name, float x, float y, float z, float w) const;
private:
	string LoadShader(string shaderPath);
	bool IsShaderCompiledSuc(int shaderID);
	bool IsShaderProgramLinkSuc(int shaderProgramID);


};
