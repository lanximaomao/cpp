#ifndef CURE_HPP
# define CURE_HPP
#include <string>
#include "AMateria.hpp"
#include "ICharacter.hpp"

class Cure: public AMateria
{
	private:
		std::string _type; // init to cure
	public:
		Cure();
		Cure(const Cure& other);
		Cure& operator=(const Cure& other);
		~Cure();

		Cure* clone() const;
		void use(ICharacter &target);
};

#endif
