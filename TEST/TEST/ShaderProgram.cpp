#include "ShaderProgram.h"



void ShaderProgram::init() {
	t_program = glCreateProgram();
	glAttachShader(t_program, t_vertexShader->getShaderID());
	glAttachShader(t_program, t_fragmentShader->getShaderID());
}


ShaderProgram::ShaderProgram() {
}


ShaderProgram::~ShaderProgram() {
}
