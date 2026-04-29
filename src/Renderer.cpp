#include "Renderer.h"


void Renderer::Draw(const VertexArray& va, const VertexBuffer& vb, const Shader& shader) const
{
	shader.use();
	va.Bind();
	vb.Bind();
	glDrawArrays(GL_TRIANGLES, 0, sizeof(vb));
}


void Renderer::DrawElements(const VertexArray& va, const VertexBuffer& vb, const IndexBuffer& ib, const Shader& shader) const
{
	shader.use();
	va.Bind();
	vb.Bind();
	ib.Bind();
	glDrawElements(GL_TRIANGLES, ib.GetCount(), GL_UNSIGNED_INT, 0);
	//glDrawArrays(GL_TRIANGLES, 0, sizeof(vb));
}

void Renderer::Clear()
{
	glClear(GL_COLOR_BUFFER_BIT);
}


