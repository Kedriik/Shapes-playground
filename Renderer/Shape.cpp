#include "stdafx.h"
#include "Shape.h"


Shape::Shape()
{
}

void Shape::draw()
{
	GLint drawMode = GL_POINTS;
	glUseProgram(RenderProgram);
	glBindBufferBase(GL_SHADER_STORAGE_BUFFER, 1, PerFrameBuffer);


	glEnableVertexAttribArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glVertexAttribPointer(
		0,
		4,
		GL_FLOAT,
		GL_FALSE,
		0,
		(void*)0
	);
	glDrawArrays(drawMode, 0, vertices.size());
}

void Shape::update(mat4 _ProjectionMatrix, mat4 _ViewMatrix)
{
	glBindBuffer(GL_SHADER_STORAGE_BUFFER, PerFrameBuffer);
	perFrameData = (struct perFrameData *) glMapBufferRange(GL_SHADER_STORAGE_BUFFER, 0, sizeof(struct perFrameData), GL_MAP_WRITE_BIT | GL_MAP_INVALIDATE_BUFFER_BIT);
	perFrameData->ViewMatrix = _ViewMatrix;
	perFrameData->ProjectionMatrix = _ProjectionMatrix;
	perFrameData->ModelMatrix = ModelMatrix;
	glUnmapBuffer(GL_SHADER_STORAGE_BUFFER);
}

void Shape::update()
{
}

void Shape::drawPoints()
{

}

int Shape::init()
{
	glGenBuffers(1, &PerFrameBuffer);
	glBindBuffer(GL_SHADER_STORAGE_BUFFER, PerFrameBuffer);
	glBufferData(GL_SHADER_STORAGE_BUFFER, sizeof(struct perFrameData), NULL, GL_DYNAMIC_COPY);
	perFrameData = (struct perFrameData *) glMapBufferRange(GL_SHADER_STORAGE_BUFFER, 0, sizeof(struct perFrameData), GL_MAP_WRITE_BIT | GL_MAP_INVALIDATE_BUFFER_BIT);
	glUnmapBuffer(GL_SHADER_STORAGE_BUFFER);

	glGenBuffers(1, &VBO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(glm::vec4), vertices.data(), GL_STATIC_DRAW);

	ShaderInfo  renderShader[] = {
		{ GL_VERTEX_SHADER,  "ShapeShaders\\Vertex.shader" },
		{ GL_FRAGMENT_SHADER,"ShapeShaders\\Fragment.shader" },
		{ GL_NONE, NULL },
		{ GL_NONE, NULL },
		{ GL_NONE, NULL }
	};

	RenderProgram = LoadShaders(renderShader);

	return 0;
}


void Shape::fillVertices()
{
	vertices.push_back(vec4(-0.5, -0.5, 0, 1));
	vertices.push_back(vec4(0.5, -0.5, 0, 1));
	vertices.push_back(vec4(0, 0.5, 0, 1));
	
}

Shape::~Shape()
{
	free(perFrameData);
}
