#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#include <iostream>
#include <map>

class BitcoinExchange
{
	private:
		int	_earliest_date;
		int	_latest_date;
		std::map<int, double>	_database;
		std::map<int, double>	_input;

		bool	_addEntryToDatabase(std::string const & entry);
		bool	_isLeapYear(int year);
		bool	_isValidFormat(std::string const & line);
		bool	_isValidDate(int year, int month, int day);
		bool	_isValidEntry(std::string const & entry);



		void	_processLine(std::string const & line);
		bool	_errorHandler(int year, int month, int day, int value);
		double	_findExchangeRate(int date);
		std::string _formatDate(int year, int month, int day);


	public:
		void	_printDatabase();
		BitcoinExchange();
		~BitcoinExchange();
		BitcoinExchange(BitcoinExchange& other);
		BitcoinExchange& operator=(BitcoinExchange &other);

		bool	readDatabase(std::string const & data);
		void	printResult(std::string const & input);
};

# endif
