#include <iostream>
#include <ctime>
#include "PmergeMe.hpp"

int main(int argc, char** argv)
{
	if (argc == 1)
		std::cout << "arguments, pls!" << std::endl;

	PmergeMe sort;
	sort.action(argv + 1);
	return (0);
}





//> ./PmergeMe 3 5 9 7 4
//Before: 3 5 9 7 4
//After: 3 4 5 7 9
//Time to process a range of 5 elements with std::[..] : 0.00031 us
//Time to process a range of 5 elements with std::[..] : 0.00014 us
//$> ./PmergeMe `shuf -i 1-100000 -n 3000 | tr "\n" " "`
//Before: 141 79 526 321 [...]
//After: 79 141 321 526 [...]
//Time to process a range of 3000 elements with std::[..] : 62.14389 us
//Time to process a range of 3000 elements with std::[..] : 69.27212 us
//$> ./PmergeMe "-1" "2"
//Error
//$> # For OSX USER:
//$> ./PmergeMe `jot -r 3000 1 100000 | tr '\n' ' '`
//[...]
//$>
