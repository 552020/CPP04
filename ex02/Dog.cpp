#include "Dog.hpp"

#include <iostream>

Dog::Dog() : AAnimal("Dog")
{
	std::cout << "Dog default constructor called" << std::endl;
	brain = new Brain();
}
Dog::Dog(const Dog &source) : AAnimal(source)
{
	std::cout << "Dog copy constructor called" << std::endl;
	brain = new Brain(*source.brain);
	type = source.type;
}
Dog &Dog::operator=(const Dog &source)
{
	std::cout << "Dog assignment operator called" << std::endl;
	if (this != &source)
	{
		delete brain;
		brain = new Brain(*source.brain);
		this->type = source.type;
	}
	return *this;
}

Dog::~Dog()
{
	delete brain;
	std::cout << "Dog destructor called" << std::endl;
}

void Dog::makeSound() const
{
	std::cout << "Bau Bau" << std::endl;
}

Brain *Dog::getBrain()
{
	return brain;
}
void Dog::setBrain(Brain *brain)
{
	if (this->brain)
		delete this->brain;
	this->brain = brain;
}