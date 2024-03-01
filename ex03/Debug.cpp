#include "Debug.hpp"

// Initialize the static member variables
bool Debug::debugEnabled = false;				// Start with debugging turned off.
Debug::Level Debug::debugLevel = Debug::NORMAL; // Default level is NORMAL.

Debug::Debug()
{
}
Debug::Debug(const Debug &)
{
}
Debug &Debug::operator=(const Debug &)
{
	return *this;
}
Debug::~Debug()
{
}

// Enable or disable debugging.
void Debug::enable(bool on)
{
	debugEnabled = on;
}

// Set the debug level.
void Debug::setLevel(Debug::Level level)
{
	debugLevel = level;
}

// Log a message if conditions are met.
void Debug::log(const std::string &message, Debug::Level paramLevel)
{
	if (!debugEnabled)
	{
		return;
	}
	if (debugEnabled && (debugLevel >= paramLevel))
	{
		std::cout << message << std::endl;
	}
}
