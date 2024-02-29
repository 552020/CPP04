#ifndef CURE_HPP
#define CURE_HPP

#include "Amateria.hpp"
#include "ICharacter.hpp"
#include <iostream>

class Cure : public Amateria
{
  public:
	Cure();
	Cure(Cure const &src);
	Cure &operator=(Cure const &src);
	virtual ~Cure();

	virtual Amateria *clone() const;
	virtual void use(ICharacter &target);
};

#endif