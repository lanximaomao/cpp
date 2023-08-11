#include <iostream>
#include "Animal.hpp"
#include "Cat.hpp"
#include "Color.hpp"

Cat::Cat(): Animal()
{
	std::cout << "Cat constructor called\n";
	_type = "Cat";
}

Cat::Cat(const Cat &other): Animal()
{
	std::cout << "Cat copy constructor called\n";
	*this = other;
}

Cat& Cat::operator=(const Cat &other)
{
	std::cout << "Cat copy assignment operator called\n";
	if (this != &other)
	{
		_type = other._type;
	}
	return (*this);
}

Cat::~Cat()
{
	std::cout << "Cat " << " deconstructor called\n";
}

void Cat::makeSound() const
{
	std::cout << COLOR_BLUE;
	std::cout << _type << " " << " : Miao Miao Miao ~~~\n";
	std::cout << COLOR_RESET;
}
