#include "Zombie.hpp"

Zombie::Zombie(void) { std::cout << "Zombie created." << std::endl; }
Zombie::~Zombie(void) { std::cout << "Zombie destoried." << std::endl; }

void Zombie::setName(std::string name) { this->_name = name; }
std::string Zombie::getName() const { return(this->_name); }

void Zombie::announce(void) const { std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl; }
