#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#include <string>
#include <map>

// deal with pull request
class BitcoinExchange
{
	private:
		int						_date;
		std::map<int, double>	_database;

	public:
		BitcoinExchange();
		~BitcoinExchange();
		BitcoinExchange(BitcoinExchange& other);
		BitcoinExchange& operator=(BitcoinExchange &other);

		int		readDatabase();
		void	printResult();
};

# endif
