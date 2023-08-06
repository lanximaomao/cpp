#include "Harl.hpp"
#include "Color.hpp"

void Harl::complain_filter(std::string level) const
{
	static const size_t level_count = 4;
	static std::string level_msg [] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	int filter = -1;
	for (size_t i = 0; i < level_count; i++)
	{
		if (level.compare(level_msg[i]) == 0)
		{
			filter = static_cast<int>(i);
			break;
		}
	}
	switch (filter)
	{
		case 0:
			_debug();
		case 1:
			_info();
		case 2:
			_warning();
		case 3:
			_error();
			break;
		default:
			_debug();
			_info();
			_warning();
			_error();
			break;
	}
}
/*
** By declaring it as static, the array is initialized only once when the program starts, and its values remain constant throughout the program's execution.
** The use of static variables in this context ensures that the variables are shared among all instances of the Harl class. It means that all objects of the Harl class will have access to the same values of level_count and level_strs.
*/
void Harl::complain(std::string level) const
{
	static const size_t level_count = 4;
	static std::string level_msg [] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	static t_complain_func level_func [] = {&Harl::_debug, &Harl::_info, &Harl::_warning, &Harl::_error};

	size_t i;
	i = 0;
	while (i < level_count)
	{
		if (level.compare(level_msg[i]) == 0)
		{
			(this->*level_func[i])();
			return;
		}
		i++;
	}
	std::cout << COLOR_BRIGHT_GREEN << "Amazing, Harl has no complain!" << COLOR_RESET << std::endl;
}

void Harl::_debug() const
{
	std::cout << COLOR_YELLOW << "[DEBUG] Harl sends a DEBUG message!" << COLOR_RESET << std::endl;
}

void Harl::_info() const
{
	std::cout << COLOR_RED << "[INFO] Harl sends a INFO message!" << COLOR_RESET << std::endl;
}

void Harl::_warning() const
{
	std::cout << COLOR_MAGENTA << "[WARNING] Harl sends a WARNING message!" << COLOR_RESET << std::endl;
}

void Harl::_error() const
{
	std::cout << COLOR_BLUE << "[ERROR] Harl sends an ERROR message!" << COLOR_RESET << std::endl;
}
