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
	//
}

PmergeMe::PmergeMe(PmergeMe & other)
{
	*this = other;
}

PmergeMe & PmergeMe::operator=(PmergeMe & other)
{
	_vbefore = other._vbefore;
	_vafter = other._vafter;
	_lbefore = other._lbefore;
	_lafter = other._lafter;

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
		//std::cout << num << " ";
		_vbefore.push_back(num);

		argv++;
	}
	//std::cout << std::endl;
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

void PmergeMe::MergeInsertionSortVector()
{
	std::vector<int>::iterator it = _vbefore.begin();
	std::vector<int>::iterator mid = it + _vbefore.size() / 2;
	std::vector<int>::iterator ite = _vbefore.end();

	std::vector<int> leftSeq(it, mid);

	mergeSort(leftSeq); // in-place sorting?
	std::cout << "HERE" << std::endl;
	printSeq(leftSeq);
	_vafter = leftSeq;
	std::vector<int>::iterator lit = _vafter.begin();

	while (mid != ite)
	{
		while (*mid > *lit)
			lit++;
		_vafter.insert(lit, *mid);
		mid++;
	}
}

void PmergeMe::MergeInsertionSortList()
{
	std::list<int>	leftSeq;
	std::list<int>	rightSeq;

	std::list<int>::iterator it = _lbefore.begin();
	for (size_t i = 0; i < _lbefore.size(); i++)
	{
		if (i < _lbefore.size()/2)
			leftSeq.push_back(*it);
		else
			rightSeq.push_back(*it);
		it++;
	}



	mergeSort(leftSeq);
	_lafter = leftSeq;
	std::list<int>::iterator lit = leftSeq.begin();
	std::list<int>::iterator lite = leftSeq.end();
	std::list<int>::iterator rit = rightSeq.begin();
	std::list<int>::iterator rite = rightSeq.end();

	while (rit != rite)
	{
		while (*rit > *lit)
			lit++;
		_lafter.insert(lit, *rit);
		rit++;
	}
}


void PmergeMe::printResult(double t_vector, double t_list)
{
	int size = _vbefore.size();
	std::cout << "Before: ";
	//for (size_t i = 0; i < size; i++)
	//	std::cout << _vbefore[i] << " ";

	//std::cout << std::endl << "After: ";
	//for (size_t i = 0; i < size; i++)
	//	std::cout << _vafter[i] << " ";

	for (std::vector<int>::iterator it = _vbefore.begin(); it != _vbefore.end(); it++)
		std::cout << *it << " ";

	std::cout << std::endl << "After: ";
	for (std::vector<int>::iterator it = _vafter.begin(); it != _vafter.end(); it++)
		std::cout << *it << " ";

	std::cout << std::endl << "Time to process a range of " << size << " elements with std::vector: " << t_vector << std::endl;
	std::cout << std::endl << "Time to process a range of " << size << " elements with std::list: " << t_list << std::endl;
}

//Before: 3 5 9 7 4
//After: 3 4 5 7 9
//Time to process a range of 5 elements with std::[..] : 0.00031 us
//Time to process a range of 5 elements with std::[..] : 0.00014 us
