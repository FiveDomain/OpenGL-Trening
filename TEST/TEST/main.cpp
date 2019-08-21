
#include <glad/glad.h>
//#include <GL/glew.h>
#include <GL/freeglut.h>
#include <GL/gl.h>
#include <GLFW/glfw3.h>
#include <iostream>

#pragma comment(lib, "glew32.lib")
#pragma comment(lib, "freeglut.lib")


using namespace std;

//wymiary obrazu
const int WIDTH = 1280;
const int HEIGHT = 960;

//inicjalizacja obiektu OpenGL 
void OnInit() {
	//ustawienie koloru czerwonego
	glClearColor(0.64f, 0.81f, 0.182f, 0);
	cout << "Inicjalizacja powiod�a si�" << endl;
}

//zwalnianie przydzielonych zasob�w
void OnShutdown() {
	cout << "Zamkni�cie uda�o si�" << endl;
}

//obs�uga zdarzenia zmiany wymiar�w
void OnResize(int nw, int nh) {

}

//funkcja zwrotna wy�wietlania
void OnRender() {
	//czyszczenie bufor�w koloru i g��bi
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	//zamiana bufor�w przedniego i tylnego w celu wy�wietlenia wynik�w renderingu
	glutSwapBuffers();
}

int main(int argc, char** argv) {

	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	//glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		std::cout << "Failed to initialize GLAD" << std::endl;
		return -1;
	}

	return 0;

	/*
	//inicjuj�ce wywo�ania biblioteki freeglut
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
	glutInitContextVersion(3, 3);
	glutInitContextFlags(GLUT_CORE_PROFILE | GLUT_DEBUG);
	glutInitContextProfile(GLUT_FORWARD_COMPATIBLE);
	glutInitWindowSize(WIDTH, HEIGHT);
	glutCreateWindow("Zaczynamy prac� z OpenGL 3.3");

	//inicjalizacja biblioteki GLEW
	glewExperimental = GL_TRUE;
	GLenum err = glewInit();
	if (GLEW_OK != err) {
		cerr << "B��d: " << glewGetErrorString(err) << endl;
	}
	else {
		if (GLEW_VERSION_3_3)
		{
			cout << "Sterownik obs�uguje OpenGL 3.3\nSczeg�y:" << endl;
		}
	}

	//wy�wietlanie informacji
	cout << "\tBiblioteka GLEW " << glewGetString(GLEW_VERSION) << endl;
	cout << "\tProducent: " << glGetString(GL_VENDOR) << endl;
	cout << "\tRenderer: " << glGetString(GL_RENDERER) << endl;
	cout << "\tWersja: " << glGetString(GL_VERSION) << endl;
	cout << "\tGLSL: " << glGetString(GL_SHADING_LANGUAGE_VERSION) << endl;

	//inicjalizacja OpenGL
	OnInit();

	//rejestracja funkcji zwrotnych
	glutCloseFunc(OnShutdown);
	glutDisplayFunc(OnRender);
	glutReshapeFunc(OnResize);

	//uruchomienie g��wnej p�tli
	glutMainLoop();

	return 0;*/
}