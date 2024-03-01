#include "MateriaSource.hpp"
#include "Character.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include <iostream>

void test()
{
	// Create a materia source and teach it some materias
	IMateriaSource *src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	// Display a message to show what materias have been learned
	std::cout << "MateriaSource has learned Ice and Cure materias.\n";
	// We can't show the inventory of the MateriaSource, cause it's private. But we could add print statements.

	// Create a character named "Hero"
	ICharacter *hero = new Character("Hero");

	// Create and equip materias to "Hero"
	AMateria *tmp;
	tmp = src->createMateria("ice");
	if (tmp)
	{
		hero->equip(tmp);
		std::cout << "Hero has been equipped with Ice materia.\n";
	}

	tmp = src->createMateria("cure");
	if (tmp)
	{
		hero->equip(tmp);
		std::cout << "Hero has been equipped with Cure materia.\n";
	}

	// Attempt to create an unknown materia
	tmp = src->createMateria("fire");
	if (!tmp)
	{
		std::cout << "Fire materia is unknown and cannot be created.\n";
	}

	// Use the equipped materias
	ICharacter *target = new Character("Villain");
	std::cout << "Hero uses his materias on Villain:\n";
	hero->use(0, *target); // Use Ice
	hero->use(1, *target); // Use Cure

	// Clean up
	delete target;
	delete hero;
	delete src;

	std::cout << "System test completed.\n";
}

int main()
{
	IMateriaSource *src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	ICharacter *me = new Character("me");
	AMateria *tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	ICharacter *bob = new Character("bob");
	me->use(0, *bob);
	me->use(1, *bob);
	delete bob;
	delete me;
	delete src;

	return 0;
}