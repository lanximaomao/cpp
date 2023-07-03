#include "Harl.hpp"
#include "Color.hpp"

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

void Harl::_debug(void) const
{
	std::cout << COLOR_YELLOW << "[DEBUG] Harl sends a DEBUG message!" << COLOR_RESET << std::endl;
}

void Harl::_info(void) const
{
	std::cout << COLOR_RED << "[INFO] Harl sends a INFO message!" << COLOR_RESET << std::endl;
}

void Harl::_warning(void) const
{
	std::cout << COLOR_MAGENTA << "[WARNING] Harl sends a WARNING message!" << COLOR_RESET << std::endl;
}

void Harl::_error(void) const
{
	std::cout << COLOR_BLUE << "[ERROR] Harl sends an ERROR message!" << COLOR_RESET << std::endl;
}
