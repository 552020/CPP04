#include "Dog.hpp"

#include <iostream>

Dog::Dog() : Animal("Dog") {
  std::cout << "Dog default constructor called" << std::endl;
}
Dog::Dog(const Dog &source) : Animal(source) {
  std::cout << "Dog copy constructor called" << std::endl;
  type = source.type;
}
Dog &Dog::operator=(const Dog &source) {
  std::cout << "Dog assignment operator called" << std::endl;
  if (this != &source) {
    this->type = source.type;
  }
  return *this;
}

Dog::~Dog() { std::cout << "Dog destructor called" << std::endl; }

void Dog::makeSound() const { std::cout << "Bau Bau" << std::endl; }
