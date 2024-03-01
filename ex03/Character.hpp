#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "ICharacter.hpp"

#define MAX_INVENTORY 4

class Character : public ICharacter
{
  private:
	std::string _name;
	// static in C++ means that the variable is shared between all instances of the class
	// the member belongs to the class, not to the instance
	static const int _inventorySize = MAX_INVENTORY;
	AMateria *_inventory[_inventorySize];

	// Extra helper function to deeply copy the inventory from another Character
	void deepCopyInventory(const Character &other);

  public:
	Character(std::string const &name);
	Character(Character const &src);
	Character &operator=(Character const &src);
	virtual ~Character();

	std::string const &getName() const;
	void equip(AMateria *m);
	void unequip(int idx);
	void use(int idx, ICharacter &target);
};

#endif