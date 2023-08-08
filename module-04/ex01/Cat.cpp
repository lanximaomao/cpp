#include <iostream>
#include "Animal.hpp"
#include "Cat.hpp"
#include "Color.hpp"

Cat::Cat(): Animal()
{
	std::cout << "Cat constructor called\n";
	_type = "Cat";
	_name = "mysterious";
}

Cat::Cat(const std::string name): Animal(name)
{
	std::cout << "Cat constructor called with a name\n";
	_type = "Cat";
	_name = name;
}

Cat::Cat(const Cat &other): Animal(other._name)
{
	std::cout << "Cat copy constructor called\n";
	*this = other;
}

Cat& Cat::operator=(const Cat &other)
{
	std::cout << "Cat copy assignment operator called\n";
	if (this != &other)
	{
		_name = other._name;
		_type = other._type;
	}
	return (*this);
}

Cat::~Cat()
{
	std::cout << "Cat " << _name << " deconstructor called\n";
}

void Cat::makeSound() const
{
	std::cout << COLOR_BLUE;
	std::cout << _type << " " << _name << " : Miao Miao Miao ~~~\n";
	std::cout << COLOR_RESET;
}
