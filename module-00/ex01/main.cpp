#include "Color.hpp"
#include "PhoneBook.hpp"

int	main()
{
	PhoneBook	phonebook;

	std::string cmd;
	while (42)
	{
		std::cout << COLOR_GREEN;
		std::cout << "\nWrite \"ADD\" to add a new contact." << std::endl;
		std::cout << "Write \"SEARCH\" to search for a contact" << std::endl;
		std::cout << "Write \"EXIT\" to exit the PhoneBook.\n" << std::endl;
		std::cout << COLOR_RESET;
		std::getline(std::cin, cmd, '\n');
		if (std::cin.eof() == 1)
			std::exit(0);
		if (cmd.empty())
		{
			std::cout << "Invalid command. Please follow these instructions:" << std::endl;
			continue ;
		}
		phonebook.op(cmd);
	}
	return (0);
}
