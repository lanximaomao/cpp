#include <iostream>
#include "BitcoinExchange.hpp"


int main(int argc, char** argv)
{
	if (argc != 2)
		return(1);

	BitcoinExchange btc;
	if (!btc.readDatabase())
	{

	}


	return (0);
}


//$> head input.txt
//date | value
//2011-01-03 | 3
//2011-01-03 | 2
//2011-01-03 | 1
//2011-01-03 | 1.2
//2011-01-09 | 1
//2012-01-11 | -1
//2001-42-42
//2012-01-11 | 1
//2012-01-11 | 2147483648
//$>


//$> ./btc
//Error: could not open file.
//$> ./btc input.txt
//2011-01-03 => 3 = 0.9
//2011-01-03 => 2 = 0.6
//2011-01-03 => 1 = 0.3
//2011-01-03 => 1.2 = 0.36
//2011-01-09 => 1 = 0.32
//Error: not a positive number.
//Error: bad input => 2001-42-42
//2012-01-11 => 1 = 7.1
//Error: too large a number.
//$>
