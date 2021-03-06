// 为了避免同一个文件被include多次， C/C++中有两种方式，一种是#ifndef(条件编译)方式，一种是#pragma once方式。
// 在能够支持这两种方式的编译器上，二者并没有太大的区别，但是两者仍然还是有一些细微的区别。
//方式一：
//#ifndef __SOMEFILE_H__
//#define __SOMEFILE_H__
//... ... // 声明、定义语句
//#endif
//
//方式二：
//#pragma once
//... ... // 声明、定义语句
// #ifndef的方式受C/C++语言标准支持。它不光可以保证同一个文件不会被包含多次，也能保证内容完全相同的两个文件（或者代码片段）不会被不小心同时包含。 但是不同文件中的宏名不能相同
// 由于编译器需要打开头文件才能判定是否有重复定义,所以大型项目中会导致编译时间变长. 可移植代码推荐用#ifndef

// #pragma once, 由编译器提供保证, 同一文件不会被 多次包含. 不过此处的同一文件是指物理上的同一文件,而不是内容相同的两个文件. 也无法对一个头文件中的一段代码一作pragma once声明
// 只能针对文件. 好处是不用纠结取宏名, 不会出现宏名冲突.
// #ifndef受语言标准支持,不受编译器的限制. 而#pragma once在一些老版本的编译器上不支持, 兼容性可能不太好.
// 两者也可以一起用.

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
	0.5f, 0.5f, 0.0f,   // 右上角
	0.5f, -0.5f, 0.0f,  // 右下角
	-0.5f, -0.5f, 0.0f, // 左下角
	-0.5f, 0.5f, 0.0f   // 左上角
	};

	unsigned int rectangleIndices[6] = { // 注意索引从0开始! 
		0, 1, 3, // 第一个三角形
		1, 2, 3  // 第二个三角形
	};

	float verticesWithColors[18] = {
		// 位置              // 颜色
		 0.5f, -0.5f, 0.0f,  1.0f, 0.0f, 0.0f,   // 右下
		-0.5f, -0.5f, 0.0f,  0.0f, 1.0f, 0.0f,   // 左下
		 0.0f,  0.5f, 0.0f,  0.0f, 0.0f, 1.0f    // 顶部
	};
	ShaderHelper shader;
	int drawType = 0;
};

