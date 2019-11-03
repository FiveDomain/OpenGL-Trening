#pragma once
#include "TBase.h"
#include "Shader.h"
#include "Window.h"
#include "VAO.h"

class Engine {

	void processInput(GLFWwindow *window);

	const unsigned int SCR_WIDTH = 800;
	const unsigned int SCR_HEIGHT = 600;

public:
	int Engine_main();

	Engine();
	virtual ~Engine();
};

