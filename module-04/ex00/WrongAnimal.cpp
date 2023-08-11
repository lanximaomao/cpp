#include <iostream>
#include "WrongAnimal.hpp"
#include "Color.hpp"

WrongAnimal::WrongAnimal(): _type("WrongAnimal")
{
	std::cout << "WrongAnimal constructor called\n";
}

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
		_type = other._type;
	}
	return (*this);
}

std::string WrongAnimal::getType() const
{
	return (_type);
}

void WrongAnimal::makeSound() const
{
	std::cout << COLOR_CYAN;
	std::cout << _type << " " << " : Wrong Wrong Wrong ~~~\n";
	std::cout << COLOR_RESET;
}
