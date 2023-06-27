#ifndef HARL_HPP
# define HARL_HPP

#include <iostream>

class Harl
{
	public:
		void complain(std::string level) const;
		void complain_filter(std::string filter_level) const;

	private:
		void _debug(void) const;
		void _info(void) const;
		void _warning(void) const;
		void _error(void) const;
};

// all the functions satisfy this format can be represented by this function pointer
typedef void (Harl::*t_complain_func)(void) const;

#endif
