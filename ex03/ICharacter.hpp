#ifndef ICHARACTER_HPP
#define ICHARACTER_HPP

#include <string>

// Forward declare AMateria to resolve the circular dependency instead of including AMateria.hpp.
class AMateria;

class ICharacter
{
  public:
	// to respect the orthodox canonical form
	ICharacter();
	ICharacter(const ICharacter &);
	ICharacter &operator=(const ICharacter &);
	// from the subject
	virtual ~ICharacter();
	virtual std::string const &getName() const = 0;
	virtual void equip(AMateria *m) = 0;
	virtual void unequip(int idx) = 0;
	virtual void use(int idx, ICharacter &target) = 0;
};

#endif