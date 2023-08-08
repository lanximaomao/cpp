#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP
#include <string>

class ClapTrap
{
	private:
		std::string	_name;
		int	_health;
		int	_energy;
		int _damage;

	public:
		ClapTrap(const std::string name);
		ClapTrap(const ClapTrap &other);
		~ClapTrap();
		ClapTrap &operator=(const ClapTrap &other);

		//setters
		void setHealth(int health);
		void setEnergy(int energy);
		void setDamage(int damage);

		//getters
		std::string getName() const;
		int getHealth() const;
		int getEnergy() const;
		int getDamage() const;

		//member function
		void attack(const std::string& target);
		void take_damage(unsigned int amount);
		void beRepaired(unsigned int amount);
};

# endif
