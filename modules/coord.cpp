#include "coord.h"


Coord::Coord(const unsigned short x, const unsigned short y) : x(x), y(y)
{
}
	
Coord::Coord(const Coord & source)
{
	/// TO DO
}
	
Coord & Coord::operator=(const Coord & source)
{
	/// TO DO
	return *this;
}

bool Coord::operator==(const Coord & comp)
{
	/// TO DO
	return true;
}

bool Coord::operator!=(const Coord & comp)
{
	/// TO DO
	return true;
}