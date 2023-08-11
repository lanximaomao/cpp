#include <iostream>
#include "Animal.hpp"
#include "Dog.hpp"
#include "Color.hpp"

Dog::Dog(): Animal()
{
	std::cout << "Dog constructor called\n";
	_type = "Dog";
}


Dog::Dog(const Dog &other): Animal()
{
	std::cout << "Dog copy constructor called\n";
	*this = other;
}

Dog& Dog::operator=(const Dog &other)
{
	std::cout << "Dog copy assignment operator called\n";
	if (this != &other)
	{
		_type = other._type;
	}
	return (*this);
}

Dog::~Dog()
{
	std::cout << "Dog " << " deconstructor called\n";
}

void Dog::makeSound() const
{
	std::cout << COLOR_RED;
	std::cout << _type << " " << " : Haw Haw Haw ~~~ \n";
	std::cout << COLOR_RESET;
}
