#include "MateriaSource.hpp"
#include "Character.hpp"
#include "Debug.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "AMateria.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

void test_debug()
{
	Debug::enable(true);
	Debug::setLevel(Debug::NORMAL);

	// This will be logged
	Debug::log("This is a NORMAL message.", Debug::NORMAL);
	// This will not be logged
	Debug::log("This is a OCF message.", Debug::OCF);

	Debug::setLevel(Debug::OCF);
	// This will be logged
	Debug::log("This is a NORMAL message.", Debug::NORMAL);
	// This will be logged
	Debug::log("This is a OCF message.", Debug::OCF);

	Debug::enable(false);
	// This will not be logged
	Debug::log("This is a NORMAL message.", Debug::NORMAL);
	// This will not be logged
	Debug::log("This is a OCF message.", Debug::OCF);
}

void test_amateria()
{
	std::cout << "Amateria is an abstract class, so we can't create an instance of it.\n";
	std::cout << "Uncomment the code in the test_amateria function to see the error.\n";
	// AMateria *materia = new AMateria("test");
	// delete materia;
}

void test_Character()
{
	Debug::enable(true);
	Debug::setLevel(Debug::OCF);

	std::cout << "\nTesting Character functionalities\n" << std::endl;

	// TEST 1 - Testing Character constructor
	std::cout << "1. Testing Character constructor" << std::endl;
	std::cout << "\n***Character stroustrup(\"Stroustrup\");***" << std::endl;
	Character stroustrup("Stroustrup");

	std::cout << "\n***AMateria *ice = new Ice();***" << std::endl;
	AMateria *ice = new Ice();
	std::cout << "\n***AMateria *cure = new Cure();***" << std::endl;
	AMateria *cure = new Cure();

	// TEST 2 - Testing equip and unequip methods
	std::cout << "\n2. Testing equip and unequip methods" << std::endl;
	std::cout << "\n***stroustrup.equip(ice);***" << std::endl;
	stroustrup.equip(ice);
	std::cout << "\n***stroustrup.equip(cure);***" << std::endl;
	stroustrup.equip(cure);
	std::cout << "\n***stroustrup.unequip(0);***" << std::endl;
	stroustrup.unequip(0); // Unequip the first materia (ice)

	// TEST 3 - Testing use method
	std::cout << "\n3. Testing use method" << std::endl;
	std::cout << "\n***stroustrup.use(0, stroustrup);***" << std::endl;
	stroustrup.use(1, stroustrup); // Should use the cure materia on stroustrup

	// TEST 4 - Testing the copy constructor
	std::cout << "\n4. Testing the copy constructor" << std::endl;
	std::cout << "\n***Character stroustrupCopy(stroustrup);***" << std::endl;
	Character stroustrupCopy(stroustrup);

	// TEST 5 - Testing the assignment operator
	std::cout << "\n5. Testing the assignment operator" << std::endl;
	std::cout << "\n***Character stroustrupAssigned = stroustrup;***" << std::endl;
	Character stroustrupAssigned = stroustrup;

	std::cout << "\nTesting complete." << std::endl;
	std::cout << "Cleaning up..." << std::endl;
}

