#include <iostream>
#include <GL/glew.h>
#include "display.h"

int main(int argc, char* argv) {
	Display display(800, 600, "hello world");

	while (!display.IsClosing()) {
		display.Clear(0.05f, 0.15f, 0.3f);
		display.Update();
	}
	return 0;
}