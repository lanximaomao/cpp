#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP
#include "IMateriaSource.hpp"
#include "Cure.hpp"
#include "Ice.hpp"

class MateriaSource: public IMateriaSource
{
	private:
		AMateria* _materials[4];

	public:
		MateriaSource();
		MateriaSource(const MateriaSource& other);
		virtual MateriaSource& operator=(const MateriaSource &other);
		virtual ~MateriaSource();

		virtual void learnMateria(AMateria* other);
		virtual AMateria* createMateria(std::string const & type);
};

#endif

