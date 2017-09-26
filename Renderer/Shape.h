#pragma once
#include "glew-2.0.0\include\GL\glew.h"
#include "glfw-3.2.1.bin.WIN64\include\GLFW\glfw3.h"
#include "glm\glm\gtx\transform.hpp"
#include "glm\glm\gtc\matrix_transform.hpp"
#include "glm\glm\gtc\quaternion.hpp"
#include "glm\glm\gtx\quaternion.hpp"
#include <iostream>
#include "glm\glm\glm.hpp"
#include <string>
#include <fstream>
#include "LoadShaders\include\LoadShaders.h"
#include <vector>
#include <time.h>
#include <conio.h>
#include <vector>
#include <chrono>
#include "glm\glm\glm.hpp"
#include "Renderer.h"
using namespace std;
using namespace glm;
class Shape
{
	friend class Renderer;
private:
	GLuint RenderProgram;
	GLuint VBO, PerFrameBuffer;
	struct perFrameData
	{
		mat4 ModelMatrix;
		mat4 ProjectionMatrix;
		mat4 ViewMatrix;
		vec4 additionalStorage; // time, size etc, buffers need to be aligned to 4 floats
	} *perFrameData;
	
	vector<vec4> vertices;
	mat4 ModelMatrix;
public:
	Shape();
	void draw();
	void update(mat4 ProjectionMatrix=mat4(1.0f), mat4 ViewMatrix=mat4(1.0f));
	void drawPoints();
	int init();
	void update();
	void loadVertices();
	void fillVertices();
	~Shape();
};

