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
		AMateria* _receipt[4];
		AMateria* _garbage[1000];

	public:
		MateriaSource();
		MateriaSource(const MateriaSource& other);
		virtual MateriaSource& operator=(const MateriaSource &other);
		virtual ~MateriaSource();

		// member function
		virtual void learnMateria(AMateria* other);
		virtual AMateria* createMateria(std::string const & type);
		virtual AMateria* getReceipt(int i) const;
};

#endif

