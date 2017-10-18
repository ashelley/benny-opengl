#ifndef TEXTURE_H
#define TEXTURE_H

#include "GL/glew.h"
#include <string>

class Texture {
public:
	Texture(const std::string fileName);
	void Bind(unsigned int unit);
	~Texture();
private:
	GLuint m_texture;
};


#endif