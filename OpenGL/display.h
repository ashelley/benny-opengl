#ifndef DISPLAY_H
#define DISPLAY_H

#include "sdl/SDL.h"
#undef main
#include <string>;

class Display {
public:
	Display(int width, int height, const std::string& title);
	void Update();
	void Clear(float r, float g, float b);
	bool IsClosing();
	virtual ~Display();
protected:
private:
	Display(const Display &other) {}
	Display& operator=(const Display& other) {}

	SDL_Window* m_window;
	SDL_GLContext m_glContext;
	bool isClosing;
};

#endif