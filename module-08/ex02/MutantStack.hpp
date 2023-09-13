#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

#include <iostream>
#include <stack>
#include <deque>

template <typename T>
//template <typename T, class Container =  std::deque<T> >
//class MutantStack : public std::stack<T, Container> >
class MutantStack : public std::stack<T, std::deque<T> >
{
	public:
		MutantStack() {};
		MutantStack(const MutantStack& other);
		MutantStack& operator=(const MutantStack& other);
		~MutantStack() {};

		typedef typename std::deque<T>::iterator iterator;
		typedef typename std::deque<T>::const_iterator const_iterator;

		iterator begin() { return this->c.begin(); }
		iterator end() { return this->c.end(); }
		iterator rbegin() { return this->c.rbegin(); }
		iterator rend() { return this->c.rend(); }
		const_iterator cbegin() const { return this->c.cbegin(); }
		const_iterator cend() const { return this->c.cend(); }
		const_iterator crbegin() const { return this->c.crbegin(); }
		const_iterator crend() const { return this->c.crend(); }
};


# endif
