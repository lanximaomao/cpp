#include <iostream>
#include "Span.hpp"

#include <vector>

Span::Span() :_size(0) {}

Span::Span(const unsigned int size) :_size(size) {}

Span::Span(const Span& other)
{
	*this = other;
}

std::vector<int>& Span::getInt()
{
	return(_arr);
}

Span& Span::operator=(const Span& other)
{
	if (this == &other)
		return (*this);
	_size = other._size;
	_arr.clear();
	//_arr = other._arr;
	std::copy(other._arr.begin(), other._arr.end(), std::back_inserter(_arr));
	return (*this);
}

Span::~Span() {}

void Span::addNumber(int n)
{
	if (_arr.size() < _size)
		_arr.push_back(n);
	else
		throw Span::ExceedFullCapacity();
}

/* const function requires using const_iterator */
int Span::longestSpan() const
{
	if (_arr.size() < 2)
		throw Span::NoSpanFound();
	int max = std::numeric_limits<int>::min();
	int min = std::numeric_limits<int>::max();
	for (std::vector<int>::const_iterator it = _arr.begin(); it != _arr.end(); ++it)
	{
		if (*it > max)
			max = *it;
		if (*it < min)
			min = *it;
	}
	return (max - min);
}

int Span::shortestSpan() const
{
	if (_arr.size() < 2)
		throw Span::NoSpanFound();

	int min_span = std::numeric_limits<int>::max();

	for (std::vector<int>::const_iterator i = _arr.begin(); i != _arr.end(); ++i)
	{
		for (std::vector<int>::const_iterator j = _arr.begin(); j != _arr.end(); ++j)
		{
			if (i != j && (*i - *j < min_span))
				min_span = abs(*i - *j);
		}
	}
	return (min_span);
}
