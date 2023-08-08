#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP
#include <string>
#include "AMateria.hpp"
#include "IMateriaSource.hpp"
#include "Cure.hpp"
#include "Ice.hpp"

class MateriaSource: public IMateriaSource
{
	private:
		// What?
		std::string _receipt[4];


	public:
		MateriaSource();
		MateriaSource(const MateriaSource& other);
		virtual MateriaSource& operator=(const MateriaSource &other);
		virtual ~MateriaSource();

		// member function
		virtual void learnMateria(AMateria* other);
		virtual AMateria* createMateria(std::string const & type);
};

#endif

