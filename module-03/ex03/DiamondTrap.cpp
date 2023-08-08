#include <iostream>
#include "DiamondTrap.hpp"

// desired values are 100-50-30
// the inheritance should follow the order defined in hpp file
// the attribuates by default is from FragTrap
DiamondTrap::DiamondTrap(std::string name)
: ClapTrap(name + "_clap_name") // 10-10-0
, ScavTrap(name) // 100-50-20
, FragTrap(name) // 100-100-30
{
	std::cout << "DiamondTrap " << name << " created\n";
	//_health = FragTrap::_health;
	//_energy = ScavTrap::_energy;
	//_damage = FragTrap::_damage;

	//setHealth(FragTrap::_health);
	//setEnergy(ScavTrap::_energy);
	//setDamage(FragTrap::_damage);

	//FragTrap::_health = 100;
	//ScavTrap::_energy = 50;
	//ScavTrap::_damage = 30;

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

DiamondTrap& DiamondTrap::operator=(const DiamondTrap &other)
{
	std::cout << "DiamondTrap copy assignment operator called\n";
	if (this != &other)
	{
		_name = other._name;
		_health = other._health;
		_energy = other._energy;
		_damage = other._damage;
	}
	return (*this);
}

void DiamondTrap::whoAmI(void) const
{
	std::cout << "I am" << _name << "in DiamondTrap" << std::endl;
}


