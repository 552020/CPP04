#include "AMateria.hpp"

AMateria::AMateria() : _type("amateria")
{
}
AMateria::AMateria(std::string const &type) : _type(type)
{
}
AMateria::AMateria(AMateria const &src) : _type(src._type)
{
}
AMateria &AMateria::operator=(AMateria const &src)
{
	if (this != &src)
		_type = src._type;
	return *this;
}
AMateria::~AMateria()
{
}

std::string const &AMateria::getType() const
{
	return _type;
}
void AMateria::use(ICharacter &target)
{
	std::cout << this->_type << " shoots some materia at " << target.getName() << std::endl;
	std::cout << "The materia does nothing!" << std::endl;
	std::cout << "We don't know what an 'raw' materia is, and if a character can shoot it!" << std::endl;
	std::cout << "But since since this is not a pure virtual function, we have to implement it!" << std::endl;
}