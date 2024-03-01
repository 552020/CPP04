
#include <iostream>
#include "ICharacter.hpp"

ICharacter::ICharacter()
{
	// std::cout << "ICharacter default constructor called." << std::endl;
}

ICharacter::ICharacter(const ICharacter &)
{
	// std::cout << "ICharacter copy constructor called." << std::endl;
}

ICharacter &ICharacter::operator=(const ICharacter &)
{
	// std::cout << "ICharacter copy assignment operator called." << std::endl;
	return *this;
}

ICharacter::~ICharacter()
{
	// std::cout << "ICharacter destructor called." << std::endl;
}
