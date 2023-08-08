#include <iostream>
#include "ClapTrap.hpp"
#include "Color.hpp"

ClapTrap::ClapTrap(std::string name)
: _name(name)
, _health(10)
, _energy(10)
, _damage(0)
{
	std::cout << "ClapTrap " << name << " created\n";
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap " << _name << " destoryed\n";
}

ClapTrap::ClapTrap(const ClapTrap &other)
{
	std::cout << "ClapTrap " << "copy constructor called\n";
	*this = other;
}

ClapTrap& ClapTrap::operator=(const ClapTrap &other)
{
	if (this != &other)
	{
		_name = other._name;
		_health = other._health;
		_energy = other._energy;
		_damage = other._damage;
	}
	return (*this);
}

//setters
void ClapTrap::setHealth(int health)
{
	_health = health;
}

void ClapTrap::setEnergy(int energy)
{
	_energy = energy;
}
void ClapTrap::setDamage(int damage)
{
	_damage = damage;
}

//getters
std::string ClapTrap::getName() const
{
	return (_name);
}

int ClapTrap::getHealth() const
{
	return (_health);
}

int ClapTrap::getEnergy() const
{
	return (_energy);
}

int ClapTrap::getDamage() const
{
	return (_damage);
}

//member function
void ClapTrap::attack(const std::string& target)
{
	if (_health <= 0 || _energy <= 0)
		return;
	_energy --;
	std::cout << COLOR_BRIGHT_RED
		<< "ClapTrap " << _name << " attacks "
		<< target << ", causing " << _damage << " points of damage!\n"
		<< COLOR_RESET;
}

void ClapTrap::take_damage(unsigned int amount)
{
	std::cout << COLOR_MAGENTA
		<< "ClapTrap " << _name << " takes damage of "
		<< amount << " points\n" << COLOR_RESET;
	if (amount > 0)
	{
		_health -= amount;
		if (_health <= 0 )
		{
			_health = 0;
			std::cout << this->_name << " died.\n";
		}
	}
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (_health <= 0 || _energy <= 0)
		return;
	if (amount > 0)
	{
		_health += amount;
		_energy -= 1;
	}
	std::cout << COLOR_CYAN
		<< "ClapTrap " << _name << " repaired itself for "
		<< amount << " points\n" << COLOR_RESET;
}
