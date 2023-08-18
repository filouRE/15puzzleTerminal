#pragma once
#include "pch.h"

class Tile
{
public:
	Tile() = default;
	explicit Tile(int number)
		: m_number{ number }
	{}

	Tile& operator=(int source);
	friend std::ostream& operator<<(std::ostream& out, const Tile& obj);
	friend bool operator==(const Tile& obj, const Tile& obj2);

	bool isEmpty() const;
	int getNum() const;

private:
	int m_number{};
};