#include <iostream>
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"
#include "Color.hpp"

void print_status(ClapTrap &clapTrap)
{
	std::cout << clapTrap.getName()
		<< " health: "
		<< clapTrap.getHealth()
		<< " energy: "
		<< clapTrap.getEnergy()
		<< " damage: "
		<< clapTrap.getDamage()
		<< std::endl;
}

int main()
{
	std::cout << "\n\n===== DiamondTrap =====\n\n";

	DiamondTrap f1("xx");
	print_status(f1);

	f1.attack("monster");
	print_status(f1);

	f1.takeDamage(10);
	print_status(f1);

	f1.beRepaired(20);
	print_status(f1);

	std::cout << "\n\n=== Inherited function ===\n\n";
	f1.guardGate();
	f1.highFivesGuys();

	std::cout << "\n\n=== its own member function ===\n\n";
	f1.whoAmI();

	return (0);
}



