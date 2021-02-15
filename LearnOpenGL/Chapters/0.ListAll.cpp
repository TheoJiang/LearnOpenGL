
#include "0.ListAll.h"


Chapter::Chapter()
{
	Title = "empty";
}

Chapter::~Chapter()
{
}

void Chapter::Draw()
{
}
void Chapter::InitData(int type)
{
}
void Chapter::LoadAllShader(string vsp, string fsp, unsigned int *shaderProgramID)
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

	*shaderProgramID = glCreateProgram();

	glAttachShader(*shaderProgramID, vshader);
	glAttachShader(*shaderProgramID, fshader);
	glLinkProgram(*shaderProgramID);

	if (!IsShaderProgramLinkSuc(*shaderProgramID))
	{
		return;
	}


	glDeleteShader(vshader);
	glDeleteShader(fshader);
}

string Chapter::LoadShader(string shaderPath)
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

	//	// 1. 从文件路径中获取顶点/片段着色器
	//std::string vertexCode;
	//std::ifstream vShaderFile;
	//// 保证ifstream对象可以抛出异常：
	//vShaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
	//try
	//{
	//	// 打开文件
	//	vShaderFile.open(shaderPath);
	//	std::stringstream vShaderStream;
	//	// 读取文件的缓冲内容到数据流中
	//	vShaderStream << vShaderFile.rdbuf();
	//	// 关闭文件处理器
	//	vShaderFile.close();
	//	// 转换数据流到string
	//	vertexCode = vShaderStream.str();
	//}
	//catch (std::ifstream::failure e)
	//{
	//	std::cout << "ERROR::SHADER::FILE_NOT_SUCCESFULLY_READ" << std::endl;
	//}
	//const char* vShaderCode = vertexCode.c_str();
	//return vShaderCode;
}

bool Chapter::IsShaderCompiledSuc(int shaderID)
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

bool Chapter::IsShaderProgramLinkSuc(int shaderProgramID)
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