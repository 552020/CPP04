#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include "IMateriaSource.hpp"
#include "AMateria.hpp"

class MateriaSource : public IMateriaSource
{
  private:
	static const int MAX_MATERIAS = 4;
	AMateria *_inventory[MAX_MATERIAS]; // Inventory of learned Materias

  public:
	MateriaSource();
	MateriaSource(const MateriaSource &src);
	MateriaSource &operator=(const MateriaSource &rhs);
	virtual ~MateriaSource();
	// learnMateira is the laboratory where the MateriaSource learns a new Materia
	virtual void learnMateria(AMateria *);
	virtual AMateria *createMateria(std::string const &type);
};

#endif
