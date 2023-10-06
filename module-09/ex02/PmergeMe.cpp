#include "PmergeMe.hpp"
#include <vector>
#include <list>

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

void PmergeMe::readDataToVector(char** argv)
{

}

void PmergeMe::readDataToList(char** argv)
{

}

void PmergeMe::sortInteger_inVector()
{

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
