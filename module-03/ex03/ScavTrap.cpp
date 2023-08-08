#include <iostream>
#include "ScavTrap.hpp"

// these private attributes are treated as protected in ClapTrap class
ScavTrap::ScavTrap(const std::string name): ClapTrap(name)
{
	std::cout << "ScavTrap " << name << " created\n";
	_health = 100;
	_energy = 50;
	_damage = 20;
}

ScavTrap::ScavTrap(const ScavTrap &other):ClapTrap(other._name)
{
	std::cout << "ScavTrap copy constructor called\n";
	*this = other;
}

ScavTrap& ScavTrap::operator=(const ScavTrap &other)
{
	std::cout << "ScavTrap copy assignment operator called\n";
	if (this != &other)
	{
		_name = other._name;
		_health = other._health;
		_energy = other._energy;
		_damage = other._damage;
	}
	return (*this);
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap " << _name << " destoryed\n";
}

void ScavTrap::guardGate()
{
	std::cout << "ScavTrap " << _name << " is now in Gate keeper mode\n";
}
