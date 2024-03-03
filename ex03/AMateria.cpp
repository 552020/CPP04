#include "AMateria.hpp"
#include "Debug.hpp"

AMateria::AMateria() : _type("amateria")
{
	Debug::log("A new AMateria object has been created with the constructor.", Debug::OCF);
}
AMateria::AMateria(std::string const &type) : _type(type)
{
	Debug::log("A new AMateria object has been created with the parameterized constructor.", Debug::OCF);
}
AMateria::AMateria(AMateria const &src) : _type(src._type)
{
	Debug::log("A new AMateria object has been created with the copy constructor.", Debug::OCF);
}
AMateria &AMateria::operator=(AMateria const &src)
{

	if (this != &src)
		_type = src._type;
	Debug::log("AMateria object has been assigned with the assignment operator.", Debug::OCF);
	return *this;
}
AMateria::~AMateria()
{
	Debug::log("An AMateria object has been destroyed.", Debug::OCF);
}

std::string const &AMateria::getType() const
{
	return _type;
}
// This function is not pure virtual, so we have to implement it. We will never use it.
void AMateria::use(ICharacter &target)
{
	std::cout << "* " << this->_type << " shoots some materia at " << target.getName() << " *" << std::endl;
}