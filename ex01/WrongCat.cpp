#include "WrongCat.hpp"
#include "WrongAnimal.hpp"

#include <iostream>

WrongCat::WrongCat()
{
	WrongAnimal::setType("WrongCat");
	std::cout << "WrongCat default constructor called" << std::endl;
}
WrongCat::WrongCat(const WrongCat &source) : WrongAnimal(source)
{
	std::cout << "WrongCat copy constructor called" << std::endl;
}
WrongCat &WrongCat::operator=(const WrongCat &source)
{
	std::cout << "WrongCat assignment operator called" << std::endl;
	if (this != &source)
	{
		WrongAnimal::operator=(source);
	}
	return *this;
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat destructor called" << std::endl;
}