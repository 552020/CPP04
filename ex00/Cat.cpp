#include "Cat.hpp"
#include <iostream>

// Default constructor
Cat::Cat() : Animal("Cat") {
  std::cout << "Cat default constructor called" << std::endl;
}
// Copy constructor
Cat::Cat(const Cat &source) : Animal(source) {
  std::cout << "Cat copy constructor called" << std::endl;
}
// Assignment operator overload
Cat &Cat::operator=(const Cat &source) {
  std::cout << "Cat assignment operator called" << std::endl;
  if (this != &source) {
    this->type = source.type;
  }
  return *this;
}

// Destructor
Cat::~Cat() { std::cout << "Cat destructor called" << std::endl; }

// Member functions
void Cat::makeSound() const { std::cout << "Miao" << std::endl; }