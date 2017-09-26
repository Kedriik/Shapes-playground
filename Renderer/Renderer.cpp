#include "Renderer.h"

Renderer::Renderer()
{
}

int Renderer::init(float width, float height)
{
	if (!glfwInit())
	{
		fprintf(stderr, "Failed to initialize GLFW\n");
		return -1;
	}
	std::cout << "GLFW init completed" << std::endl;

	glfwWindowHint(GLFW_SAMPLES, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 4);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_COMPAT_PROFILE);

	window = glfwCreateWindow(width, height, "Simple 2D shapes playground - Kedrowsky Solutions", NULL, NULL);
	glfwMakeContextCurrent(window);

	glewExperimental = true;
	if (glewInit() != GLEW_OK) {
		fprintf(stderr, "Failed to initialize GLEW\n");
		return -1;
	}
	std::cout << "GLEW init completed" << std::endl;
	glfwSetInputMode(window, GLFW_STICKY_KEYS, GL_TRUE);


	glGenFramebuffers(1, &FrameBuffer0);

	return 0;
}

void Renderer::addShape(Shape _shape)
{
	shapes.push_back(_shape);
}

void Renderer::launchLoop()
{
	double deltaTime;
	double loopTotalTime;
	float stallTime = 1.0f;
	do
	{
		static double lastTime = glfwGetTime();
		double currentTime = glfwGetTime();
		deltaTime = double(currentTime - lastTime);
		if (deltaTime > stallTime) deltaTime = 0;
		loopTotalTime += deltaTime;
		lastTime = currentTime;
		glfwSwapBuffers(window);
		glfwPollEvents();

	} while (glfwGetKey(window, GLFW_KEY_ESCAPE) != GLFW_PRESS &&
		glfwWindowShouldClose(window) == 0);
}

Renderer::~Renderer()
{
}
