#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <string>

class Animal
{
  protected:
	std::string type;

  public:
	Animal();
	Animal(std::string type);
	Animal(const Animal &source);
	Animal &operator=(const Animal &source);
	virtual ~Animal();
	std::string getType() const;
	// Note 1
	virtual void makeSound() const = 0;
};

#endif
/* Note 1
Making a function pure virtual is done by adding = 0 to the end of its, this
will make the class abstract. That means that the class cannot be instantiated,
but it can be used as a base class. This is useful when you want to create a
class that has a function that must be implemented by the derived class, but you
don't want to implement it in the base class. In this case, the derived class
must implement the function, or it will also be abstract.
*/