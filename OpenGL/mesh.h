#ifndef MESH_H
#define MESH_H

#include "glm/glm.hpp"
#include "GL/glew.h"

class Vertex {
public:
	Vertex(glm::vec3& pos, const glm::vec2 texCoord) {
		this->pos = pos;
		this->texCoord = texCoord;
	}
	glm::vec3 pos;
	glm::vec2 texCoord;
private:
};

class Mesh {
public: 
	Mesh(Vertex *vertices, unsigned int numVertices);
	void Draw();
	virtual ~Mesh();
protected:
private:
	Mesh(const Mesh& other);
	Mesh& operator=(const Mesh& other);

	enum {
		POSITION_VB,
		TEXCOORD_VB,

		NUM_BUFFERS
	};

	GLuint m_vertexArrayObject;
	GLuint m_vertexArrayBuffers[NUM_BUFFERS];
	unsigned int m_drawCount;
};
#endif