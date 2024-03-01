#include "AAnimal.hpp"

#include <iostream>

AAnimal::AAnimal() : type("AAnimal")
{
	std::cout << "AAnimal default constructor called" << std::endl;
}
AAnimal::AAnimal(std::string type) : type(type)
{
	std::cout << "AAnimal type constructor called" << std::endl;
}

AAnimal::AAnimal(const AAnimal &source) : type(source.type)
{
	std::cout << "AAnimal copy constructor called" << std::endl;
}

AAnimal &AAnimal::operator=(const AAnimal &source)
{
	std::cout << "AAnimal assignment operator called" << std::endl;
	if (this != &source)
	{
		this->type = source.type;
	}
	return *this;
}

AAnimal::~AAnimal()
{
	std::cout << "AAnimal destructor called" << std::endl;
}

std::string AAnimal::getType() const
{
	return this->type;
}