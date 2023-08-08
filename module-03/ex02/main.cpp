#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
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
	std::cout << "\n\n===== FragTrap =====\n\n";

	FragTrap f1("Ahhhh");
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

	f1.highFivesGuys();

	return (0);
}



