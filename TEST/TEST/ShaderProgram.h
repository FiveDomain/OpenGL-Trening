#pragma once
#include "TBase.h"
#include "Shader.h"
#include <memory>

class ShaderProgram {

	GLuint t_program;
	GLint succes;
	GLchar errBuffer[512];

	std::shared_ptr<Shader> t_vertexShader;
	std::shared_ptr<Shader> t_fragmentShader;

public:

	void init();

	ShaderProgram();
	ShaderProgram(std::shared_ptr<Shader> vs, std::shared_ptr<Shader> fs);
	virtual ~ShaderProgram();
};

