#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
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
	std::cout << "\n\n===== ScavTrap =====\n\n";

	ScavTrap s1("snake");
	print_status(s1);

	s1.attack("crazy frog");
	print_status(s1);

	s1.takeDamage(4);
	print_status(s1);

	s1.beRepaired(100);
	print_status(s1);

	s1.guardGate();

	return (0);
}

