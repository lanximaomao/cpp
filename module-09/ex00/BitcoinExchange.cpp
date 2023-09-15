#include "BitcoinExchange.hpp"
#include <map>

// If the date used in the input does not exist in your DB then you
//must use the closest date contained in your DB. Be careful to use the
//lower date and not the upper one.

BitcoinExchange::BitcoinExchange()
{

}

BitcoinExchange::~BitcoinExchange()
{

}

BitcoinExchange::BitcoinExchange(BitcoinExchange& other)
{
	*this = other;
}

BitcoinExchange& BitcoinExchange::operator=(BitcoinExchange &other)
{
	return(*this);
}

