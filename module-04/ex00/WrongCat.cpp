#include <iostream>
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Color.hpp"

WrongCat::WrongCat(): WrongAnimal()
{
	std::cout << "WrongCat constructor called\n";
	_type = "WrongCat";
	_name = "mysterious";
}

WrongCat::WrongCat(const std::string name): WrongAnimal(name)
{
	std::cout << "WrongCat constructor called with a name\n";
	_type = "WrongCat";
	_name = name;
}

WrongCat::WrongCat(const WrongCat &other): WrongAnimal(other._name)
{
	std::cout << "WrongCat copy constructor called\n";
	*this = other;
}

WrongCat& WrongCat::operator=(const WrongCat &other)
{
	std::cout << "WrongCat copy assignment operator called\n";
	if (this != &other)
	{
		_name = other._name;
		_type = other._type;
	}
	return (*this);
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat " << _name << " deconstructor called\n";
}

void WrongCat::makeSound() const
{
	std::cout << COLOR_CYAN;
	std::cout << _type << " " << _name << " : Wrong Miao Miao Miao ~~~\n";
	std::cout << COLOR_RESET;
}
