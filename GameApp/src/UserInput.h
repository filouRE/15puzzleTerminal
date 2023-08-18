#pragma once

#include "pch.h"
#include "Helpers.h"
#include "Direction.h"

namespace UserInput
{
	char getCommandFromUser();

	Direction::Type convertToType(const char input);
};