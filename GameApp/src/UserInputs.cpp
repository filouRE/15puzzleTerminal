#include "pch.h"
#include "UserInput.h"

char UserInput::getCommandFromUser()
{
	char character{};

	while (tolower(character) != 'q')
	{
		Helpers::checkInputBuffer();

		std::cin >> character;
		Helpers::ignoreLine();

		switch (character)
		{
		case 'w':
		case 'a':
		case 'd':
		case 's':
		case 'q':
			return character;
		default:
			continue;
		}
	}
}

Direction::Type UserInput::convertToType(const char input)
{
	switch (tolower(input))
	{
	case 'w':
		return Direction::up;
	case 'a':
		return Direction::left;
	case 'd':
		return Direction::right;
	case 's':
		return Direction::down;
	default:
		break;
	}
}