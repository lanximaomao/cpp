#include "HumanA.hpp"

HumanA::HumanA(std::string _name, Weapon &w):_name(_name), _first_weapon(w) {}

HumanA::~HumanA() {}

void HumanA::setWeapon(Weapon& new_weapon)
{
	this->_first_weapon = new_weapon;
}

void HumanA::attack()
{
	std::cout << this->_name << " attack with their " << this->_first_weapon.getType() << std::endl;
}


