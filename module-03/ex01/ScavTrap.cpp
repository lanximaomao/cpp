#include <iostream>
#include "ScavTrap.hpp"
#include "Color.hpp"

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
		ClapTrap::operator=(other);
		_name = other._name;
	}
	return (*this);
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap " << _name << " destoryed\n";
}

void ScavTrap::attack(const std::string& target)
{
	if (_health <= 0 || _energy <= 0)
		return;
	_energy --;
	std::cout << COLOR_MAGENTA
		<< "ScavTrap " << _name << " attacks "
		<< target << ", causing " << _damage << " points of damage!\n"
		<< COLOR_RESET;
}

void ScavTrap::guardGate()
{
	std::cout << "ScavTrap " << _name << " is now in Gate keeper mode\n";
}
