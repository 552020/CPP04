#include "Character.hpp"
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
	copyInventory(other);
}

Character &Character::operator=(const Character &other)
{
	if (this != &other)
	{
		_name = other._name;
		for (int i = 0; i < _inventorySize; ++i)
		{
			delete _inventory[i]; // Clean up existing _inventory
			_inventory[i] = NULL;
		}
		copyInventory(other);
	}
	return *this;
}

Character::~Character()
{
	for (int i = 0; i < _inventorySize; ++i)
	{
		delete _inventory[i];
	}
}

std::string const &Character::getName() const
{
	return _name;
}

void Character::equip(AMateria *m)
{
	for (int i = 0; i < _inventorySize; ++i)
	{
		if (_inventory[i] == NULL)
		{
			_inventory[i] = m;
			break;
		}
	}
}

void Character::unequip(int idx)
{
	if (idx >= 0 && idx < _inventorySize)
	{
		_inventory[idx] = NULL; // Just remove from _inventory without deleting
	}
}

void Character::use(int idx, ICharacter &target)
{
	if (idx >= 0 && idx < _inventorySize && _inventory[idx] != NULL)
	{
		_inventory[idx]->use(target);
	}
}

void Character::copyInventory(const Character &other)
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
