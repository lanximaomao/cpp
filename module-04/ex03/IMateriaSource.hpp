#ifndef IMATERIASOURCE_HPP
# define IMATERIASOURCE_HPP
#include <string>
#include "AMateria.hpp"

class IMateriaSource
{
	private:

	public:
		virtual ~IMateriaSource() {}
		virtual void learnMateria(AMateria*) = 0;
		virtual AMateria* createMateria(std::string const & type) = 0;
		//virtual AMateria* getReceipt(int i) const = 0;
};

#endif
