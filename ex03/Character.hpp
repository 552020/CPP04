#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "ICharacter.hpp"

#define MAX_INVENTORY 4

class Character : public ICharacter
{
  private:
	std::string _name;
	static const int _inventorySize = MAX_INVENTORY;
	AMateria *_inventory[_inventorySize];

	// Helper function to deeply copy the inventory from another Character
	void copyInventory(const Character &other);

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