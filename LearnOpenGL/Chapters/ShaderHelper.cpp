#include "ShaderHelper.h"

ShaderHelper::ShaderHelper()
{
}

ShaderHelper::ShaderHelper(string vsp, string fsp)
{
	LoadAllShader(vsp, fsp);
}

ShaderHelper::~ShaderHelper()
{
}

void ShaderHelper::LoadAllShader(string vsp, string fsp)
{
	string vsStr = LoadShader(vsp);
	string fsStr = LoadShader(fsp);

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

	ID = glCreateProgram();

	glAttachShader(ID, vshader);
	glAttachShader(ID, fshader);
	glLinkProgram(ID);

	if (!IsShaderProgramLinkSuc(ID))
	{
		return;
	}


	glDeleteShader(vshader);
	glDeleteShader(fshader);
}

string ShaderHelper::LoadShader(string shaderPath)
{
	ifstream vsf(shaderPath);
	if (vsf.is_open())
	{
		string vs((istreambuf_iterator<char>(vsf)), (istreambuf_iterator<char>()));
		cout << vs << endl;
		vsf.close();
		return vs.c_str();
	}
	return "";
}

bool ShaderHelper::IsShaderCompiledSuc(int shaderID)
{
	int suc;
	char info[1024];
	glGetShaderiv(shaderID, GL_COMPILE_STATUS, &suc);
	if (!suc)
	{
		glGetShaderInfoLog(shaderID, 1024, NULL, info);
		cout << "Shader compile error:  " << info << endl;
	}

	return suc;
}

bool ShaderHelper::IsShaderProgramLinkSuc(int shaderProgramID)
{
	int suc;
	char info[1024];
	glGetProgramiv(shaderProgramID, GL_COMPILE_STATUS, &suc);
	if (!suc)
	{
		glGetProgramInfoLog(shaderProgramID, 1024, NULL, info);
		cout << "Shader Program link error:  " << info << endl;
	}
	return suc;
}

void ShaderHelper::Use()
{
	glUseProgram(ID);
}

void ShaderHelper::SetBool(const std::string& name, bool value) const
{
	glUniform1i(glGetUniformLocation(ID, name.c_str()), (int)value);
}
void ShaderHelper::SetInt(const std::string& name, int value) const
{
	glUniform1i(glGetUniformLocation(ID, name.c_str()), value);
}
void ShaderHelper::SetFloat(const std::string& name, float value) const
{
	glUniform1f(glGetUniformLocation(ID, name.c_str()), value);
}
void ShaderHelper::SetFloat4(const std::string& name, float x, float y, float z, float w) const
{
	glUniform4f(glGetUniformLocation(ID, name.c_str()), x, y, z, w);
}