#include "BitcoinExchange.hpp"
#include <map>
#include <fstream>
#include <iostream>
#include <sstream>
#include <cstdlib>
#include <string>

BitcoinExchange::BitcoinExchange()
: _earliest_date(0), _latest_date(0)
{
	//
}

BitcoinExchange::~BitcoinExchange()
{
	_database.clear();
}

BitcoinExchange::BitcoinExchange(BitcoinExchange& other)
{
	*this = other;
}

BitcoinExchange& BitcoinExchange::operator=(BitcoinExchange &other)
{
	_database = other._database;
	return(*this);
}

bool BitcoinExchange::readDatabase(std::string const & data)
{
	std::string		entry;
	std::ifstream	database_file;

	database_file.open(data);
	if (database_file.fail())
	{
		std::cout << "Error: cannot open database." << std::endl;
		return (false);
	}
	while (getline(database_file, entry))
	{
		if (entry != "date,exchange_rate" && entry != "")
		{
			if (!_addEntryToDatabase(entry))
				return(false);
		}
	}

	database_file.close();

	std::map<int, double>::iterator it = _database.begin();
	_earliest_date = it->first;
	std::map<int, double>::reverse_iterator rit = _database.rbegin();
	_latest_date = rit->first;
	return (true);
}


bool BitcoinExchange::_addEntryToDatabase(std::string const & entry)
{
	std::istringstream ss(entry);
	int year, month, day;
	double value;
	char delimitor_1, delimitor_2, delimitor_3;

	ss >> year >> delimitor_1 >> month >> delimitor_2 >> day >> delimitor_3 >> value;
	if (delimitor_1 != '-' || delimitor_2 != '-' || delimitor_3 != ',')
		return (false);

	int date = year * 10000 + month * 100 +  day * 1;

	if (!_isValidDate(year, month, day))
		return (false);

	_database[date] = value;
	return (true);
}

bool	BitcoinExchange::_isValidDate(int year, int month, int day)
{
	if (month < 1 || month >  12 || day < 1 || day > 31)
		return (false);

	if (month == 2)
	{
		if (day > 29)
			return (false);
		if (day == 29 && !_isLeapYear(year))
			return (false);
	}

	if (month == 2 || month == 4 || month == 6 || month ==  9 || month == 11)
	{
		if (day == 31)
			return (false);
	}
	return (true);
}

bool	BitcoinExchange::_isLeapYear(int year)
{
	if (year % 4 == 0)
	{
		if (year % 100 != 0 || year % 400 == 0 )
			return (true);
	}
	return (false);
}

void BitcoinExchange::_printDatabase()
{
	std::map<int, double>::iterator it = _database.begin();
	for (; it != _database.end(); it++)
	{
		std::cout << it->first << ": " << it->second << std::endl;
	}
}

void	BitcoinExchange::printResult(std::string const & input)
{

	std::string		line;
	std::ifstream	input_file;

	input_file.open(input);
	if (input_file.is_open())
	{
		int		flag = 0;
		while (getline(input_file, line))
		{
			if (line.empty())
			{
				std::cout << std::endl;
				continue;
			}
			if (line == "date | value")
			{
				if (flag == 0)
				{
					std::cout << "date | value" << std::endl;
					flag++;
				}
				else
					std::cout << "Error: bad input" << std::endl;
				continue;
			}
			_processLine(line);
		}
	}
	else
	{
		std::cout << "Error: could not open file." << std::endl;
		return;
	}
}

bool	BitcoinExchange::_isValidFormat(std::string const & line)
{
	int flag_float = 0;

	if (line.length() <= 13)
		return false;
	for (size_t i = 0; i < line.length(); ++i)
	{
		if (i == 4 || i == 7)
		{
			if (line[i] != '-')
				return false;
		}
		else if (i== 10 || i== 12)
		{
			if (line[i] != ' ')
				return false;
		}
		else if (i == 11)
		{
			if (line[i] != '|')
				return false;

		}
		else if ( i < 10 && !isdigit(line[i]))
			return false;
		else if (i > 13 && !isdigit(line[i]))
		{
			if (line[i] == '.' && flag_float == 0 )
				++flag_float;
			else
				return false;
		}
	}
	return true;
}

void	BitcoinExchange::_processLine(std::string const & line)
{
	if (!_isValidFormat(line)) {
		std::cout <<  "Error: bad input => " << line <<  std::endl;
		return;
	}
	std::istringstream ss(line);
	int year, month, day;
	double value;
	char delimitor_1 = 0, delimitor_2 = 0, delimitor_3 = 0;

	ss >> year >> delimitor_1 >> month >> delimitor_2 >> day >> delimitor_3 >> value;
	if (value > std::numeric_limits<int>::max() || value < std::numeric_limits<int>::min())
	{
		std::cout << "Error: bad input: date out of the range of the integer. " << std::endl;
		return;
	}
	if (_errorHandler(year, month, day,value))
	{
		double exchange_rate;

		exchange_rate = _findExchangeRate(year * 10000 + month * 100 + day);
		if (exchange_rate >= 0)
			std::cout << _formatDate(year, month, day) << " => " << value << " = " << exchange_rate * value << std::endl;
		else
			std::cout << "Error: bad input: date out of the range of the datebase. " << std::endl;
	}
}

std::string BitcoinExchange::_formatDate(int year, int month, int day)
{
	std::string filler1 = "";
	std::string filler2 = "";

	if (month < 10)
		filler1 = "0";
	if (day < 10)
		filler2 = "0";
	return (std::to_string(year) + "-" +  filler1 + std::to_string(month) + "-" + filler2 + std::to_string(day));
}

bool	BitcoinExchange::_errorHandler(int year, int month, int day, int value)
{
	if (!_isValidDate(year, month, day))
	{
		std::cout << "Error: bad input => " << _formatDate(year, month, day) <<  std::endl;
		return false;
	}
	if (value < 0)
	{
		std::cout << "Error: not a positive number." << std::endl;
		return false;
	}
	if (value > 1000)
	{
		std::cout << "Error: too large a number." << std::endl;
		return false;
	}
	return true;
}

double	BitcoinExchange::_findExchangeRate(int date)
{
	if (date < _earliest_date || date > _latest_date)
		return (-1);

	std::map<int, double>::iterator it = _database.find(date);

	if (it != _database.end()) // find the exact value
		return (it->second);

	it = _database.begin(); // find approximate date

	double exchange_rate = it->second;
	while (it != _database.end())
	{
		if ( date > it->first)
			exchange_rate = it->second;
		it++;
	}
	return (exchange_rate);
}
