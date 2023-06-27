#include "Weapon.hpp"

Weapon::Weapon(std::string w): _type(w){}
Weapon::~Weapon(){}

void Weapon::setType(std::string type)
{
	this->_type = type;
}

std::string&	Weapon::getType()
{
	std::string &ret = this->_type;
	return(ret);
}
