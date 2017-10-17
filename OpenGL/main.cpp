#include <iostream>
#include <GL/glew.h>
#include "display.h"
//#include "shader.h"
#include "mesh.h"

int main(int argc, char* argv) {
	Display display(800, 600, "hello world");

	Vertex vertices[] = {
		Vertex(glm::vec3(-0.5f,-0.5f,0)),
		Vertex(glm::vec3(0,0.5f,0)) ,
		Vertex(glm::vec3(0.5f,-0.5f,0))
	};

	Mesh mesh(vertices, sizeof(vertices) / sizeof(vertices[0]));

	while (!display.IsClosing()) {
		display.Clear(0.05f, 0.15f, 0.3f);

		mesh.Draw();

		display.Update();
	}
	return 0;
}