#pragma once
#include "Matiere.h"
class a
{
private:
	int x;
	int y;
	int z;
	Matiere m;
public:
	a(int x, int y, int z, const Matiere& m)
		: x(x),
		  y(y),
		  z(z),
		  m(m)
	{
	}

	a() = default;
};

