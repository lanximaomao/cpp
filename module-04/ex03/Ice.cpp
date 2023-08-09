#include <iostream>
#include "Ice.hpp"
#include "Color.hpp"

Ice::Ice()
: AMateria("ice")
{
	//std::cout << "ice constructor called\n";
}

Ice::Ice(const Ice& other)
: AMateria("ice")
{
	*this = other;
}

Ice& Ice::operator=(const Ice& other)
{
	if (this != &other)
	{
		_type = other._type;
	}
	return (*this);
}

Ice::~Ice()
{
	//std::cout << "ice destructor called\n";
}

// make a deep copy
Ice* Ice::clone() const
{
	std::cout << "cloning ice\n";
	return(new Ice());
}

void Ice::use(ICharacter &target)
{
	std::cout << COLOR_RED;
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
	std::cout << COLOR_RESET;
}

