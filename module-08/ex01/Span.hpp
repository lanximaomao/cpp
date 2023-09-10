#ifndef SPAN_HPP
# define SPAN_HPP

#include <vector>
#include <iostream>


// should we consider other container type?

class Span
{
	private:
		unsigned int			_size;
		std::vector<int>		_v1; // already initilized
		Span();

	public:
		Span(const unsigned int size);
		Span(const Span& other);
		Span& operator=(const Span& other);
		~Span();

		// member functions
		void	addNumber(int n);
		int		shortestSpan() const;
		int		longestSpan() const;
		std::vector<int>& getInt();

	class ExceedFullCapacity: public std::exception
	{
		const char* what() const throw()
		{
			return ("exceed full capacity! ");
		}
	};

	class NoSpanFound: public std::exception
	{
		const char* what() const throw()
		{
			return("no span can be found. inspect span size!");
		}
	};
};

# endif
