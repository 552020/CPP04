#include "Dog.hpp"

#include <iostream>

Dog::Dog()
{
	type = "Dog";
	std::cout << "Dog default constructor called" << std::endl;
}
Dog::Dog(const Dog &source) : Animal(source)
{
	// we don't need to specify the type here, because it's already done in the base class. The type is copied from the
	// base class, and since the base class is already initialized with a "Dog" type, we don't need to do it again here.
	std::cout << "Dog copy constructor called" << std::endl;
}
Dog &Dog::operator=(const Dog &source)
{
	Animal::operator=(source);
	std::cout << "Dog assignment operator called" << std::endl;
	if (this != &source)
	{
		this->type = source.type;
	}
	return *this;
}

Dog::~Dog()
{
	std::cout << "Dog destructor called" << std::endl;
}

void Dog::makeSound() const
{
	std::cout << "Bau Bau" << std::endl;
}
