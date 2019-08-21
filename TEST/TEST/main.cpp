
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

	//rejestracja funkcji zwrotnych
	glutCloseFunc(OnShutdown);
	glutDisplayFunc(OnRender);
	glutReshapeFunc(OnResize);

	//uruchomienie g³ównej pêtli
	glutMainLoop();

	return 0;*/
}