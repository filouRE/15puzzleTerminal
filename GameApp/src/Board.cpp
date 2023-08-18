#include "pch.h"
#include "Board.h"

std::ostream& operator<<(std::ostream& out, const Board& obj)
{
	// make the spaces above
	for (size_t it{ 0 }; it < g_consoleLines; it++)
	{
		out << '\n';
	}

	// print the board
	for (size_t it{ 0 }; it < 4; it++)
	{
		for (size_t it_i{ 0 }; it_i < 4; it_i++)
		{
			out << obj.m_game[it][it_i];
		}

		out << '\n';
	}

	return out;
}

bool operator==(const Board& board1, const Board& board2)
{
	for (int it{ 0 }; it < board1.SIZE; it++)
	{
		for (int it_i{ 0 }; it_i < board1.SIZE; it_i++)
		{
			// if one of the tile is not the same it returns false
			if (board1.m_game[it][it_i] != board2.m_game[it][it_i])
				return false;
		}
	}

	return true;
}

bool Board::isPointValid(const Point& point)
{
	return (point.posX >= 0 && point.posX < SIZE) && (point.posY >= 0 && point.posY < SIZE);
}

Point Board::findEmpty()
{
	for (int it{ 0 }; it < SIZE; it++)
	{
		for (int it_i{ 0 }; it_i < SIZE; it_i++)
		{
			if (m_game[it][it_i].isEmpty())
			{
				return Point{ it_i, it };
			}
		}
	}
}

void Board::swapTiles(Point& pt1, Point& pt2)
{
	// swap 2 element
	std::swap(m_game[pt1.posY][pt1.posX], m_game[pt2.posY][pt2.posX]);
}

// returns true if user moved successfully
bool Board::moveTile(Direction dir)
{
	Point emptyTile{ findEmpty() };
	Point adj{ emptyTile.getAdjacentPoint(-dir) };

	if (!isPointValid(adj))
		return false;

	swapTiles(adj, emptyTile);
	return true;
}

void Board::randomize()
{
	for (int it{0}; it < 1000; it++)
	{
		Board::moveTile(Direction::getRandomDirection());
	}
}

bool Board::playerWon()
{
	return *this == Board{};
}