#include "Brain.hpp"
#include <iostream>

// Default constructor
Brain::Brain()
{
	for (int i = 0; i < 100; i++)
		ideas[i] = "";
	std::cout << "Brain default constructor called" << std::endl;
}
// Copy constructor
Brain::Brain(const Brain &src)
{
	for (int i = 0; i < 100; i++)
		ideas[i] = src.ideas[i];
	std::cout << "Brain copy constructor called" << std::endl;
}
// Copy assignment operator
Brain &Brain::operator=(const Brain &src)
{
	for (int i = 0; i < 100; i++)
		ideas[i] = src.ideas[i];
	std::cout << "Brain copy assignment operator called" << std::endl;
	return *this;
}
// Destructor
Brain::~Brain()
{
	std::cout << "Brain destructor called" << std::endl;
}

void Brain::setIdea(std::string idea)
{
	for (int i = 0; i < 100; i++)
	{
		if (ideas[i] == "")
		{
			ideas[i] = idea;
			break;
		}
	}
}
std::string *Brain::getIdeas()
{
	return ideas;
}