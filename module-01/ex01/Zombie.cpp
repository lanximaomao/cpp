#include "Zombie.hpp"

Zombie::Zombie() { std::cout << "Zombie created." << std::endl; }
Zombie::~Zombie() { std::cout << "Zombie destroyed." << std::endl; }

void Zombie::setName(std::string name) { this->_name = name; }
std::string Zombie::getName() const { return(this->_name); }

void Zombie::announce() const { std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl; }
