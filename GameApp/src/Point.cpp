#include "Point.h"

Point Point::getAdjacentPoint(const Direction& obj)
{
	switch (obj.getCurrentDirection())
	{
	case Direction::up:
		return Point{ this->posX, this->posY - 1 };
	case Direction::down:
		return Point{ this->posX, this->posY + 1 };
	case Direction::left:
		return Point{ this->posX - 1, this->posY };
	case Direction::right:
		return Point{ this->posX + 1, this->posY };
	}

	return *this;
}

bool operator==(const Point& first, const Point& second)
{
	return (first.posX == second.posX) && (first.posY == second.posY);
}

bool operator!=(const Point& first, const Point& second)
{
	return !(first == second);
}