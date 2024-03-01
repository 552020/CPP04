#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <iostream>
class WrongAnimal
{
  private:
	std::string type;

  public:
	WrongAnimal();
	WrongAnimal(const WrongAnimal &source);
	WrongAnimal &operator=(const WrongAnimal &source);
	virtual ~WrongAnimal();

	void makeSound() const;

	std::string getType() const;
	void setType(std::string type);
};

#endif
