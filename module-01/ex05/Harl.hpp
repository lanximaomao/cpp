#ifndef HARL_HPP
# define HARL_HPP

#include <iostream>

class Harl
{
	public:
		void complain(std::string level) const;
		//void complain_filter(std::string filter_level) const;

	private:
		void _debug() const;
		void _info() const;
		void _warning() const;
		void _error() const;
};

// all the functions satisfy this format can be represented by this function pointer
typedef void (Harl::*t_complain_func)() const;

#endif
