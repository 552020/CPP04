#include "MateriaSource.hpp"
#include "Character.hpp"
#include "Debug.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "AMateria.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

void test_debug();
void test_amateria();
void test_Character();
void test_MateriaSource();
void test_clone_random();
void test_clone_user_input();
void test_ice();
void test();


int main()
{
	// test_debug();
	// test_ice();
	// test_clone_user_input();
	// test_clone_random();
	// test_MateriaSource();
	// test_Character();
	// test();

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