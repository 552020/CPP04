
#include <iostream>
#include "ICharacter.hpp"
#include "Debug.hpp"

ICharacter::~ICharacter()
{
	Debug::log("An ICharacter object has been destroyed.", Debug::OCF);
}
