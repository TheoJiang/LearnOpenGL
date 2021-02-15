// Ϊ�˱���ͬһ���ļ���include��Σ� C/C++�������ַ�ʽ��һ����#ifndef(��������)��ʽ��һ����#pragma once��ʽ��
// ���ܹ�֧�������ַ�ʽ�ı������ϣ����߲�û��̫������𣬵���������Ȼ������һЩϸ΢������
//��ʽһ��
//#ifndef __SOMEFILE_H__
//#define __SOMEFILE_H__
//... ... // �������������
//#endif
//
//��ʽ����
//#pragma once
//... ... // �������������
// #ifndef�ķ�ʽ��C/C++���Ա�׼֧�֡���������Ա�֤ͬһ���ļ����ᱻ������Σ�Ҳ�ܱ�֤������ȫ��ͬ�������ļ������ߴ���Ƭ�Σ����ᱻ��С��ͬʱ������ ���ǲ�ͬ�ļ��еĺ���������ͬ
// ���ڱ�������Ҫ��ͷ�ļ������ж��Ƿ����ظ�����,���Դ�����Ŀ�лᵼ�±���ʱ��䳤. ����ֲ�����Ƽ���#ifndef

// #pragma once, �ɱ������ṩ��֤, ͬһ�ļ����ᱻ ��ΰ���. �����˴���ͬһ�ļ���ָ�����ϵ�ͬһ�ļ�,������������ͬ�������ļ�. Ҳ�޷���һ��ͷ�ļ��е�һ�δ���һ��pragma once����
// ֻ������ļ�. �ô��ǲ��þ���ȡ����, ������ֺ�����ͻ.
// #ifndef�����Ա�׼֧��,���ܱ�����������. ��#pragma once��һЩ�ϰ汾�ı������ϲ�֧��, �����Կ��ܲ�̫��.
// ����Ҳ����һ����.

#pragma once
#include "0.ListAll.h"

class DrawTriangle : public Chapter
{
public:
	DrawTriangle();
	~DrawTriangle();
	void Draw();
	void InitData(int type);

	void InitRectangleData();
	void InitMultipleAttributes();
private:
	unsigned int vao;
	unsigned int vbo;
	unsigned int shaderP;

	float vertices[9] = {
	-0.5f, -0.5f, 0.0f,
	 0.5f, -0.5f, 0.0f,
	 0.0f,  0.5f, 0.0f
	};

	unsigned int ebo;

	float rectangle[12] = {
	0.5f, 0.5f, 0.0f,   // ���Ͻ�
	0.5f, -0.5f, 0.0f,  // ���½�
	-0.5f, -0.5f, 0.0f, // ���½�
	-0.5f, 0.5f, 0.0f   // ���Ͻ�
	};

	unsigned int rectangleIndices[6] = { // ע��������0��ʼ! 
		0, 1, 3, // ��һ��������
		1, 2, 3  // �ڶ���������
	};

	float verticesWithColors[18] = {
		// λ��              // ��ɫ
		 0.5f, -0.5f, 0.0f,  1.0f, 0.0f, 0.0f,   // ����
		-0.5f, -0.5f, 0.0f,  0.0f, 1.0f, 0.0f,   // ����
		 0.0f,  0.5f, 0.0f,  0.0f, 0.0f, 1.0f    // ����
	};
	ShaderHelper shader;
	int drawType = 0;
};

