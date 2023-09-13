#include <iostream>
#include <ctime>
#include "Span.hpp"

#define MAX_SIZE 5

int main()
{
	std::cout << "\n\n=====  basic functionality test =====\n\n";
	Span sp = Span(5);

	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);

	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;

	std::cout << "\n\n=====  more numbers =====\n\n";
	{
		Span sp = Span(MAX_SIZE);
		srand(time(NULL));
		for(size_t i = 0; i < MAX_SIZE; i++)
		{
			int random_value = rand();
			sp.addNumber(random_value);
			std::cout << random_value << std::endl;
		}
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}

	std::cout << "\n\n=====  exception test =====\n\n";
	try
	{
		sp.addNumber(50);
	}
	catch (Span::ExceedFullCapacity& ex)
	{
		std::cout << ex.what() << std::endl;
	}

	Span sp2 = Span(1);
	try
	{
		std::cout << sp2.shortestSpan() << std::endl;
	}
	catch(Span::NoSpanFound& ex)
	{
		std::cout << ex.what() << std::endl;
	}
}
