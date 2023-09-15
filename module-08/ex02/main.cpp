#include "MutantStack.hpp"
#include "Student.hpp"

template <typename T>
void display(MutantStack<T> & mstack)
{
	typename MutantStack<T>::iterator it = mstack.begin();
	typename MutantStack<T>::iterator ite = mstack.end();

	while (it != ite)
	{
		std::cout << *it << " ";
		it++;
	}
	std::cout << std::endl;
}

template <typename T>
void display_reverse(MutantStack<T> & mstack)
{
	typename MutantStack<T>::reverse_iterator it = mstack.rbegin();
	typename MutantStack<T>::reverse_iterator ite = mstack.rend();

	while (it != ite)
	{
		std::cout << *it << " ";
		it++;
	}
	std::cout << std::endl;
}

template <typename T>
void clear(MutantStack<T> &mstack)
{
	std::cout << "poping........\n";
	while (!mstack.empty())
	{
		std::cout << mstack.top() << std::endl;
		mstack.pop();
	}
	std::cout << "poping finished! " << std::endl;
}

int main()
{
	std::cout << "\n\n=====  iterator test =====\n\n";
	MutantStack<int > mstack;
	for (int i = 0; i < 10; i++)
		mstack.push(i);
	display(mstack);


	std::cout << "\n\n=====  complex data type =====\n\n";
	MutantStack<Student> s1;

	s1.push(Student("August", 1.1f));
	s1.push(Student("April", 2.2f));
	s1.push(Student("Cathy", 3.3f));

	display(s1);

	std::cout << "\n\n=====  reverse iterator =====\n\n";
	display_reverse(mstack);
	std::cout << std::endl;
	display_reverse(s1);

	std::cout << "\n\n=====  member function test =====\n\n";
	clear(mstack);
	display(mstack);

	return (0);

}

