#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

#include <iostream>

int main() {
  const int nbrCatsAndDogs = 10;
  // Note 1
  Animal *animals[nbrCatsAndDogs];
  for (int i = 0; i < nbrCatsAndDogs; i++) {
    if (i % 2 == 0)
      animals[i] = new Cat();
    else
      animals[i] = new Dog();
  }
  // Demonstrating deep copy for Dog
  Dog dog1;
  dog1.getBrain()->setIdea("Idea 1");
  Dog dog2(dog1);
  dog2.getBrain()->setIdea("Idea 2");
  std::cout << "Dog 1 ideas: " << std::endl;
  for (int i = 0; i < 100; i++)
    std::cout << dog1.getBrain()->getIdeas()[i] << std::endl;
  std::cout << "Dog 2 ideas: " << std::endl;
  for (int i = 0; i < 100; i++)
    std::cout << dog2.getBrain()->getIdeas()[i] << std::endl;

  // Clean up and call the appropriate destructors
  for (int i = 0; i < nbrCatsAndDogs; i++)
    delete animals[i];

  //   const Animal *meta = new Animal();
  //   const Animal *j = new Dog();
  //   const Animal *i = new Cat();

  //   const WrongAnimal *meta2 = new WrongAnimal();
  //   const WrongAnimal *j2 = new WrongCat();

  //   std::cout << j->getType() << " " << std::endl; // will output the dog's
  //   type std::cout << i->getType() << " " << std::endl; // will output the
  //   cat's type i->makeSound();                                // will output
  //   the cat sound! j->makeSound(); meta->makeSound();

  //   std::cout << j2->getType() << " " << std::endl; // will output the dog's
  //   type j2->makeSound(); std::cout << meta2->getType() << " "
  //             << std::endl; // will output the cat's type
  //   meta2->makeSound();

  return (0);
}

/* Note 1
A pointer to the base class can point to a derived class object.
*/