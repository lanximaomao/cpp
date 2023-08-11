#ifndef AMATERIA_HPP
# define AMATERIA_HPP
#include <string>
#include "ICharacter.hpp"

/*
** this is called forward declaration
** it's useful to solve mutual dependencies
** it provide a way to introduce names of entities
** before their full definitions
*/
class ICharacter;

class AMateria
{
	protected:
		std::string	_type;

	public:
		AMateria*	_next;
		AMateria(const std::string &type);
		AMateria(const AMateria &other);
		virtual ~AMateria();
		AMateria& operator=(const AMateria &other);


		const std::string& getType() const;
		virtual AMateria* clone() const = 0;
		virtual void use(ICharacter &target);
};

# endif
