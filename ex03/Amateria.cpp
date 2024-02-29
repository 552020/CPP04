#include "Amateria.hpp"

Amateria::Amateria() : _type("default type")
{
}
Amateria::Amateria(std::string const &type) : _type(type)
{
}
Amateria::Amateria(Amateria const &src) : _type(src._type)
{
}
Amateria &Amateria::operator=(Amateria const &src)
{
	if (this != &src)
		_type = src._type;
	return *this;
}
Amateria::~Amateria()
{
}

std::string Amateria::const &getType() const
{
	return _type;
}
void Amateria::use(ICharacter &target)
{
	std::cout << this._name << " shoots an ice bolt at " << target.getName() << std::endl;
}