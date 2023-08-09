#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP
#include <string>
#include "ClapTrap.hpp" // must include here

class ScavTrap: public ClapTrap
{
	private:

	public:
		ScavTrap(const std::string name);
		ScavTrap(const ScavTrap &other);
		~ScavTrap();
		ScavTrap& operator=(const ScavTrap &other);

		// member functions
		void guardGate();
		void attack(const std::string& target);
};

#endif

