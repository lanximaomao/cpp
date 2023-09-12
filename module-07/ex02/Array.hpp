#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <iostream>

template <typename T>
class Array
{
	private:
		T*				_array;
		unsigned int	_size;

	public:
		Array();
		Array(unsigned int n);
		Array(const Array& other);
		~Array();
		Array&	operator=(const Array& other);
		T&		operator[](unsigned int index) const;
		T* 		getArray() const;
		unsigned int	size() const;
};

#include "Array.tpp"

#endif
