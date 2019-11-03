#ifndef SHADER_H
#define SHADER_H

#include "TBase.h"
//#include <glad/glad.h> // include glad to get all the required OpenGL headers

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

enum ShaderType {
	VERTEX_SHADER = GL_VERTEX_SHADER,
	FRAGMENT_SHADER = GL_FRAGMENT_SHADER
};

class Shader {

	ShaderType typeshader;
	GLint succes;
	GLchar errBuffer[512];

	GLuint t_ShaderID;
public:
	void LoadFromFile(const char* filename, ShaderType shaderType);

	Shader(const char* filename, ShaderType shaderType);
	GLuint getShaderID();

	~Shader();
	
	unsigned int ID;


	Shader(const GLchar* vertexPath, const GLchar* fragmentPath);

	void use();
	void setBool(const std::string &name, bool value) const;
	void setInt(const std::string &name, int value) const;
	void setFloat(const std::string &name, float value) const;
	
};

#endif