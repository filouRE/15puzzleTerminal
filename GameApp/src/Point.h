#pragma once
#include "Direction.h"

struct Point
{
public:
	int posX{};
	int posY{};

	Point getAdjacentPoint(const Direction& obj);
};

bool operator==(const Point& first, const Point& second);
bool operator!=(const Point& first, const Point& second);