#include <iostream>
#include "Animal.hpp"
#include "Dog.hpp"
#include "Color.hpp"
#include "Brain.hpp"

Dog::Dog(): Animal()
{
	std::cout << "Dog constructor called\n";
	_type = "Dog";
	_name = "mysterious";
	_tinyBrain = new Brain();
}

Dog::Dog(const std::string name): Animal(name)
{
	std::cout << "Dog constructor called with a name\n";
	_type = "Dog";
	_name = name;
	_tinyBrain = new Brain();
}

Dog::Dog(const Dog &other): Animal(other._name)
{
	std::cout << "Dog copy constructor called\n";
	*this = other;
	_tinyBrain = new Brain();
}

// do i need to delete and recreate _tinyBrain?
Dog& Dog::operator=(const Dog &other)
{
	std::cout << "Dog copy assignment operator called\n";
	if (this != &other)
	{
		_name = other._name;
		_type = other._type;
		delete _tinyBrain;
		_tinyBrain = new Brain();
		// copy brain ideas
		for (size_t i = 0; i < 100; i++)
			_tinyBrain[i] = other._tinyBrain[i];
	}
	return (*this);
}

Dog::~Dog()
{
	std::cout << "Dog " << _name << " deconstructor called\n";
	delete _tinyBrain;
}

void Dog::makeSound() const
{
	std::cout << COLOR_RED;
	std::cout << _type << " " << _name << " : Haw Haw Haw ~~~ \n";
	std::cout << COLOR_RESET;
}

Brain* Dog::getBrain() const
{
	return (_tinyBrain);
}
