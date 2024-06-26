#ifndef DOG_HPP
#define DOG_HPP

#include "AAnimal.hpp"
#include "Brain.hpp"
#include <string>

class Dog : public AAnimal
{
  private:
	Brain *brain;

  public:
	Dog();
	Dog(const Dog &source);
	Dog &operator=(const Dog &source);
	virtual ~Dog();
	virtual void makeSound() const;
	Brain *getBrain();
	void setBrain(Brain *brain);
};

#endif