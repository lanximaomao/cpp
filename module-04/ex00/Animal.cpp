#include <iostream>
#include "Color.hpp"
#include "Animal.hpp"

Animal::Animal(): _type("Animal")
{
	std::cout << "Animal constructor called\n";
}

Animal::Animal(const Animal &other)
{
	std::cout << "Animal copy constructor called\n";
	*this = other;
}

Animal::~Animal()
{
	std::cout << "Animal deconstructed\n";
}

Animal& Animal::operator=(const Animal& other)
{
	if (this != &other)
	{
		_type = other._type;
	}
	return (*this);
}

std::string Animal::getType() const
{
	return (_type);
}

void Animal::makeSound() const
{
	std::cout << COLOR_BLUE;
	std::cout << _type << " " << " : what sound should I make? \n";
	std::cout << COLOR_RESET;
}

