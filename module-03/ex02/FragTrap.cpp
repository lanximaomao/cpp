#include <iostream>
#include "FragTrap.hpp"

FragTrap::FragTrap(const std::string name):ClapTrap(name)
{
	std::cout << "FragTrap " << name << " created\n";
	_health = 100;
	_energy = 100;
	_damage = 30;
}

FragTrap::FragTrap(const FragTrap &other):ClapTrap(other.getName())
{
	std::cout << "FragTrap copy constructor called\n";
	*this = other;
}

FragTrap& FragTrap::operator=(const FragTrap &other)
{
	std::cout << "FragTrap copy assignment operator called\n";
	if (this != &other)
	{
		ClapTrap::operator=(other);
		_name = other._name;
	}
	return (*this);
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap "<< _name << " got destoryed\n";
}

void FragTrap::highFivesGuys(void)
{
	std::cout << "FragTrap " << _name << "says: have five!\n";
}

