#include "Cat.hpp"
#include <iostream>

Cat::Cat() : Animal("Cat")
{
	std::cout << "Cat default constructor called" << std::endl;
	brain = new Brain();
}
// Copy constructor
Cat::Cat(const Cat &source) : Animal(source)
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
		Animal::operator=(source);
		delete brain;
		brain = new Brain(*source.brain);
	}
	return *this;
}

Cat::~Cat()
{
	delete brain;
	std::cout << "Cat destructor called" << std::endl;
}

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