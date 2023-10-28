#include <iostream>
#include <ctime>
#include "PmergeMe.hpp"

int main(int argc, char** argv)
{
	if (argc == 1)
	{
		std::cout << "arguments, pls!" << std::endl;
		return (1);
	}

	PmergeMe sort;
	sort.action(argv + 1);
	return (0);
}
