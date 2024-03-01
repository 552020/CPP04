#include "Character.hpp"
#include "AMateria.hpp"
#include "Debug.hpp"
#include <iostream>

Character::Character(const std::string &name) : _name(name)
{
	for (int i = 0; i < _inventorySize; ++i)
	{
		_inventory[i] = NULL;
	}
	std::string message = "A new Character " + name + " has been created with the constructor";
	Debug::log(message, Debug::OCF);
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
			std::string message = m->getType() + " has been equipped to " + _name;
			Debug::log(message, Debug::NORMAL);
			break;
		}
		i++;
	}
	if (i == _inventorySize)
	{
		std::string message = "Inventory is full! " + m->getType() + " has not been equipped to " + _name;
		Debug::log(message, Debug::NORMAL);
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
		std::string message = "Materia at index " + std::to_string(idx) + " has been unequipped.";
		Debug::log(message, Debug::NORMAL);
	}
	else
	{
		std::cout << "Invalid index." << std::endl;
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
	Debug::log("Deep copying inventory START", Debug::OCF);
	int j = 0;
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
		j++;
	}
	std::string message = "A new inventory has been created with " + std::to_string(j) + " materias.";
	Debug::log("Deep copying inventory END", Debug::OCF);
	Debug::log(message, Debug::OCF);
}
