#pragma once

#include "pch.h"
#include "Board.h"
#include "UserInput.h"
#include "Point.h"

void playPuzzle()
{
	Board board{};
	board.randomize();
	std::cout << board;

	std::cout << "Enter a command: ";
	while (true)
	{
		char ch{ UserInput::getCommandFromUser() };

		// Handle non-direction commands
		if (ch == 'q')
		{
			std::cout << "\n\nBye!\n\n";
			break;
		}

		// Handle direction commands
		Direction dir{ UserInput::convertToType(ch) };

		bool userMoved{ board.moveTile(dir) };
		if (userMoved)
			std::cout << board;
		if (board.playerWon())
		{
			std::cout << "\n\nYou won!\n\n";
			break;
		}
	}
}