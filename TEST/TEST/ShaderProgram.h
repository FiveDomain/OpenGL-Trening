#pragma once
#include "TBase.h"
#include "Shader.h"

class ShaderProgram {

	GLuint t_program;

	Shader *t_vertexShader;

	Shader *t_fragmentShader;
public:

	void init();

	ShaderProgram();
	virtual ~ShaderProgram();
};

