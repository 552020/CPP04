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
	std::cout << this->_type << " shoots an amateria at " << target.getName() << std::endl;
}