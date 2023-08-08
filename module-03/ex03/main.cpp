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

	DiamondTrap f1("Ah, diamond");
	print_status(f1);

	f1.attack("monster");
	print_status(f1);

	f1.take_damage(10);
	print_status(f1);

	f1.beRepaired(20);
	print_status(f1);

	// test overflow
	f1.beRepaired(-20);
	print_status(f1);

	// inherited from ScavTrap
	f1.guardGate();

	// inherited from FragTrap
	f1.highFivesGuys();

	return (0);
}



