#include "pch.h"
#include "Tile.h"

Tile& Tile::operator=(int source)
{
	this->m_number = source;

	return *this;
}

std::ostream& operator<<(std::ostream& out, const Tile& obj)
{
	out << ' ';

	if (obj.m_number != 0)
	{
		if (obj.m_number > 9)
			out << obj.m_number;
		else
			out << ' ' << obj.m_number;
	}

	else
		out << ' ';

	out << ' ';

	return out;
}

bool operator==(const Tile& obj, const Tile& obj2)
{
	return (obj.m_number == obj2.m_number);
}

bool Tile::isEmpty() const 
{ 
	return m_number == 0; 
}
int Tile::getNum() const
{ 
	return m_number; 
}