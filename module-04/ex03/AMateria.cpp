#include "AMateria.hpp"
#include <iostream>

AMateria::AMateria(std::string const &type)
: _type(type)
{
	std::cout << "AMateria constructor called\n";
	_next = NULL;
}

AMateria::AMateria(const AMateria& other)
{
	*this = other;
}

AMateria::~AMateria()
{
	std::cout << "AMateria destructor called\n";
}

AMateria& AMateria::operator=(const AMateria &other)
{
	std::cout << "AMateria copy assignment called\n";
	if (this != &other)
	{
		_type = other._type;
		_next = other._next;
	}
	return (*this);
}

const std::string& AMateria::getType() const
{
	return(_type);
}

void AMateria::use(ICharacter &target)
{
	std::cout << "at Amateria, are you sure you want to use?\n"
		<< target.getName() << std::endl;
}
