#include "Ice.hpp"
#include "Debug.hpp"

Ice::Ice() : AMateria("ice")
{
	Debug::log("A new Ice materia has been created with the constructor", Debug::OCF);
}
Ice::Ice(Ice const &src) : AMateria("ice")
{
	*this = src;
	Debug::log("A new Ice materia has been created with the copy constructor", Debug::OCF);
}
Ice &Ice::operator=(Ice const &src)
{
	if (this != &src)
		AMateria::operator=(src);
	Debug::log("Ice materia has been assigned with the assignment operator", Debug::OCF);
	return *this;
}
AMateria *Ice::clone() const
{
	AMateria *newIce = new Ice();
	Debug::log("A new Ice materia has been created with the clone method", Debug::NORMAL);
	return newIce;
}
void Ice::use(ICharacter &target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
Ice::~Ice()
{
	Debug::log("The Ice materia has been destroyed", Debug::OCF);
}