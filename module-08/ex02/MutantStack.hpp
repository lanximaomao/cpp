#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

#include <iostream>
#include <stack>

template <typename T>
class MutantStack: public std::stack
{
	private:
		T*		_ptr; // raw pointer
	public:
		MutantStack();
		// copy constructor needed or not?
		~MutantStack();
		class iterator
		{
			T* operator=(T* other); //
			int operator++(T* other);
			int operator--(T* other);
			void operator++(T* other);
			void operator--(T* other);
			T* operator+(T* other);
			T* operator-(T* other);
			bool operator!=(T* other);
			bool operatpr==(T* other);
		};

		class const_iterator
		{
			T& const_iterator();
		}
}

# endif

