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
		AMateria::operator=(src);
	return *this;
}
AMateria *Ice::clone() const
{
	AMateria *newIce = new Ice();
	return newIce;
}
void Ice::use(ICharacter &target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
Ice::~Ice()
{
}