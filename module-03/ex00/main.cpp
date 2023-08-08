#include "ClapTrap.hpp"
#include "Color.hpp"
#include <iostream>

void print_status(ClapTrap &clapTrap)
{
	std::cout << clapTrap.getName()
		<< " health: "
		<< clapTrap.getHealth()
		<< " damage: "
		<< clapTrap.getDamage()
		<< " energy: "
		<< clapTrap.getEnergy()
		<< std::endl;
}

int main()
{
	std::cout << "\n\n===== ClapTrap =====\n\n";
	ClapTrap c1("apple");
	ClapTrap c2("banana");

	print_status(c1);

	// test member functions
	c1.attack("banana");
	c2.beRepaired(1);
	c2.take_damage(5);

	// c2 status after repair and damage
	print_status(c2);

	c2.take_damage(100);
	c2.beRepaired(100);

	// c2 status after damage and repair
	print_status(c2);
	return (0);
}