void test_MateriaSource()
{
	MateriaSource source;
	Debug::enable(true);
	Debug::setLevel(Debug::NORMAL);

	std::cout << "\nTesting MateriaSource functionalities\n" << std::endl;
	// TEST 1 - Testing learnMateria method
	std::cout << "1. Testing learnMateria method" << std::endl;

	// Learn Ice materia
	AMateria *ice = new Ice();
	std::cout << "\n***source.learnMateria(ice);***" << std::endl;
	source.learnMateria(ice);

	// Learn Cure materia
	AMateria *cure = new Cure();
	std::cout << "\n***source.learnMateria(cure);***" << std::endl;
	source.learnMateria(cure);

	// TEST 2 - Testing createMateria method
	std::cout << "\n2. Testing createMateria method" << std::endl;
	std::cout << "\n***source.createMateria(\"ice\");***" << std::endl;
	AMateria *createdIce = source.createMateria("ice");

	std::cout << "\n***source.createMateria(\"cure\");***" << std::endl;
	AMateria *createdCure = source.createMateria("cure");

	// TEST 3 - Testing inventory limit
	std::cout << "\n3. Testing invenotry limit" << std::endl;
	std::cout << "\n***source.learnMateria(new Ice());***" << std::endl;
	source.learnMateria(new Ice());
	std::cout << "\n***source.learnMateria(new Cure());***" << std::endl;
	source.learnMateria(new Cure());
	std::cout << "\n***source.learnMateria(new Ice());***" << std::endl;
	source.learnMateria(new Ice());

	// TEST 4 - Testing the OCF functionality
	std::cout << "\n4. Testing the copy constructor.\n" << std::endl;
	Debug::setLevel(Debug::OCF);
	std::cout << "\n***MateriaSource copiedSource(source);***" << std::endl;
	MateriaSource copiedSource(source);
	// We check if the inventory of the copied source is the same as the original source, i.e. if we can get back an Ice
	// materia
	std::cout << "\n***copiedSource.createMateria(\"ice\");***" << std::endl;
	AMateria *copiedIce = copiedSource.createMateria("ice");

	// TEST 5 - Testing the assignment operator
	std::cout << "\n5. Testing the assignment operator." << std::endl;
	std::cout << "\n***MateriaSource assignedSource = source;***" << std::endl;
	MateriaSource assignedSource;
	std::cout << "\n***assignedSource = source;***" << std::endl;
	assignedSource = source;
	std::cout << "\n***assignedSource.createMateria(\"cure\");***" << std::endl;
	AMateria *assignedCure = assignedSource.createMateria("cure");

	std::cout << "\nTesting complete." << std::endl;
	std::cout << "Cleaning up..." << std::endl;
	delete ice;
	delete cure;
	delete createdIce;
	delete createdCure;
	delete copiedIce;
	delete assignedCure;
}

void test_clone_random()
{
	// Seed the random number generator
	srand(static_cast<unsigned int>(time(NULL)));
	AMateria *materia = NULL;
	AMateria *clonedMateria = NULL;

	std::cout << "Testing clone functionality and polymorphism:" << std::endl;

	// Example using random choice
	// Randomly choose 0 (Ice) or 1 (Cure)
	int choice = rand() % 2;

	if (choice == 0)
	{
		std::cout << "Randomly selected Ice materia." << std::endl;
		materia = new Ice();
	}
	else
	{
		std::cout << "Randomly selected Cure materia." << std::endl;
		materia = new Cure();
	}

	clonedMateria = materia->clone();

	Character polyphemus("Polyphemus");
	std::cout << "Original materia use:" << std::endl;
	if (materia)
		materia->use(polyphemus);
	std::cout << "Cloned materia use:" << std::endl;
	if (clonedMateria)
		clonedMateria->use(polyphemus);

	delete materia;
	delete clonedMateria;
}

void test_clone_user_input()
{
	AMateria *materia = NULL;
	AMateria *clonedMateria = NULL;
	std::string userInput;
	while (userInput != "ice" && userInput != "cure")
	{

		std::cout << "Choose a materia type ('ice' or 'cure'): ";
		std::cin >> userInput;

		if (userInput == "ice")
			materia = new Ice();
		else if (userInput == "cure")
			materia = new Cure();
		else
			std::cout << "Invalid choice. Try again!" << std::endl;
	}

	clonedMateria = materia->clone();

	Character hero("Hero");
	if (materia)
		materia->use(hero);
	if (clonedMateria)
		clonedMateria->use(hero);

	delete materia;
	delete clonedMateria;
}

void test_ice()
{
	Debug::enable(true);
	Debug::setLevel(Debug::OCF);
	Character *pinguin = new Character("Pinguin");
	// Test default constructor
	Ice iceDefault;
	// Test constructor
	Ice ice = Ice();
	ice.use(*pinguin);
	// Test copy constructor
	Ice ice2;
	ice2.use(*pinguin);
	Ice ice3 = Ice(ice2);
	ice3.use(*pinguin);
	// Test copy assignment
	Ice ice4;
	ice4.use(*pinguin);
	ice4 = ice3;
	ice4.use(*pinguin);
	// Test destructor
	ice2.~Ice();
	// Test clone method

	// Clone the Ice materia using the clone method
	AMateria *icePtr = ice.clone();
	AMateria *clonedIce = icePtr->clone();

	// Using the cloned Ice materia
	clonedIce->use(*pinguin);
	delete clonedIce;
	delete pinguin;
}

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

	ICharacter *target = new Character("Villain");
	std::cout << "Hero uses his materias on Villain:\n";
	hero->use(0, *target);
	hero->use(1, *target);

	delete target;
	delete hero;
	delete src;
}