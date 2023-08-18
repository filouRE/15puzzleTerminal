#pragma once
#include "pch.h"
#include "Random.h"

class Direction
{
public:
	enum Type
	{
		up,
		down,
		left,
		right,

		max_direction,
	};

	Direction(Type direction)
		: m_currentDirection{ direction }
	{}

	static Direction getRandomDirection();

	friend Direction operator-(const Direction& dir);
	friend std::ostream& operator<<(std::ostream& out, const Direction& obj);
	
	Type getCurrentDirection() const;

private:
	Type m_currentDirection{};
};