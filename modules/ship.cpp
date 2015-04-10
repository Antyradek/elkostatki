#include "ship.h"


Ship::Ship(const unsigned short size) : size(size)
{
	/// TO DO
}

void Ship::setVertical(bool vertical)
{
	this->vertical = vertical;
}

void Ship::setPosition(Coord position)
{
	this->position = position;
}

bool Ship::isHit(const Coord position)
{
	/// TO DO
	return true;
}

bool Ship::isAfloat()
{
	/// TO DO
	return true;
}