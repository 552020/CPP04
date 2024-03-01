#include "Cure.hpp"
#include "Debug.hpp"

Cure::Cure() : AMateria("cure")
{
	Debug::log("A new Cure materia has been created with the constructor", Debug::OCF);
}
Cure::Cure(Cure const &src) : AMateria("cure")
{
	*this = src;
	Debug::log("A new Cure materia has been created with the copy constructor", Debug::OCF);
}
Cure &Cure::operator=(Cure const &src)
{
	if (this != &src)
		AMateria::operator=(src);
	Debug::log("Cure materia has been assigned with the assignment operator", Debug::OCF);
	return *this;
}

AMateria *Cure::clone() const
{
	AMateria *newCure = new Cure();
	Debug::log("A new Cure materia has been created with the clone method", Debug::NORMAL);
	return newCure;
}

void Cure::use(ICharacter &target)
{
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}

Cure::~Cure()
{
	Debug::log("The Cure materia has been destroyed", Debug::OCF);
}