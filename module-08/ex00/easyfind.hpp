#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <algorithm>
#include <iostream>


template <typename T>
void easyPrint(T& generic_container)
{
	for (size_t i = 0; i < generic_container.size(); i++)
		std::cout << generic_container[i] << std::endl;
}

class ValueNotFound: public std::exception
{
	public:
		const char *what() const throw()
		{
			return ("value not found.");
		}
};

template <typename T>
typename T::iterator easyfind(T& generic_container, const int target)
{
	typename T::iterator it = std::find(generic_container.begin(), generic_container.end(), target);
	if (it == generic_container.end())
		throw ValueNotFound();
	return (it);
}

# endif
