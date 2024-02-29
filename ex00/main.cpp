#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

#include <iostream>

int main()
{
	const Animal *meta = new Animal();
	const Animal *j = new Dog();
	const Animal *i = new Cat();

	const WrongAnimal *meta2 = new WrongAnimal();
	const WrongAnimal *j2 = new WrongCat();

	std::cout << j->getType() << " " << std::endl; // will output the dog's type
	std::cout << i->getType() << " " << std::endl; // will output the cat's type
	i->makeSound();								   // will output the cat sound!
	j->makeSound();
	meta->makeSound();

	std::cout << j2->getType() << " " << std::endl; // will output the dog's type
	j2->makeSound();
	std::cout << meta2->getType() << " " << std::endl; // will output the cat's type
	meta2->makeSound();

	return (0);
}