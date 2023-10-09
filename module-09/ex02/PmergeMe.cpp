#include "PmergeMe.hpp"
#include <vector>
#include <list>
#include <sstream>
#include <cctype>
#include <climits>

std::vector<int> PmergeMe::_vbefore;
std::vector<int> PmergeMe::_vafter;
std::list<int> PmergeMe::_lbefore;
std::list<int> PmergeMe::_lafter;

PmergeMe::PmergeMe()
{

}

PmergeMe::PmergeMe(PmergeMe & other)
{

}

PmergeMe & PmergeMe::operator=(PmergeMe & other)
{
	return (*this);
}


// error handeling, only positive numbers

bool PmergeMe::readDataToVector(char** argv)
{
	std::string arg;
	long		num;
	std::string	sign = "";
	while (*argv)
	{
		for (size_t i = 0; (*argv)[i]; i++)
		{
			if (i == 0 && *argv[0] == '+')
				continue;
			if (!std::isdigit((*argv)[i])) // handel non-digital output
				return (false);
		}
		errno = 0;
		num = strtol(*argv, NULL, 10);
		if (errno != 0 || num > INT_MAX || num < INT_MIN)
			return (false);
		std::cout << num << " ";
		_vbefore.push_back(num);

		argv++;
	}
	std::cout << std::endl;
	return (true);
}

/* duplicates? */
bool PmergeMe::readDataToList(char** argv)
{
	std::string arg;
	long		num;
	std::string	sign = "";
	while (*argv)
	{
		for (size_t i = 0; (*argv)[i]; i++)
		{
			if (i == 0 && *argv[0] == '+')
			{
				sign += "+";
				continue;
			}
			if (!std::isdigit((*argv)[i])) // handel non-digital output
				return (false);
		}
		errno = 0;
		num = strtol(*argv, NULL, 10);
		if (errno != 0 || num > INT_MAX || num < INT_MIN)
			return (false);
		std::cout << num << " ";
		_lbefore.push_back(num);

		argv++;
	}
	std::cout << std::endl;
	return (true);
}

void mergeTwoContainer(std::vector<int> & intSeq, std::vector<int> & left, std::vector<int> & right)
{
	std::vector<int>::iterator lit = left.begin();
	std::vector<int>::iterator lite = left.end();

	std::vector<int>::iterator rit = right.begin();
	std::vector<int>::iterator rite = right.end();

	for (; lit != lite; lit++)
	{
		
		for (; rit != rite; rit++)
		{

		}
	}
}

void mergeSort(std::vector<int> & int_seq)
{
	std::vector<int>::iterator it = int_seq.begin();
	std::vector<int>::iterator mid = it + int_seq.size() / 2;
	std::vector<int>::iterator ite = int_seq.end();

	if (int_seq.size() <= 1)
		return;

	std::vector<int> left_seq(it, mid);
	std::vector<int> right_seq(mid, ite);

	mergeSort(left_seq);
	mergeSort(right_seq);

	mergeTwoContainer(int_seq, left_seq, right_seq);
}

void PmergeMe::sortInteger_inVector()
{
	// break into pairs
	// sort pairs
	//

}

void PmergeMe::sortInteger_inList()
{

}


void PmergeMe::printResult(double t_vector, double t_list)
{
	int size = _vbefore.size();
	std::cout << "Before: ";
	for (size_t i = 0; i < size; i++)
		std::cout << _vbefore[i] << " ";

	std::cout << std::endl << "After: ";
	for (size_t i = 0; i < size; i++)
		std::cout << _vbefore[i] << " ";

	std::cout << std::endl << "Time to process a range of " << size << " elements with std::vector: " << t_vector << std::endl;
	std::cout << std::endl << "Time to process a range of " << size << " elements with std::list: " << t_list << std::endl;
}

//Before: 3 5 9 7 4
//After: 3 4 5 7 9
//Time to process a range of 5 elements with std::[..] : 0.00031 us
//Time to process a range of 5 elements with std::[..] : 0.00014 us
