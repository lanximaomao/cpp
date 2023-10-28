#include "PmergeMe.hpp"
#include <vector>
#include <deque>
#include <sstream>
#include <cctype>
#include <climits>
#include <iomanip>
#include <sys/time.h>


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
	_deque = other._deque;

	return (*this);
}

bool PmergeMe::_readDataToVector(char** argv)
{
	long		num;
	std::string arg;
	std::string	sign = "";
	while (*argv)
	{
		for (size_t i = 0; (*argv)[i]; i++)
		{
			if (i == 0 && *argv[0] == '+')
				continue;
			if (!std::isdigit((*argv)[i]))
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
	return (true);
}

bool PmergeMe::_readDataToDeque(char** argv)
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
			if (!std::isdigit((*argv)[i]))
				return (false);
		}
		errno = 0;
		num = strtol(*argv, NULL, 10);
		if (errno != 0 || num > INT_MAX || num < INT_MIN)
			return (false);
		_deque.push_back(num);
		argv++;
	}
	std::cout << std::endl;
	return (true);
}

static unsigned long getTime()
{
	timeval	time;

	gettimeofday(&time, NULL);
	return (1000000 * time.tv_sec + time.tv_usec);
}

void PmergeMe::action(char** argv)
{
	unsigned int start = getTime();
	if (!_readDataToVector(argv))
	{
		std::cout << "Error" << std::endl;
		return;
	}
	_sortInVector(0, _size - 1);
	unsigned int end = getTime();

	unsigned int start2 = getTime();
	if (!_readDataToDeque(argv))
	{
		std::cout << "Error" << std::endl;
		return;
	}
	_sortInDeque(0, _size - 1);
	unsigned int end2 = getTime();

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

	std::cout << std::endl << "Time to process a range of " << _size << " elements with std::vector: " << std::setprecision(6) << (end - start) << " us" << std::endl;
	std::cout << "Time to process a range of " << _size << " elements with std::deque: " << std::setprecision(6) << (end2 - start2) << " us"  << std::endl;
}

void PmergeMe::_sortInDeque(int start, int end)
{
	if (start < end)
	{
		if (end - start >= MIN_SIZE)
		{
			int mid = start + (end - start) / 2;
			_sortInDeque(start, mid);
			_sortInDeque(mid + 1, end);
			_dequeMerge(start, mid, end);
		}
		else
			_dequeInsert(start,end);
	}
}

void	PmergeMe::_dequeMerge(int start, int mid, int end)
{
	int i, j, k;

	std::deque<int> left(mid - start + 1), right(end - mid);

	for (i = 0; i < mid - start + 1; i++)
		left[i] = _deque[start + i];
	for (j = 0; j < end - mid; j++)
		right[j] = _deque[mid + 1 + j];

	i = 0;
	j = 0;
	k = start;

	while (i < mid - start + 1 && j < end - mid)
	{
		if (left[i] <= right[j])
			_deque[k++] = left[i++];
		else
			_deque[k++] = right[j++];
	}

	while (i < mid - start + 1)
		_deque[k++] = left[i++];

	while (j < end - mid)
		_deque[k++] = right[j++];
}

void	PmergeMe::_dequeInsert(int start, int end)
{
	int i, j, tmp;
	for (i = start + 1; i <= end; i++)
	{
		tmp = _deque[i];
		j = i - 1;
		for (; j >= start && _deque[j] > tmp; j--)
			_deque[j + 1] = _deque[j];
		_deque[j + 1] = tmp;
	}
}

void PmergeMe::_sortInVector(int start, int end)
{
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

