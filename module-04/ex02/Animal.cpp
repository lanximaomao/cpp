#include <iostream>
#include "Color.hpp"
#include "Animal.hpp"

Animal::Animal(): _type("Animal"), _name("Animal")
{
	std::cout << "Animal constructor called\n";
}

Animal::Animal(const std::string name)
: _type("Animal")
, _name(name)
{
	std::cout << "Animal constructor called with a name\n";
}

Animal::Animal(const Animal &other)
{
	std::cout << "Animal copy constructor called\n";
	*this = other;
}

// so the virtual keyword cannot be here
Animal::~Animal()
{
	std::cout << "Animal deconstructed\n";
}

Animal& Animal::operator=(const Animal& other)
{
	if (this != &other)
	{
		_name = other._name;
		_type = other._type;
	}
	return (*this);
}

std::string Animal::getName() const
{
	return (_name);
}

std::string Animal::getType() const
{
	return (_type);
}

//void Animal::makeSound() const
//{
//	std::cout << COLOR_BLUE;
//	std::cout << _type << " " << _name << " : what sound should I make? \n";
//	std::cout << COLOR_RESET;
//}

