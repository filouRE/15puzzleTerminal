#pragma once
#include "pch.h"
#include "Tile.h"
#include "Point.h"

// global
constexpr int g_consoleLines{ 25 };

class Board
{
public:
	Board() = default;

	friend std::ostream& operator<<(std::ostream& out, const Board& obj);
	friend bool operator==(const Board& board1, const Board& board2);

	static bool isPointValid(const Point& point);
	Point findEmpty();
	void swapTiles(Point& one, Point& second);
	bool moveTile(Direction dir);
	void randomize();
	bool playerWon();

private:
	static constexpr int SIZE = 4;
	Tile m_game[SIZE][SIZE]{
	   Tile{ 1 }, Tile { 2 }, Tile { 3 } , Tile { 4 },
	   Tile { 5 } , Tile { 6 }, Tile { 7 }, Tile { 8 },
	   Tile { 9 }, Tile { 10 }, Tile { 11 }, Tile { 12 },
	   Tile { 13 }, Tile { 14 }, Tile { 15 }, Tile { 0 } };
};