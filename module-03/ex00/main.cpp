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
	print_status(c2);


	std::cout << "\n\n=== member function ===\n\n";
	c2.attack("apple");
	c2.beRepaired(1);
	c2.takeDamage(5);
	print_status(c2);

	c2.takeDamage(100);
	c2.beRepaired(100);

	print_status(c2);
	return (0);
}

