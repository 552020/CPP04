#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include <string>

class Dog : public Animal {
public:
  Dog();
  Dog(const Dog &source);
  Dog &operator=(const Dog &source);
  virtual ~Dog();
  virtual void makeSound() const;
};

#endif