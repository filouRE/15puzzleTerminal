#include "pch.h"
#include "Direction.h"

Direction Direction::getRandomDirection()
{
	// get random number from 0 to 3
	Type random{ static_cast<Type>(Random::get(0, Type::max_direction - 1)) };

	return Direction{ random };
}

// returns the opposite direction
Direction operator-(const Direction& dir)
{
	switch (dir.m_currentDirection)
	{
	case Direction::up:
		return Direction(Direction::down);
	case Direction::down:
		return Direction(Direction::up);
	case Direction::left:
		return Direction(Direction::right);
	case Direction::right:
		return Direction(Direction::left);
	default:
		break;
	}
}

std::ostream& operator<<(std::ostream& out, const Direction& obj)
{
	switch (obj.m_currentDirection)
	{
	case Direction::up:
		out << "up";
		break;
	case Direction::down:
		out << "down";
		break;
	case Direction::left:
		out << "left";
		break;
	case Direction::right:
		out << "right";
		break;
	default:
		break;
	}

	return out;
}

Direction::Type Direction::getCurrentDirection() const // Public function to access m_currentDirection
{
	return m_currentDirection;
}