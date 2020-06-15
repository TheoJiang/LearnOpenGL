#pragma once
#include <glad/glad.h>
#include <GLFW/glfw3.h>

//static void SetKey(int key)
//{
//	trigeredKey = key;
//}

class Common
{
public:
	static Common *GetInstance();

	Common();
	~Common();

	static void SetKey(int key);
	static int GetKey();
private:
	int trigeredKey = GLFW_KEY_UNKNOWN;

	static Common *instance;

};
