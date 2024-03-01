#include "MateriaSource.hpp"
#include <iostream>

MateriaSource::MateriaSource()
{
	for (int i = 0; i < MAX_MATERIAS; ++i)
	{
		_inventory[i] = NULL;
	}
}

MateriaSource::MateriaSource(const MateriaSource &src)
{
	for (int i = 0; i < MAX_MATERIAS; ++i)
	{
		if (src._inventory[i])
			_inventory[i] = src._inventory[i]->clone();
		else
			_inventory[i] = NULL;
	}
}
// Using here another denominator for parameter name. Normally I have src or other. Here I have rhs.
MateriaSource &MateriaSource::operator=(const MateriaSource &rhs)
{
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
	return *this;
}

MateriaSource::~MateriaSource()
{
	for (int i = 0; i < MAX_MATERIAS; ++i)
	{
		if (_inventory[i])
			delete _inventory[i];
	}
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
			// std::cout << "Materia \"learned\". Whatever this means!" << std::endl;
			return;
		}
	}
	std::cout << "Inventory is full. Cannot learn more Materias." << std::endl;
}

// We are just returning a clone of the Materia that is in the inventory. If the Materia is not found, we return NULL.
AMateria *MateriaSource::createMateria(std::string const &type)
{
	for (int i = 0; i < MAX_MATERIAS; ++i)
	{
		if (_inventory[i] && _inventory[i]->getType() == type)
		{
			// std::cout << "Materia " << type << " created." << std::endl;
			return _inventory[i]->clone();
		}
	}
	std::cout << "Materia " << type << " not found." << std::endl;
	return NULL;
}
