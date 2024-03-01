#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

#include <iostream>

#define ANIMALS_NBR 10

void printDogIdeas(Dog &dog)
{
	for (int i = 0; i < 100; i++)
	{
		std::string dogIdea = dog.getBrain()->getIdeas()[i];
		if (dogIdea != "")
			std::cout << dogIdea << std::endl;
	}
}

int main()
{
	const int nbrAnimals = ANIMALS_NBR;
	// Note 1
	Animal *animals[nbrAnimals];
	std::cout << "--- Creating " << nbrAnimals << " animals ---\n" << std::endl;
	for (int i = 0; i < nbrAnimals; i++)
	{
		if (i % 2 == 0)
			animals[i] = new Cat();
		else
			animals[i] = new Dog();
	}
	std::cout << "*** " << nbrAnimals << " animals created ***\n" << std::endl;
	// Demonstrating deep copy for Dog
	std::cout << "--- Demonstrating deep copy for Dog ---\n" << std::endl;
	std::cout << "Creating Dog 1 and setting an idea\n" << std::endl;
	Dog dog1;
	dog1.getBrain()->setIdea("Idea 1");
	std::cout << "\nCreating Dog 2 by copying Dog 1\n" << std::endl;
	Dog dog2(dog1);
	std::cout << "Dog 1 (just after copy) ideas: " << std::endl;
	printDogIdeas(dog1);
	std::cout << "Dog 2 (just after copy) ideas: " << std::endl;
	printDogIdeas(dog2);
	std::cout << "\nSetting new idea int Dog2's brain\n" << std::endl;
	dog2.getBrain()->setIdea("Idea 2");
	std::cout << "Dog 1 (after adding new idea to Dog2) ideas: " << std::endl;
	printDogIdeas(dog1);
	std::cout << "Dog 2 (after adding new idea to Dog2) ideas: " << std::endl;
	printDogIdeas(dog2);

	std::cout << "\n--- Cleaning up ---\n" << std::endl;
	for (int i = 0; i < nbrAnimals; i++)
		delete animals[i];

	return (0);
}
