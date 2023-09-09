#ifndef ITER_HPP
# define ITER_HPP

# include <cstddef>
#include <iostream>

template<typename T>
void iter(T arr[], std::size_t size, void (*func)(const T&))
{
	for (std::size_t i = 0; i < size; i++)
		func(arr[i]);
}

template<typename T>
void printElement(const T& element)
{
	std::cout << element << std::endl;
}
#endif
