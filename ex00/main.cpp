#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

#include <iostream>

int main()
{
	std::cout << "---- Animal ----\n" << std::endl;
	std::cout << "***const Animal *meta = new Animal();***" << std::endl;
	const Animal *meta = new Animal();
	std::cout << "***const Animal *j = new Dog();***" << std::endl;
	const Animal *j = new Dog();
	std::cout << "***const Animal *i = new Cat();***" << std::endl;
	const Animal *i = new Cat();

	std::cout << "***std::cout << j->getType() << std::endl;***" << std::endl;
	std::cout << j->getType() << " " << std::endl;
	std::cout << "***i->getType() << std::endl;***" << std::endl;
	std::cout << i->getType() << " " << std::endl;
	std::cout << "***i->makeSound();***" << std::endl;
	i->makeSound();
	std::cout << "***j->makeSound();***" << std::endl;
	j->makeSound();
	std::cout << "***meta->makeSound();***" << std::endl;
	meta->makeSound();

	std::cout << "\n---- WrongAnimal ----\n" << std::endl;
	std::cout << "***const WrongAnimal *meta2 = new WrongAnimal();***" << std::endl;
	const WrongAnimal *meta2 = new WrongAnimal();
	std::cout << "***const WrongAnimal *j2 = new WrongCat();***" << std::endl;
	const WrongAnimal *i2 = new WrongCat();
	std::cout << "***const WrongAnimal *j3 = new WrongCat();***" << std::endl;
	const WrongCat *i3 = new WrongCat();

	std::cout << "***std::cout << j2->getType() << std::endl;***" << std::endl;
	std::cout << i2->getType() << " " << std::endl;
	std::cout << "***j2->makeSound();***" << std::endl;
	i2->makeSound();
	std::cout << "***meta2->makeSound();***" << std::endl;
	meta2->makeSound();
	std::cout << "***j3->makeSound();***" << std::endl;
	i3->makeSound();

	std::cout << "\n---- Small Extra Test ----\n" << std::endl;

	std::cout << "***const Animal *i4 = new Cat();***" << std::endl;
	const Cat *i4 = new Cat;
	std::cout << "***i4->makeSound();***" << std::endl;
	i4->makeSound();

	return (0);
}