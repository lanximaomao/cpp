#include <iostream>
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Color.hpp"

WrongCat::WrongCat(): WrongAnimal()
{
	std::cout << "WrongCat constructor called\n";
	_type = "WrongCat";
}

WrongCat::WrongCat(const WrongCat &other): WrongAnimal()
{
	std::cout << "WrongCat copy constructor called\n";
	*this = other;
}

WrongCat& WrongCat::operator=(const WrongCat &other)
{
	std::cout << "WrongCat copy assignment operator called\n";
	if (this != &other)
	{
		_type = other._type;
	}
	return (*this);
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat " << " deconstructor called\n";
}

void WrongCat::makeSound() const
{
	std::cout << COLOR_CYAN;
	std::cout << _type << " " << " : Wrong Miao Miao Miao ~~~\n";
	std::cout << COLOR_RESET;
}
