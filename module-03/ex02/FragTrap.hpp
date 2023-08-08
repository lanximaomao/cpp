#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP
# include <string>
# include "ClapTrap.hpp"

class FragTrap: public ClapTrap
{
	private:

	public:
		FragTrap(const std::string name);
		FragTrap(const FragTrap &other);
		~FragTrap();
		FragTrap& operator=(const FragTrap &other);

		// member function
		void highFivesGuys(void);
};

#endif
