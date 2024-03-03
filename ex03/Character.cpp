#include "Character.hpp"
#include "AMateria.hpp"
#include "Debug.hpp"
#include <iostream>
#include <sstream> // for std::ostringstream

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
		std::ostringstream oss;
		oss << "Materia at index " << idx << " has been unequipped.";
		std::string message = oss.str();

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
		{
			std::ostringstream oss;
			oss << "Materia at index " << idx << " is NULL.";
		}
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
	std::ostringstream oss;
	oss << "A new inventory has been created with " << j << " materias.";
	std::string message = oss.str();
	Debug::log("Deep copying inventory END", Debug::OCF);
	Debug::log(message, Debug::OCF);
}
