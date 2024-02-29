#ifndef ICE_HPP
#define ICE_HPP

#include "Amateria.hpp"
#include "ICharacter.hpp"

class Ice : public Amateria
{
  public:
	Ice();
	Ice(Ice const &src);
	Ice &operator=(Ice const &src);
	virtual ~Ice();

	virtual Amateria *clone() const;
	virtual void use(ICharacter &target);
};

#endif