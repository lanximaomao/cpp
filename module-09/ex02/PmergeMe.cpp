#include "PmergeMe.hpp"
#include <vector>
#include <list>
#include <sstream>
#include <cctype>
#include <climits>
#include <ctime>


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
	_vector = other._vector;
	_list = other._list;

	return (*this);
}



// error handeling, only positive numbers

bool PmergeMe::_readDataToVector(char** argv)
{
	long		num;
	std::string arg;
	std::string	sign = "";
	while (*argv)
	{
		std::cout << *argv << std::endl;
		for (size_t i = 0; (*argv)[i]; i++)
		{
			if (i == 0 && *argv[0] == '+')
				continue;
			if (!std::isdigit((*argv)[i])) // handel non-digital output
			{
				return (false);
			}
		}
		errno = 0;
		num = strtol(*argv, NULL, 10);
		if (errno != 0 || num > INT_MAX || num < INT_MIN)
			return (false);
		_vector.push_back(num);

		argv++;
	}
	_size = _vector.size();
	std::cout << "size = " << _size << std::endl;
	return (true);
}

/* duplicates? */
bool PmergeMe::_readDataToList(char** argv)
{
	long		num;
	std::string arg;
	std::string	sign = "";
	while (*argv)
	{
		for (size_t i = 0; (*argv)[i]; i++)
		{
			if (i == 0 && (*argv)[0] == '+')
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
		_list.push_back(num);

		argv++;
	}
	std::cout << std::endl;
	return (true);
}

// helper function
static double getTime()
{

	std::time_t seconds = std::time(NULL);
	double microseconds = seconds * 1000000.0;

	return (microseconds);
}


void PmergeMe::action(char** argv)
{
	double start = getTime();
	if (!_readDataToVector(argv))
	{
		std::cout << "Error" << std::endl;
		return;
	}
	_sortInVector(0, _size - 1);
	double end = getTime();
	std::cout << "here" <<  std::endl;

	//double start2 = getTime();
	//if (!_readDataToList(argv))
	//{
	//	std::cout << "Error" << std::endl;
	//	return;
	//}
	//_sortInList(0, _size - 1);
	//double end2 = getTime();

	std::cout << "Before: ";
	while (*argv)
	{
		std::cout << *argv << " ";
		argv++;
	}
	std::cout << std::endl;

	std::cout << "After: ";
	for(std::vector<int>::iterator it = _vector.begin(); it != _vector.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;

	std::cout << std::endl << "Time to process a range of " << _size << " elements with std::vector: " << (end - start) << "us" << std::endl;
	//std::cout << std::endl << "Time to process a range of " << _size << " elements with std::vector: " << (end2 - start2) << "us"  << std::endl;
}

//Before: 3 5 9 7 4
//After: 3 4 5 7 9
//Time to process a range of 5 elements with std::[..] : 0.00031 us
//Time to process a range of 5 elements with std::[..] : 0.00014 us

// negative numbers
void PmergeMe::_sortInList(int start, int end)
{
	if (start < end)
	{
		if (end - start >= MIN_SIZE)
		{
			int mid = start + (end - start) / 2;
			_sortInList(start, mid);
			_sortInList(mid + 1, end);
			_listMerge(start, mid, end);
		}
		else
			_listInsert(start,end);
	}
}

void	PmergeMe::_listMerge(int start, int mid, int end)
{

}

void	PmergeMe::_listInsert(int start, int end)
{

}

// Merge Sort
void PmergeMe::_sortInVector(int start, int end)
{
	std::cout << "calling with start=" << start << " end=" << end << std::endl;
	if (start < end)
	{
		if (end - start >= MIN_SIZE)
		{
			int mid = start + (end - start) / 2;
			_sortInVector(start, mid);
			_sortInVector(mid + 1, end);
			_vectorMerge(start, mid, end);
		}
		else
			_vectorInsert(start,end);
	}
}

void	PmergeMe::_vectorMerge(int start, int mid, int end)
{
	int i, j, k;

	std::vector<int> left(mid - start + 1), right(end - mid);

	for (i = 0; i < mid - start + 1; i++)
		left[i] = _vector[start + i];
	for (j = 0; j < end - mid; j++)
		right[j] = _vector[mid + 1 + j];

	i = 0;
	j = 0;
	k = start;

	while (i < mid - start + 1 && j < end - mid)
	{
		if (left[i] <= right[j])
			_vector[k++] = left[i++];
		else
			_vector[k++] = right[j++];
	}

	while (i < mid - start + 1)
		_vector[k++] = left[i++];

	while (j < end - mid)
		_vector[k++] = right[j++];
}

void	PmergeMe::_vectorInsert(int start, int end)
{
	int i, j, tmp;
	for (i = start + 1; i <= end; i++)
	{
		tmp = _vector[i];
		j = i - 1;
		for (; j >= start && _vector[j] > tmp; j--)
			_vector[j + 1] = _vector[j];
		_vector[j + 1] = tmp;
	}
}

