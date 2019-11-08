#include "VAO.h"

VAO::VAO() {
}

VAO::VAO(std::vector<Vertex>* vertexBuffer, std::vector<GLuint>* elementBuffer)
	:m_vertexBuffer(vertexBuffer), m_elementBuffer(elementBuffer) {
	Init();
}

void VAO::Draw() {
	glBindVertexArray(getVAO());
	glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_INT, NULL);
}

GLuint VAO::getVAO() {
	return m_VAO;
}

VAO::~VAO() {
	delete m_vertexBuffer;
	delete m_elementBuffer;
	glDeleteBuffers(1, &m_VBO);
	glDeleteBuffers(1, &m_EBO);
	glDeleteVertexArrays(1, &m_VAO);
}

void VAO::Init() {
	glGenVertexArrays(1, &m_VAO);
	glGenBuffers(1, &m_VBO);
	glGenBuffers(1, &m_EBO);
	glBindVertexArray(m_VAO);
	glBindBuffer(GL_ARRAY_BUFFER, m_VBO);
	glBufferDataV(GL_ARRAY_BUFFER, *m_vertexBuffer, GL_STATIC_DRAW);

	//
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_EBO);
	glBufferDataV(GL_ELEMENT_ARRAY_BUFFER, *m_elementBuffer, GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid*)0);

	glEnableVertexAttribArray(0);

	glBindBuffer(GL_ARRAY_BUFFER, 0);

	glBindVertexArray(NULL);
}