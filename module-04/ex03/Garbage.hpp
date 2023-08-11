#ifndef GARBAGE_HPP
# define GARBAGE_HPP

#include "AMateria.hpp"

class Garbage
{
	private:
		AMateria*	_materia_list;

	public:
		Garbage();
		Garbage(Garbage &other);
		Garbage* operator=(Garbage* other);
		~Garbage();

		void		pushBack(AMateria& material);
		void		_deleteList();
};

#endif
