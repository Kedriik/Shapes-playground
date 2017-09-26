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
#include "Shape.h"
using namespace glm;
using namespace std;
class Renderer            //Renderer will handle drawing and interactions between shapes
{
	friend class Shape;
private:

	GLFWwindow *window;
	GLuint FrameBuffer0 = 0;
	mat4 ProjectionMatrix;
	mat4 ViewMatrix;
	vector<Shape> shapes;
public:
	Renderer();
	int init(float height, float width);
	void addShape(Shape _shape);
	void launchLoop();          
	~Renderer();
	
};