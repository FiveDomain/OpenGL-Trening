#include "Engine.h"

Engine::Engine() {

}


Engine::~Engine() {
}

void framebuffer_size_callback(GLFWwindow * window, int width, int height) {
	glViewport(0, 0, width, height);
}


int Engine::Engine_main() {

	float vertices[] = {		//colors
	-0.5f, -0.5f, 0.0f,		1.0f, 0.0f, 0.0f,	// bottom right
	 0.5f, -0.5f, 0.0f,		0.0f, 1.0f, 0.0f,	// bottom left
	 0.0f,  0.5f, 0.0f,		0.0f, 0.0f, 1.0f	// top
	};

	auto t_Window = new Window;

	t_Window->init(this->SCR_WIDTH, this->SCR_HEIGHT);



	//resize

	unsigned int VBO, VAO;
	glGenBuffers(1, &VBO);
	glGenVertexArrays(1, &VAO);
	glBindVertexArray(VAO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);

	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
	glEnableVertexAttribArray(1);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);

	auto ourShader = Shader("3.3.shader.vs", "3.3.shader.fs");
	int nrAttributes;

	glGetIntegerv(GL_MAX_VERTEX_ATTRIBS, &nrAttributes);

	std::cout << "Maximum nr of vertex attributes supported: " << nrAttributes << std::endl;
	glfwSetFramebufferSizeCallback(t_Window->window, framebuffer_size_callback);

	while (!glfwWindowShouldClose(t_Window->window)) {

		processInput(t_Window->window);

		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		ourShader.use();
		ourShader.setFloat("someUniform", 1.0f);
		glBindVertexArray(VAO);

		glDrawArrays(GL_TRIANGLES, 0, 3);

		glfwSwapBuffers(t_Window->window);
		glfwPollEvents();
	}

	glfwTerminate();
	return 0;
}


void Engine::processInput(GLFWwindow * window) {
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS || glfwGetKey(window, GLFW_KEY_SPACE) == GLFW_PRESS) {
		glfwSetWindowShouldClose(window, true);
	}
}