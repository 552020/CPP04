#include "Cure.hpp"

Cure::Cure() : AMateria("cure")
{
}
Cure::Cure(Cure const &src) : AMateria("cure")
{
	*this = src;
}
Cure &Cure::operator=(Cure const &src)
{
	if (this != &src)
		AMateria::operator=(src);
	return *this;
}

AMateria *Cure::clone() const
{
	AMateria *newCure = new Cure();
	return newCure;
}

void Cure::use(ICharacter &target)
{
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}

Cure::~Cure()
{
}