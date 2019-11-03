#include "Engine.h"

Engine::Engine() {

}


Engine::~Engine() {
}

void framebuffer_size_callback(GLFWwindow * window, int width, int height) {
	glViewport(0, 0, width, height);
}


int Engine::Engine_main() {

	auto t_Window = new Window;

	t_Window->init(this->SCR_WIDTH, this->SCR_HEIGHT);

	Vertex vert[] = {
		{ glm::vec3(-0.5f,-0.5f,1.0f) },
		{ glm::vec3(0.5f,-0.5f,1.0f) },
		{ glm::vec3(0.0f,0.5f,1.0f) }
	};

	GLuint indicies[] = { 0,1,2 };

	VAO vao(new std::vector<Vertex>(vert, std::end(vert)), new std::vector<GLuint>(indicies, std::end(indicies)));

	auto ourShader = Shader("3.3.shader.vs", "3.3.shader.fs");
	int nrAttributes;

	glGetIntegerv(GL_MAX_VERTEX_ATTRIBS, &nrAttributes);

	std::cout << "Maximum nr of vertex attributes supported: " << nrAttributes << std::endl;
	glfwSetFramebufferSizeCallback(t_Window->window, framebuffer_size_callback);

	//glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	//glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	while (!glfwWindowShouldClose(t_Window->window)) {

		processInput(t_Window->window);

		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		ourShader.use();
		ourShader.setFloat("someUniform", 1.0f);
		glBindVertexArray(vao.getVAO());
		glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_INT, NULL);

		//glDrawArrays(GL_TRIANGLES, 0, 3);

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