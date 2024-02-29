#include "Ice.hpp"

Ice::Ice() : Amateria("ice")
{
}
Ice::Ice(Ice const &src) : Amateria("ice")
{
	*this = src;
}
Ice &Ice::operator=(Ice const &src)
{
	if (this != &src)
		_type = src._type;
	return *this;
}
Amateria *Ice::clone() const
{
	Amateria *clone = new Ice();
	return clone;
}
void Ice::use(ICharacter &target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
Ice::~Ice()
{
}