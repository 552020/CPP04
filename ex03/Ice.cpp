#include "Ice.hpp"

Ice::Ice() : AMateria("ice")
{
}
Ice::Ice(Ice const &src) : AMateria("ice")
{
	*this = src;
}
Ice &Ice::operator=(Ice const &src)
{
	if (this != &src)
	{
		AMateria::operator=(src);
		_type = src._type;
	}
	return *this;
}
AMateria *Ice::clone() const
{
	AMateria *clone = new Ice();
	return clone;
}
void Ice::use(ICharacter &target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
Ice::~Ice()
{
}