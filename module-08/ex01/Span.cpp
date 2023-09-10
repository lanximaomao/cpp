#include <iostream>
#include "Span.hpp"

#include <vector>

Span::Span() :_size(0)
{
	//
}

Span::Span(const unsigned int size)
:_size(size)
{
	std::cout << "parametric span constructor called" << std::endl;
}

Span::Span(const Span& other)
{
	*this = other;
}

std::vector<int>& Span::getInt()
{
	return(_v1);
}

Span& Span::operator=(const Span& other)
{
	if (this == &other)
		return (*this);
	_size = other._size;
	_v1.clear();
	//_v1 = other._v1;
	std::copy(other._v1.begin(), other._v1.end(), std::back_inserter(_v1));
	return (*this);
}

Span::~Span() {}

void Span::addNumber(int n)
{
	if (_v1.size() < _size)
		_v1.push_back(n);
	else
		throw Span::ExceedFullCapacity();
}

/* const function requires using const_iterator */
int Span::longestSpan() const
{
	if (_v1.size() < 2)
		throw Span::NoSpanFound();
	int max = std::numeric_limits<int>::min();
	int min = std::numeric_limits<int>::max();
	for (std::vector<int>::const_iterator it = _v1.begin(); it != _v1.end(); ++it)
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
	if (_v1.size() < 2)
		throw Span::NoSpanFound();

	int min_span = std::numeric_limits<int>::max();

	for (std::vector<int>::const_iterator i = _v1.begin(); i != _v1.end(); ++i)
	{
		for (std::vector<int>::const_iterator j = _v1.begin(); j != _v1.end(); ++j)
		{
			if (i != j && (*i - *j < min_span))
				min_span = abs(*i - *j);
		}
	}
	return (min_span);
}
