#pragma once
#include <glad/glad.h>
#include <GL/freeglut.h>
#include <GL/gl.h>
#include <GLFW/glfw3.h>
#include <iostream>
class Window {

public:

	bool init(unsigned short SCR_WIDTH, unsigned short SCR_HEIGHT);

	GLFWwindow* window = nullptr;

	Window();
	virtual ~Window();
};

