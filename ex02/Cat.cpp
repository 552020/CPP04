#include "Cat.hpp"
#include <iostream>

// Default constructor
Cat::Cat() : AAnimal("Cat")
{
	std::cout << "Cat default constructor called" << std::endl;
	brain = new Brain();
}
// Copy constructor
Cat::Cat(const Cat &source) : AAnimal(source)
{
	std::cout << "Cat copy constructor called" << std::endl;
	brain = new Brain(*source.brain);
}
// Assignment operator overload
Cat &Cat::operator=(const Cat &source)
{
	std::cout << "Cat assignment operator called" << std::endl;
	if (this != &source)
	{
		delete brain;
		brain = new Brain(*source.brain);
		this->type = source.type;
	}
	return *this;
}

// Destructor
Cat::~Cat()
{
	delete brain;
	std::cout << "Cat destructor called" << std::endl;
}

// Member functions
void Cat::makeSound() const
{
	std::cout << "Miao" << std::endl;
}
Brain *Cat::getBrain()
{
	return brain;
}
void Cat::setBrain(Brain *brain)
{
	if (this->brain)
		delete this->brain;
	this->brain = brain;
}