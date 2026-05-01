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

void Renderer::Square(const Entity e, std::vector<float> pos, Shader& shader)
{
	//Calculate Vertices positions

	//manage buffers
		//index 				(constant)
		//vertex array/buffer 	(dynamic)
		//color 				(constant)

	//draw call


	EntityMemoryPool& pool = EntityMemoryPool::Instance();
	//Entity player = pool.addEntity("player");
	size_t id = e.getID(); // however your Entity exposes its index
	pool.getComponent<CTransform>(id).setPos(pos);
	float xRatio = 1920.0f/1050.0f;
	Cgrain& s = pool.getComponent<Cgrain>(id);
	float size = s.getSize();
	std::vector<float> color = {pool.getComponent<Csand>(id).getColor()};


	float halfX = (size / xRatio) / 2.0f;
	float halfY = size / 2.0f;
	std::cout <<"halfX: "<< halfX << ", " <<"halfY: " << halfY << std::endl;

	float verts[] = {
    pos[0] - halfX,  pos[1] - halfY,  -1.0f,  color[0], color[1], color[2], color[3],
    pos[0] + halfX,  pos[1] - halfY,  -1.0f,  color[0], color[1], color[2], color[3],
    pos[0] - halfX,  pos[1] + halfY,  -1.0f,  color[0], color[1], color[2], color[3],
    pos[0] + halfX,  pos[1] + halfY,  -1.0f,  color[0], color[1], color[2], color[3]
};

	/*float verts[] = {
	    pos[0],       		 pos[1], -1.0f,  color[0], color[1], color[2], color[3],
	    (pos[0]+size),         pos[1], -1.0f,  color[0], color[1], color[2], color[3],
	    pos[0],		         pos[1]+size, -1.0f,  color[0], color[1], color[2], color[3],
	    (pos[0]+size),   	     pos[1]+size, -1.0f,  color[0], color[1], color[2], color[3]
	};*/

	/*std::cout << "pos[1] " << pos[1] << std::endl;
	std::cout << "pos[1] + halfY " << pos[1] + halfY << std::endl;
	std::cout << "pos[1] + halfY " << pos[1] + halfY << std::endl;
	std::cout << "pos[1] - halfY " << pos[1] - halfY << std::endl;
	std::cout << "pos[1] - halfY " << pos[1] - halfY << std::endl;*/

/*	unsigned int indices[] = {
	0, 1, 3, 
	0, 2, 3
	};*/
	unsigned int indices[] = {
    0, 1, 3,   // top-left,  top-right,    bottom-right
    0, 3, 2    // top-left,  bottom-right, bottom-left
	};


	VertexArray va;
	VertexBuffer vb(verts, sizeof(verts));

	IndexBuffer ib(indices, 6);

	ib.Bind();

	VertexBufferLayout layout;
	layout.Push<float>(3);
	layout.Push<float>(4);
	va.addBuffer(vb, layout);
	Renderer::DrawElements(va, vb, ib, shader);
}

void Renderer::Clear()
{
	glClear(GL_COLOR_BUFFER_BIT);
}


