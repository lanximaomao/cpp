#include "Color.hpp"
#include "PhoneBook.hpp"
#include <iomanip>
#include <string>

PhoneBook::PhoneBook(): _index(-1), _count(0){}
PhoneBook::~PhoneBook() {}

int PhoneBook::getTotal() { return (this->_count); }

Contact *PhoneBook::_getContact() { return (this->_record); }

void PhoneBook::op(std::string cmd)
{
	if (cmd == "ADD")
		this->_add();
	else if (cmd == "SEARCH")
		this->_search();
	else if (cmd == "EXIT")
		std::exit(0);
	else
		std::cout << "Invalid command! Please follow these instructions:" << std::endl;
}

static std::string check_empty(std::string msg)
{
	std::string input;
	std::cout << COLOR_BRIGHT_BLUE;
	while (42)
	{
		std::cout << msg;
		std::getline(std::cin, input, '\n');
		if (std::cin.eof())
		{
			std::cout << COLOR_RESET << std::endl;
			std::exit(0);
		}
		if (input.empty() == 0)
		{
			std::cout << COLOR_RESET;
			return (input);
		}
		else
			std::cout << "\nInvalid input!" << std::endl;
	}
}

void PhoneBook::_add()
{
	std::string msg;
	if (this->_index < MAX_CONTACT - 1) //max contact in definition
		this->_index += 1;
	else
		this->_index = 0;
	msg = "\nInsert first name: ";
	this->_getContact()[this->_index].setFirstName(check_empty(msg));
	msg = "Inset last name: ";
	this->_getContact()[this->_index].setLastName(check_empty(msg));
	msg = "Inset nick name: ";
	this->_getContact()[this->_index].setNickName(check_empty(msg));
	msg = "Inset your phone number: ";
	this->_getContact()[this->_index].setNumber(check_empty(msg));
	msg = "Insert your darkest secret: ";
	this->_getContact()[this->_index].setSecret(check_empty(msg));
	if (this->_count < MAX_CONTACT)
		this->_count += 1;
}

static std::string truncate(std::string str)
{
	if (str.length() >= 10)
	{
		std::string cut = str.substr(0, 10);
		cut[9] = '.';
		return (cut);
	}
	else
		return (str);
}

static void phoneBook_header()
{
	std::cout << COLOR_MAGENTA << std::endl;
	std::cout << std::setfill(' ') << std::setw(10) << truncate("Index") << '|';
	std::cout << std::setfill(' ') << std::setw(10) << truncate("First Name") << '|';
	std::cout << std::setfill(' ') << std::setw(10) << truncate("Last Name") << '|';
	std::cout << std::setfill(' ') << std::setw(10) << truncate("Nickname")<< '|';
	std::cout << COLOR_RESET << std::endl;
}

static void phoneBook_body(Contact record, int index)
{
	std::cout << COLOR_MAGENTA;
	std::cout << std::setfill(' ') << std::setw(10) << index << '|';
	std::cout << std::setfill(' ') << std::setw(10) << truncate(record.getFirstName()) << '|';
	std::cout << std::setfill(' ') << std::setw(10) << truncate(record.getLastName()) << '|';
	std::cout << std::setfill(' ') << std::setw(10) << truncate(record.getNickName()) << '|';
	std::cout << COLOR_RESET << std::endl;
}

void PhoneBook::_search() const
{
	int	index;

	std::string input;
	if (this->_count == 0)
	{
		std::cout << COLOR_RED << "Empty phonebook!" << COLOR_RESET << std::endl;
		return ;
	}
	phoneBook_header();
	for (int i = 0; i < this->_count; i++)
		phoneBook_body(this->_record[i], i);
	input = check_empty("\nPlease enter the index number: ");
	try
	{
		index = std::stoi(input);
		if (index >= 0 && index < this->_count)
		{
			std::cout << COLOR_CYAN;
			std::cout << "\nFirst name: " << _record[index].getFirstName() << std::endl;
			std::cout << "Last name: " << _record[index].getLastName() << std::endl;
			std::cout << "Nickname name: " << _record[index].getNickName() << std::endl;
			std::cout << "Phone number: " << _record[index].getNumber() << std::endl;
			std::cout << "Darkest secret: " << _record[index].getSecret() << std::endl;
			std::cout << COLOR_RESET << std::endl;
			return ;
		}
		else
			std::cout << "Invalid index!" << std::endl;
	}
	catch(...)
	{
		std::cout << "Invalid input!" << std::endl;
	}
}
