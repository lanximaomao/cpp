#include <iostream>
#include "Cure.hpp"
#include "Color.hpp"

Cure::Cure()
: AMateria("cure")
{
	std::cout << "cure constructor called\n";
}

Cure::Cure(const Cure& other)
:AMateria("cure")
{
	*this = other;
}

Cure& Cure::operator=(const Cure& other)
{
	if (this != &other)
	{
		_type = other._type;
	}
	return (*this);
}

Cure::~Cure()
{
	std::cout << "cure destructor called\n";
}

AMateria* Cure::clone() const
{
	return(new Cure(*this));
}

void Cure::use(ICharacter &target)
{
	std::cout << COLOR_BLUE;
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
	std::cout << COLOR_RESET;
}
