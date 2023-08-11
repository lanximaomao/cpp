#include <iostream>
#include "Animal.hpp"
#include "Cat.hpp"
#include "Brain.hpp"
#include "Color.hpp"

Cat::Cat(): Animal()
{
	std::cout << "Cat constructor called\n";
	_type = "Cat";
	_name = "mysterious";
	_tinyBrain = new Brain();
}

Cat::Cat(const std::string name): Animal(name)
{
	std::cout << "Cat constructor called with a name\n";
	_type = "Cat";
	_name = name;
	_tinyBrain = new Brain();
}

Cat::Cat(const Cat &other): Animal(other._name)
{
	std::cout << "Cat copy constructor called\n";
	_name = other._name;
	_type = other._type;
	_tinyBrain = new Brain(*other._tinyBrain);
}

Cat& Cat::operator=(const Cat &other)
{
	std::cout << "Cat copy assignment operator called\n";
	if (this != &other)
	{
		_name = other._name;
		_type = other._type;
		_tinyBrain = other._tinyBrain;
	}
	return (*this);
}

Cat::~Cat()
{
	std::cout << "Cat " << _name << " deconstructor called\n";
	delete _tinyBrain;
}

void Cat::makeSound() const
{
	std::cout << COLOR_BLUE;
	std::cout << _type << " " << _name << " : Miao Miao Miao ~~~\n";
	std::cout << COLOR_RESET;
}

Brain* Cat::getBrain() const
{
	return (_tinyBrain);
}
