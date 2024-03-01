#ifndef AANIMAL_HPP
#define AANIMAL_HPP

#include <string>

// To make a class abstract and thus not instantiable directly, you need to declare at least one member function as a
// pure virtual function.
class AAnimal
{
  protected:
	std::string type;

  public:
	AAnimal();
	AAnimal(std::string type);
	AAnimal(const AAnimal &source);
	AAnimal &operator=(const AAnimal &source);
	virtual ~AAnimal();
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