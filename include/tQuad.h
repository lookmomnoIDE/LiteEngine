#ifndef TQUAD_H
#define TQUAD_H


#include "tVertex.h"

template <typename T>
class tQuad
{
public:

	tVertex<T> v0;
	tVertex<T> v1;
	tVertex<T> v2;
	tVertex<T> v3;
};


#endif