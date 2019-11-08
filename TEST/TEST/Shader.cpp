#include "Shader.h"
//do narpawy

void checkCompileErrors(unsigned int shader, std::string type);

Shader::Shader(const GLchar * vertexPath, const GLchar * fragmentPath) {
	// 1. retrieve the vertex/fragment source code from filePath
	std::string vertexCode;
	std::string fragmentCode;
	std::ifstream vShaderFile;
	std::ifstream fShaderFile;
	/*
	int nrAttributes;

	glGetIntegerv(GL_MAX_VERTEX_ATTRIBS, &nrAttributes);
	std::cout << "Maximum nr of vertex attributes supported: " << nrAttributes << std::endl;
	*/
	// ensure ifstream objects can throw exceptions:
	vShaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
	fShaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
	try {
		vShaderFile.open(vertexPath);
		fShaderFile.open(fragmentPath);

		std::stringstream vShaderStream, fShaderStream;
		
		vShaderStream << vShaderFile.rdbuf();
		fShaderStream << fShaderFile.rdbuf();
		
		vShaderFile.close();
		fShaderFile.close();
		
		vertexCode = vShaderStream.str();
		fragmentCode = fShaderStream.str();
	}
	catch (std::ifstream::failure e) {
		std::cout << "ERROR::SHADER::FILE_NOT_SUCCESFULLY_READ" << std::endl;
	}
	const char* vShaderCode = vertexCode.c_str();
	const char * fShaderCode = fragmentCode.c_str();
	// compile shaders
	unsigned int vertex, fragment;
	// vertex shader
	vertex = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertex, 1, &vShaderCode, NULL);
	glCompileShader(vertex);
	checkCompileErrors(vertex, "VERTEX");
	// fragment Shader
	fragment = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragment, 1, &fShaderCode, NULL);
	glCompileShader(fragment);
	checkCompileErrors(fragment, "FRAGMENT");
	// shader Program
	ID = glCreateProgram();
	glAttachShader(ID, vertex);
	glAttachShader(ID, fragment);
	glLinkProgram(ID);
	checkCompileErrors(ID, "PROGRAM");

	glDeleteShader(vertex);
	glDeleteShader(fragment);
}

void Shader::clear(float red, float gren, float blue, float alfa ) {
	glClearColor(red, gren, blue, alfa);
	glClear(GL_COLOR_BUFFER_BIT);
}

void checkCompileErrors(unsigned int shader, std::string type) {
	int success;
	char infoLog[1024];
	if (type != "PROGRAM") {
		glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
		if (!success) {
			glGetShaderInfoLog(shader, 1024, NULL, infoLog);
			std::cout << "ERROR::SHADER_COMPILATION_ERROR of type: " << type << "\n" << infoLog << "\n -- --------------------------------------------------- -- " << std::endl;
		}
	}
	else {
		glGetProgramiv(shader, GL_LINK_STATUS, &success);
		if (!success) {
			glGetProgramInfoLog(shader, 1024, NULL, infoLog);
			std::cout << "ERROR::PROGRAM_LINKING_ERROR of type: " << type << "\n" << infoLog << "\n -- --------------------------------------------------- -- " << std::endl;
		}
	}

}

void Shader::use() {
	glUseProgram(this->ID);
}

void Shader::setBool(const std::string & name, bool value) const {
	glUniform1i(glGetUniformLocation(ID, name.c_str()), (int)value);
}

void Shader::setInt(const std::string & name, int value) const {
	glUniform1i(glGetUniformLocation(ID, name.c_str()), value);
}

void Shader::setFloat(const std::string & name, float value) const {
	glUniform1f(glGetUniformLocation(ID, name.c_str()), value);
}
/*
void Shader::LoadFromFile(const char * filename, ShaderType shaderType) {
	std::fstream file;
	file.open(filename, std::ios::in);

	if (!file) {
		std::cerr << "Filed to open Shdaer file :( \n";
		return;
	}

	std::stringstream sstream;

	sstream << file.rdbuf();

	file.close();

	std::string str = sstream.str();

	const char* shaderText = str.c_str();

	t_ShaderID = glCreateShader(shaderType); 

	glShaderSource(t_ShaderID, 1, &shaderText, NULL);
	glCompileShader(t_ShaderID);
	glGetShaderiv(t_ShaderID, GL_COMPILE_STATUS, &succes);
	
	if (!succes) {
		glad_glGetShaderInfoLog(t_ShaderID, 512, NULL, errBuffer);
		std::cerr << "Filed to compile shader fro file: "  << filename << " "  << errBuffer;

	}
}
*//*
Shader::Shader(const char * filename, ShaderType sType) {
	LoadFromFile(filename, sType);
}
*/
GLuint Shader::getShaderID()
{
	return GLuint(t_ShaderID);
}

Shader::~Shader() {
}
