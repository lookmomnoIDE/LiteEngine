#ifndef QUAD_H
#define QUAD_H


#include "Vertex.h"

template <typename T>
class Quad
{
public:

	Vertex<T> v0;
	Vertex<T> v1;
	Vertex<T> v2;
	Vertex<T> v3;
};


#endif