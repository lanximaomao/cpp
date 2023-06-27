#include "Weapon.hpp"
#include "HumanA.hpp"
#include "HumanB.hpp"

int main()
{
	{
		Weapon club = Weapon("apple");
		HumanA bob("Bob", club);
		bob.attack();
		club.setType("Pineapple");
		bob.attack();
	}
	{
		Weapon club = Weapon("banana");
		HumanB jim("Jim");
		jim.attack();
		jim.setWeapon(&club);
		club.setType("Crazybanana");
		jim.attack();
		return 0;
	}
}
