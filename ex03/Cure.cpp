#include "Cure.hpp"

Cure::Cure() : Amateria("cure")
{
}
Cure::Cure(Cure const &src) : Amateria("cure")
{
	*this = src;
}
Cure &Cure::operator=(Cure const &src)
{
	if (this != &src)
		_type = src._type;
	return *this;
}

Amateria *Cure::clone() const
{
	Amateria *clone = new Cure();
	return clone;
}

void Cure::use(ICharacter &target)
{
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}

Cure::~Cure()
{
}