#ifndef WEAPON_HPP
# define WEAPON_HPP

#include <iostream>

class Weapon
{
	public:
		Weapon(std::string w);
		~Weapon();

		void			setType(std::string type);
		std::string&	getType();

	private:
		std::string		_type;

};

#endif

