#include <iostream>
#include "WrongAnimal.hpp"
#include "Color.hpp"

WrongAnimal::WrongAnimal(): _type("WrongAnimal"), _name("WrongAnimal")
{
	std::cout << "WrongAnimal constructor called\n";
}

WrongAnimal::WrongAnimal(const std::string name)
: _type("WrongAnimal")
, _name(name)
{
	std::cout << "WrongAnimal constructor called with a name\n";
}

// so the virtual keyword cannot be here
WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal deconstructed\n";
}

WrongAnimal::WrongAnimal(const WrongAnimal &other)
{
	std::cout << "Wrong animal copy constructor called\n";
	*this = other;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& other)
{
	if (this != &other)
	{
		_name = other._name;
		_type = other._type;
	}
	return (*this);
}

std::string WrongAnimal::getName() const
{
	return (_name);
}

std::string WrongAnimal::getType() const
{
	return (_type);
}

void WrongAnimal::makeSound() const
{
	std::cout << COLOR_CYAN;
	std::cout << _type << " " << _name << " : Wrong Wrong Wrong ~~~\n";
	std::cout << COLOR_RESET;
}
