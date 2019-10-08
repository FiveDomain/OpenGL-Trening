#pragma once
#include "TBase.h"

class Window {

public:

	bool init(unsigned short SCR_WIDTH, unsigned short SCR_HEIGHT);

	GLFWwindow* window = nullptr;

	Window();
	virtual ~Window();
};

