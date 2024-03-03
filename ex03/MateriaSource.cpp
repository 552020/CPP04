#include "MateriaSource.hpp"
#include "Debug.hpp"
#include <iostream>

MateriaSource::MateriaSource()
{
	for (int i = 0; i < MAX_MATERIAS; ++i)
	{
		_inventory[i] = NULL;
	}
	Debug::log("A new MateriaSource has been created with the constructor", Debug::OCF);
}

MateriaSource::MateriaSource(const MateriaSource &src)
{
	Debug::log("COPY CONSTRUCTOR START!", Debug::OCF);
	for (int i = 0; i < MAX_MATERIAS; ++i)
	{
		if (src._inventory[i])
			_inventory[i] = src._inventory[i]->clone();
		else
			_inventory[i] = NULL;
	}
	Debug::log("COPY CONSTRUCTOR END!", Debug::OCF);
	Debug::log("A new MateriaSource has been created with the copy constructor", Debug::OCF);
}

// Using here another denominator for parameter name. Normally I have src or other. Here I have rhs.
MateriaSource &MateriaSource::operator=(const MateriaSource &rhs)
{
	Debug::log("ASSIGNMENT OPERATOR START!", Debug::OCF);
	if (this != &rhs)
	{
		for (int i = 0; i < MAX_MATERIAS; ++i)
		{
			if (_inventory[i] != NULL)
				delete _inventory[i];
			if (rhs._inventory[i])
				_inventory[i] = rhs._inventory[i]->clone();
			else
				_inventory[i] = NULL;
		}
	}
	Debug::log("ASSIGNMENT OPERATOR END!", Debug::OCF);
	Debug::log("MateriaSource has been assigned with the assignment operator", Debug::OCF);
	return *this;
}

MateriaSource::~MateriaSource()
{
	for (int i = 0; i < MAX_MATERIAS; ++i)
	{
		if (_inventory[i])
			delete _inventory[i];
	}
	Debug::log("The MateriaSource has been destroyed", Debug::OCF);
}

// This is the laboratory where the MateriaSource learns a new Materia, that means a Matria is cloned and stored in the
// inventory. The Materia passed is always of type Ice or Cure.
void MateriaSource::learnMateria(AMateria *m)
{
	for (int i = 0; i < MAX_MATERIAS; ++i)
	{
		if (!_inventory[i])
		{
			_inventory[i] = m->clone();
			Debug::log("Materia \"learned\". Whatever this means!", Debug::NORMAL);
			return;
		}
	}
	Debug::log("Inventory is full. Cannot learn more Materias.", Debug::NORMAL);
}

// We are just returning a clone of the Materia that is in the inventory. If the Materia is not found, we return NULL.
AMateria *MateriaSource::createMateria(std::string const &type)
{
	for (int i = 0; i < MAX_MATERIAS; ++i)
	{
		if (_inventory[i] && _inventory[i]->getType() == type)
		{
			Debug::log("Materia " + type + " created.", Debug::NORMAL);
			return _inventory[i]->clone();
		}
	}
	Debug::log("Materia " + type + " not found.", Debug::NORMAL);
	return NULL;
}
