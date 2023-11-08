#include "Animal.hpp"

#include <iostream>

Animal::Animal() : type("Animal") {
  std::cout << "Animal default constructor called" << std::endl;
}
Animal::Animal(std::string type) : type(type) {
  std::cout << "Animal type constructor called" << std::endl;
}

Animal::Animal(const Animal &source) : type(source.type) {
  std::cout << "Animal copy constructor called" << std::endl;
}

Animal &Animal::operator=(const Animal &source) {
  std::cout << "Animal assignment operator called" << std::endl;
  if (this != &source) {
    this->type = source.type;
  }
  return *this;
}

Animal::~Animal() { std::cout << "Animal destructor called" << std::endl; }

std::string Animal::getType() const { return this->type; }