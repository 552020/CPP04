#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP

#include "WrongAnimal.hpp"
class WrongCat : public WrongAnimal {
public:
  WrongCat();
  WrongCat(const WrongCat &source);
  WrongCat &operator=(const WrongCat &source);
  virtual ~WrongCat();
};

#endif