#include <iostream>
#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(std::string name)
: ClapTrap(name + "ClapTrap")
, ScavTrap(name)
, FragTrap(name)
, _name (name)
{
	std::cout << "DiamondTrap " << name << " created\n";
	_health = 100;
	_energy = 50;
	_damage = 30;
}

DiamondTrap::DiamondTrap(const DiamondTrap &other)
: ClapTrap(other._name + "_clap_name")
, ScavTrap(other._name)
, FragTrap(other._name)
{
	*this = other;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap "<< _name << " got destoryed\n";
}

// first copy the parent class and then update the derived class atrributes
DiamondTrap& DiamondTrap::operator=(const DiamondTrap &other)
{
	std::cout << "DiamondTrap copy assignment operator called\n";
	if (this != &other)
	{
		FragTrap::operator=(other);
		ScavTrap::operator=(other);
		_name = other._name;
	}
	return (*this);
}

void DiamondTrap::whoAmI(void) const
{
	std::cout << "I am " << _name << " in DiamondTrap. But, also I am "
		<< ClapTrap::_name << std::endl;
}


