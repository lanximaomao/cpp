#include <iostream>
#include "Span.hpp"

#include <vector>

Span::Span() :_size(0), _data(0) {}

Span::Span(const unsigned int size) :_size(size), _data(0) {}

Span::Span(const Span& other)
{
	*this = other;
}

std::vector<int>& Span::getData()
{
	return(_data);
}

unsigned int Span::getSize()
{
	return(_size);
}

Span& Span::operator=(const Span& other)
{
	if (this == &other)
		return (*this);
	_size = other._size;
	_data.clear();
	std::copy(other._data.begin(), other._data.end(), std::back_inserter(_data));
	return (*this);
}

Span::~Span() {}

void Span::addNumber(int n)
{
	if (_data.size() < _size)
		_data.push_back(n);
	else
		throw Span::ExceedFullCapacity();
}

/* const function requires using const_iterator */
int Span::longestSpan() const
{
	if (_data.size() < 2)
		throw Span::NoSpanFound();
	return (*std::max_element(_data.begin(), _data.end())
		- *std::min_element(_data.begin(), _data.end()));
}

int Span::shortestSpan() const
{
	if (_data.size() < 2)
		throw Span::NoSpanFound();

	int min_span = std::numeric_limits<int>::max();

	for (std::vector<int>::const_iterator i = _data.begin(); i != _data.end(); ++i)
	{
		for (std::vector<int>::const_iterator j = _data.begin(); j != _data.end(); ++j)
		{
			if (i != j && (*i - *j < min_span))
				min_span = abs(*i - *j);
		}
	}
	return (min_span);
}
