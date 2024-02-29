#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include <iostream>
#include <string>

class Amateria {
protected:
  std::string _type;

public:
  Amateria();
  Amateria(std::string const &type);
  Amateria(Amateria const &src);
  Amateria &operator=(Amateria const &src);
  virtual ~Amateria();

  std::string const &getType() const; // Returns the materia type
  virtual Amateria *clone() const = 0;
  virtual void use(ICharacter &target);
};

#endif