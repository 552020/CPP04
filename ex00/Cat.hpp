#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"

class Cat : public Animal
{
  public:
	Cat();
	Cat(const Cat &source);
	Cat &operator=(const Cat &source);
	virtual ~Cat();
	virtual void makeSound() const;
};

#endif