#ifndef HUMANA_HPP
# define HUMANA_HPP

#include "Weapon.hpp"

class HumanA
{
	public:
		HumanA(std::string _name, Weapon &w);
		~HumanA(void);

		void		attack();
		void		setWeapon(Weapon& new_weapon);

	private:
		std::string	_name;
		Weapon&		_first_weapon;
};

#endif
