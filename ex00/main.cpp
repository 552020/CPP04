#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int main() {
  const Animal *meta = new Animal();
  const Animal *j = new Dog();
  const Animal *i = new Cat();

  std::cout << j->getType() << " " << std::endl; // will output the dog's type
  std::cout << i->getType() << " " << std::endl; // will output the cat's type
  i->makeSound();                                // will output the cat sound!
  j->makeSound();
  meta->makeSound();

  return (0);
}