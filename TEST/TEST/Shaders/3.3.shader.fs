#version 330 core\n
	out vec4 FragColor;\n
	in vec3 ourColor;\n
	//uniform vec4 ourColor;\n
		void main()\n
		{\n
		   FragColor = vec4(ourColor, 1.0);\n
		}\n\0;