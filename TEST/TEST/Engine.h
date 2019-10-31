#pragma once
#include "TBase.h"
#include "Shader.h"
#include "Window.h"

class Engine {

	void processInput(GLFWwindow *window);

	//void framebuffer_size_callback(GLFWwindow * window, int width, int height);
	const unsigned int SCR_WIDTH = 800;
	const unsigned int SCR_HEIGHT = 600;

public:
	int Engine_main();

	Engine();
	virtual ~Engine();
};

