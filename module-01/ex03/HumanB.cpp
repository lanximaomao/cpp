#include "HumanB.hpp"

HumanB::HumanB(std::string _name):_name(_name)
{
	this->_first_weapon = NULL;
}

HumanB::~HumanB() {}

void HumanB::setWeapon(Weapon& new_weapon)
{
	this->_first_weapon = &new_weapon;
}

void HumanB::attack()
{
	if (this->_first_weapon)
		std::cout << this->_name << " attack with their " << this->_first_weapon->getType() << std::endl;
	else
		std::cout << this->_name << " has no weapon!" << std::endl;
}
