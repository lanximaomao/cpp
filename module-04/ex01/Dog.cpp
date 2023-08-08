#include <iostream>
#include "Animal.hpp"
#include "Dog.hpp"
#include "Color.hpp"

Dog::Dog(): Animal()
{
	std::cout << "Dog constructor called\n";
	_type = "Dog";
	_name = "mysterious";
}

Dog::Dog(const std::string name): Animal(name)
{
	std::cout << "Dog constructor called with a name\n";
	_type = "Dog";
	_name = name;
}

Dog::Dog(const Dog &other): Animal(other._name)
{
	std::cout << "Dog copy constructor called\n";
	*this = other;
}

Dog& Dog::operator=(const Dog &other)
{
	std::cout << "Dog copy assignment operator called\n";
	if (this != &other)
	{
		_name = other._name;
		_type = other._type;
	}
	return (*this);
}

Dog::~Dog()
{
	std::cout << "Dog " << _name << " deconstructor called\n";
}

void Dog::makeSound() const
{
	std::cout << COLOR_RED;
	std::cout << _type << " " << _name << " : Haw Haw Haw ~~~ \n";
	std::cout << COLOR_RESET;
}
