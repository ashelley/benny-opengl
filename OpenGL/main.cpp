#include <iostream>
#include <GL/glew.h>
#include "display.h"
#include "shader.h"
#include "texture.h"
#include "mesh.h"
#include "transform.h"
#include "camera.h"

#define WIDTH 800
#define HEIGHT 600

int main(int argc, char* argv) {
	Display display(WIDTH, HEIGHT, "hello world");
	Shader shader("./basicShader");
	Texture texture("./textures/bricks.jpg");
	Camera camera(glm::vec3(0, 0, -3), 70.0f, float(WIDTH) / float(HEIGHT), 0.01f, 1000.0f);
	Transform transform;

	Vertex vertices[] = {
		Vertex(glm::vec3(-0.5f,-0.5f,0), glm::vec2(0.0,0.0)),
		Vertex(glm::vec3(0,0.5f,0), glm::vec2(0.5,1.0)),
		Vertex(glm::vec3(0.5f,-0.5f,0), glm::vec2(1.0,0.0))
	};

	Mesh mesh(vertices, sizeof(vertices) / sizeof(vertices[0]));

	float counter = 0.0f;

	while (!display.IsClosing()) {

		float cosCounter = cosf((float)counter / 2.0);

		transform.GetPos().x = sinf(counter);
		transform.GetPos().z = cosCounter;
		transform.GetRot().z = counter;
		transform.GetRot().y = counter;
		transform.GetRot().z = counter;
		//transform.SetScale(glm::vec3(cosCounter, cosCounter, cosCounter));

		display.Clear(0.05f, 0.15f, 0.3f);
		shader.Bind();
		shader.Update(transform, camera);
		texture.Bind(0);
		mesh.Draw();

		display.Update();

		counter += 0.001f;
	}
	return 0;
}