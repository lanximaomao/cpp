#include "BitcoinExchange.hpp"
#include <map>
#include <fstream>
#include <iostream>

// If the date used in the input does not exist in your DB then you
//must use the closest date contained in your DB. Be careful to use the
//lower date and not the upper one.

int BitcoinExchange::readDatabase()
{
	std::string	input_line;

	std::ifstream input_file(_file);
	if (!input_file)
		return (0); // return false
	while (getline(input_file, input_line))
	{
		if (input_line != "date,exchange_rate")
		{
			// split
			//_database[]
		}
	}



}

BitcoinExchange::BitcoinExchange():_file("data.csv")
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
	return(*this);
}

void	BitcoinExchange::printResult()
{
	//compare the dates
}
