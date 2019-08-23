#include <GL/glew.h>
#include <GL/freeglut.h>
#include <GL/gl.h>
#include <GLFW/glfw3.h>
#include <iostream>

using namespace std;

static unsigned int CompileShader( unsigned int type, const std::string& sourse) {
	unsigned int id = glCreateShader(type);
	const char* src = sourse.c_str();
	glShaderSource(id, 1, &src, nullptr);
	glCompileShader(id);

	int result;
	glGetShaderiv(id, GL_COMPILE_STATUS, &result);
	if (result == GL_FALSE) {
		int lenght;
		glGetShaderiv(id, GL_INFO_LOG_LENGTH, &lenght);
		char* message = static_cast<char*>(alloca(lenght * sizeof(char)));
		glGetShaderInfoLog(id, lenght, &lenght, message);
		cout << "failed to compile shader!" << (type == GL_VERTEX_SHADER ? "vertex" : "fragment") << endl;
		cout << message << endl;
		glDeleteShader(id);
		return 0;
	}
	return id;
}

static int CreateShader(const std::string& vertexShader, const std::string& fragmentShader) {
	unsigned int program = glCreateProgram();
	unsigned int vs = CompileShader(GL_VERTEX_SHADER, vertexShader);
	unsigned int fs = CompileShader(GL_FRAGMENT_SHADER, fragmentShader);
	
	glAttachShader(program, vs);
	glAttachShader(program, fs);
	glLinkProgram(program);
	glValidateProgram(program);

	glDeleteShader(vs);
	glDeleteShader(fs);

	return program;
}

//wymiary obrazu
const int WIDTH = 1280;
const int HEIGHT = 960;

//inicjalizacja obiektu OpenGL 
void OnInit() {
	//ustawienie koloru czerwonego
	glClearColor(0.3f, 0.8f, 0.4f, 0);
	cout << "Inicjalizacja powiod³a siê" << endl;
}

//zwalnianie przydzielonych zasobów
void OnShutdown() {
	cout << "Zamkniêcie uda³o siê" << endl;
}

//obs³uga zdarzenia zmiany wymiarów
void OnResize(int nw, int nh) {

}

//funkcja zwrotna wyœwietlania
void OnRender() {
	//czyszczenie buforów koloru i g³êbi
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	//zamiana buforów przedniego i tylnego w celu wyœwietlenia wyników renderingu
	glutSwapBuffers();
}

int main(int argc, char** argv) {


	
	//inicjuj¹ce wywo³ania biblioteki freeglut
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
	glutInitContextVersion(3, 3);
	glutInitContextFlags(GLUT_CORE_PROFILE | GLUT_DEBUG);
	glutInitContextProfile(GLUT_FORWARD_COMPATIBLE);
	glutInitWindowSize(WIDTH, HEIGHT);
	glutCreateWindow("Zaczynamy pracê z OpenGL 3.3");

	//inicjalizacja biblioteki GLEW
	glewExperimental = GL_TRUE;
	GLenum err = glewInit();
	if (GLEW_OK != err) {
		cerr << "B³¹d: " << glewGetErrorString(err) << endl;
	}
	else {
		if (GLEW_VERSION_3_3)
		{
			cout << "Sterownik obs³uguje OpenGL 3.3\nSczegó³y:" << endl;
		}
	}

	//wyœwietlanie informacji
	cout << "\tBiblioteka GLEW " << glewGetString(GLEW_VERSION) << endl;
	cout << "\tProducent: " << glGetString(GL_VENDOR) << endl;
	cout << "\tRenderer: " << glGetString(GL_RENDERER) << endl;
	cout << "\tWersja: " << glGetString(GL_VERSION) << endl;
	cout << "\tGLSL: " << glGetString(GL_SHADING_LANGUAGE_VERSION) << endl;

	//inicjalizacja OpenGL
	OnInit();

	std::string vertexShader =
		"#version 330 core"
		"\n"
		"layout(location = 0) in vec4 position;\n"
		"\n"
		"void main() {\n"
		"gl_Position = position;\n"
		"}\n"
		"\n";
	std::string fragmentShader =
		"#version 330 core"
		"\n"
		"layout(location = 0) out vec4 color; \n"
		"\n"
		"void main() {\n"
		"color = vec4(1.0, 0.0, 0.0, 1.0); \n"
		"}\n"
		"\n";

	unsigned int shader = CreateShader(vertexShader, fragmentShader);

	glUseProgram(shader);

	//rejestracja funkcji zwrotnych
	glutCloseFunc(OnShutdown);
	glutDisplayFunc(OnRender);
	glutReshapeFunc(OnResize);

	//vec4(position.xy)

	//uruchomienie g³ównej pêtli
	glutMainLoop();

	return 0;
}