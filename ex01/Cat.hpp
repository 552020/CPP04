#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"
#include <string>

class Cat : public Animal
{
  private:
	Brain *brain;

  public:
	Cat();
	Cat(const Cat &source);
	Cat &operator=(const Cat &source);
	virtual ~Cat();
	virtual void makeSound() const;
	Brain *getBrain();
	void setBrain(Brain *brain);
};

#endif