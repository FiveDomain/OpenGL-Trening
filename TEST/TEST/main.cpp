//#include <GL/glew.h>
#include <glad/glad.h>
#include <GL/freeglut.h>
#include <GL/gl.h>
#include <GLFW/glfw3.h>

#include "Shader.h"
#include "Window.h"

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void processInput(GLFWwindow *window);

const unsigned int SCR_WIDTH = 800;
const unsigned int SCR_HEIGHT = 600;

auto TWindow = new Window;

float vertices[] = {		//colors
	-0.5f, -0.5f, 0.0f,		1.0f, 0.0f, 0.0f,	// bottom right
	 0.5f, -0.5f, 0.0f,		0.0f, 1.0f, 0.0f,	// bottom left
	 0.0f,  0.5f, 0.0f,		0.0f, 0.0f, 1.0f	// top
};




int main() {
	TWindow->init(SCR_WIDTH, SCR_HEIGHT);

	glfwSetFramebufferSizeCallback(TWindow->window, framebuffer_size_callback);

	
	unsigned int VBO,VAO;
	glGenBuffers(1, &VBO);
	glGenVertexArrays(1, &VAO);
	glBindVertexArray(VAO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);

	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices),vertices, GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);	
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3*sizeof(float)));
	glEnableVertexAttribArray(1);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);

	auto ourShader = Shader("3.3.shader.vs", "3.3.shader.fs");
	int nrAttributes;
	glGetIntegerv(GL_MAX_VERTEX_ATTRIBS, &nrAttributes);
	std::cout << "Maximum nr of vertex attributes supported: " << nrAttributes << std::endl;
	while (!glfwWindowShouldClose(TWindow->window)) {

		processInput(TWindow->window);
		
		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		ourShader.use();
		ourShader.setFloat("someUniform", 1.0f);
		glBindVertexArray(VAO);
		/*float timeValue = glfwGetTime();
		float greenValue = sin(timeValue) / 2.0f + 0.5f;
		int vertexColorLocation = glGetUniformLocation(shaderProgram, "ourColor");
		glUniform4f(vertexColorLocation, 1.0f, greenValue, 0.0f, 1.0f);*/

		glDrawArrays(GL_TRIANGLES, 0, 3);

		glfwSwapBuffers(TWindow->window);
		glfwPollEvents();
	}
	/*
	glDeleteVertexArrays(1, &VAO);
	glDeleteBuffers(1, &VBO);
	*/
	glfwTerminate();
	return 0;
}

void processInput(GLFWwindow *window) {
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS || glfwGetKey(window, GLFW_KEY_SPACE) == GLFW_PRESS)
		glfwSetWindowShouldClose(window, true);
}

void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
	glViewport(0, 0, width, height);
}