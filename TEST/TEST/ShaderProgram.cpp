#include "ShaderProgram.h"



void ShaderProgram::init() {
	t_program = glCreateProgram();
	glAttachShader(t_program, t_vertexShader->getShaderID());
	glAttachShader(t_program, t_fragmentShader->getShaderID());
	glLinkProgram(t_program);

	glGetProgramiv(t_program, GL_LINK_STATUS, &this->succes);

	if (!succes) {
		glGetProgramInfoLog(t_program, 512, NULL, errBuffer);
		std::cerr << "Filed to compile shader fro file: " << errBuffer;
	}
}


ShaderProgram::ShaderProgram() {
}


ShaderProgram::ShaderProgram(std::shared_ptr<Shader> vs, std::shared_ptr<Shader> fs) :t_vertexShader(vs),t_fragmentShader(fs) {
	init();
}	

ShaderProgram::~ShaderProgram() {
}
