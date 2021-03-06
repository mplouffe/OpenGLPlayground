#include "VertexBuffer.h"

#include "Renderer.h"

VertexBuffer::VertexBuffer(const void * data, unsigned int size)
{
	glGenBuffers(1, &m_RendererID);													// create vertex buffer
	GLCall(glBindBuffer(GL_ARRAY_BUFFER, m_RendererID));									// bind buffer
	glBufferData(GL_ARRAY_BUFFER, size, data, GL_STREAM_DRAW);						// set layout of buffer
}

VertexBuffer::~VertexBuffer()
{
	GLCall(glDeleteBuffers(1, &m_RendererID));
}

void VertexBuffer::Bind() const
{
	GLCall(glBindBuffer(GL_ARRAY_BUFFER, m_RendererID));
}

void VertexBuffer::UnBind() const
{
	GLCall(glBindBuffer(GL_ARRAY_BUFFER, 0));
}

void VertexBuffer::UpdateBuffer(const void * data, unsigned int size)
{
	GLCall(glBindBuffer(GL_ARRAY_BUFFER, m_RendererID));
	glBufferData(GL_ARRAY_BUFFER, size, data, GL_STREAM_DRAW);
}

