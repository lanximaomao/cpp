#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP
# include <string>
# include "ClapTrap.hpp"
# include "ScavTrap.hpp"
# include "FragTrap.hpp"

// inside ScavTrap and FragTrap the inheritance specifier is changed to public virtual

class DiamondTrap: public ScavTrap, public FragTrap
{
	private:

	public:
		DiamondTrap(const std::string name);
		DiamondTrap(const DiamondTrap &other);
		~DiamondTrap();
		DiamondTrap& operator=(const DiamondTrap &other);

		// member function
		void whoAmI(void) const;
};

#endif
