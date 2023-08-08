#ifndef AMATERIA_HPP
# define AMATERIA_HPP
#include <iostream>
#include <string>
#include "ICharacter.hpp"

class AMateria
{
	protected:
		std::string _type;

	public:
		AMateria(const std::string &type);
		AMateria(const AMateria &other);
		~AMateria();
		AMateria& operator=(const AMateria &other);

		// return the materia type
		std::string const &getType() const;

		virtual AMateria *clone() const = 0;
		virtual void use(ICharacter &target) = 0;
};

# endif
