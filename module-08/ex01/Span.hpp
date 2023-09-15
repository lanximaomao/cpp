#ifndef SPAN_HPP
# define SPAN_HPP

#include <vector>
#include <iostream>

class Span
{
	private:
		unsigned int			_size;
		std::vector<int>		_data;
		Span();

	public:
		Span(const unsigned int size);
		Span(const Span& other);
		Span& operator=(const Span& other);
		~Span();

		std::vector<int>&	getData();
		unsigned int		getSize();
		void				addNumber(int n);

		template <typename I>
		void addManyNumber(I begin, I end)
		{
			while (begin != end)
			{
				addNumber(*begin);
				begin++;
			}
		}

		int					shortestSpan() const;
		int					longestSpan() const;

		class ExceedFullCapacity: public std::exception
		{
			public:
				const char* what() const throw()
				{
					return ("Exception: exceed full capacity! ");
				}
		};

		class NoSpanFound: public std::exception
		{
			public:
				const char* what() const throw()
				{
					return("Exception: no span can be found. inspect span size!");
				}
		};
};

# endif
