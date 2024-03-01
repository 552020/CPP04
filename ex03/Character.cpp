#include "Character.hpp"
#include "AMateria.hpp"
#include <iostream>

Character::Character(const std::string &name) : _name(name)
{
	for (int i = 0; i < _inventorySize; ++i)
	{
		_inventory[i] = NULL;
	}
}

Character::Character(const Character &other) : _name(other._name)
{
	deepCopyInventory(other);
}

Character &Character::operator=(const Character &other)
{
	if (this != &other)
	{
		_name = other._name;
		for (int i = 0; i < _inventorySize; ++i)
		{
			if (_inventory[i] != NULL)
			{
				delete _inventory[i];
				_inventory[i] = NULL;
			}
		}
		deepCopyInventory(other);
	}
	return *this;
}

Character::~Character()
{
	for (int i = 0; i < _inventorySize; ++i)
	{
		if (_inventory[i] != NULL)
		{
			delete _inventory[i];
			_inventory[i] = NULL;
		}
	}
}

std::string const &Character::getName() const
{
	return _name;
}

void Character::equip(AMateria *m)
{
	int i = 0;
	while (i < _inventorySize)
	{
		if (_inventory[i] == NULL)
		{
			_inventory[i] = m;
			// std::cout << m->getType() << "has been equipped to " << _name << std::endl;
			break;
		}
		i++;
	}
	if (i == _inventorySize)
	{
		// std::cout << "Inventory is full! " << m->getType() << "has not been equippd to " << _name << std::endl;
	}
}

void Character::unequip(int idx)
{
	if (idx >= 0 && idx < _inventorySize)
	{
		_inventory[idx] = NULL;
		// Just remove from _inventory without deleting
		// But we need to keep track of it to we can delete it in the destructor
		// This will happen automatically when the Character is destroyed?
		// No.
		// But this will happen automatically when the Materia is destroyed?
		// No, cause AMateria has to be manually created and destroyed.
		// There can be the case that a Character is destroyed, and therefore also the Materia in its inventory.
		// So before deleting the Materia, we need to check if it is not NULL.
	}
}

void Character::use(int idx, ICharacter &target)
{
	if (idx >= 0 && idx < _inventorySize)
		if (_inventory[idx] != NULL)
			_inventory[idx]->use(target);
		else
			std::cout << "No materia at that index " << idx << "." << std::endl;
	else
		std::cout << "Invalid index." << std::endl;
}

void Character::deepCopyInventory(const Character &other)
{
	for (int i = 0; i < _inventorySize; ++i)
	{
		if (other._inventory[i] != NULL)
		{
			_inventory[i] = other._inventory[i]->clone();
		}
		else
		{
			_inventory[i] = NULL;
		}
	}
}
