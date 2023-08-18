#include "pch.h"
#include "Helpers.h"

void Helpers::ignoreLine()
{
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

void Helpers::checkInputBuffer()
{
	if (!std::cin) // has a previous extraction failed?
	{
		std::cin.clear(); // put us back in 'normal' operation mode
		ignoreLine(); // and remove the bad input
	}
}