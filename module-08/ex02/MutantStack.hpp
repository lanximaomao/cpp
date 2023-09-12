#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

#include <iostream>
#include <stack>
#include <deque>

template <typename T>
class MutantStack : public std::stack<T, std::deque<T> >
{
	public:
		MutantStack();
		MutantStack(const MutantStack& other);
		MutantStack& operator=(const MutantStack& other);
		~MutantStack();

		using iterator = typename std::deque<T>::iterator;
		using const_iterator = typename std::deque<T>::const_iterator;

		iterator begin() { return std::deque<T>::begin(); }
		iterator end() { return std::deque<T>::end(); }
		iterator rbegin() { return std::deque<T>::rbegin(); }
		iterator rend() { return std::deque<T>::rend(); }
		const_iterator cbegin() const { return std::deque<T>::cbegin(); }
		const_iterator cend() const { return std::deque<T>::cend(); }
		const_iterator crbegin() const { return std::deque<T>::crbegin(); }
		const_iterator crend() const { return std::deque<T>::crend(); }
};


# endif
