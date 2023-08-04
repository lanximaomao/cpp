#ifndef CLAP_TRAP_HPP
# define CLAP_TRAP_HPP
#include <iostream>

class ClapTrap
{
	private:
		int	_hitPoints;
		int	_energyPoints;
		int _attackDamage;

	public:
		ClapTrap(void);
		ClapTrap(ClapTrap &other);
		ClapTrap &operator=(ClapTrap &other);
		~ClapTrap();

		//setters
		void setHitPoints(int hit);
		void setEnergyPoints(int energy);
		void setAttackDamage(int attach);

		//getters
		int getHitPoints(void) const;
		int getEnergyPoints(void) const;
		int getAttackDamage(void) const;

		//member function
		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
};

# endif

ClapTrap::ClapTrap(void):_hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	//empty
}

ClapTrap::~ClapTrap()
{
	// empty
}

ClapTrap::ClapTrap(ClapTrap &other)
{
	*this = other;
}

ClapTrap &ClapTrap::operator=(ClapTrap &other)
{
	if (this != &other)
	{
		_hitPoints = other.getHitPoints();
		_energyPoints = other.getEnergyPoints();
		_attackDamage = other.getAttackDamage();
	}
	return (*this);
}
