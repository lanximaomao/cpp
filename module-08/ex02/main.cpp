#include "MutantStack.hpp"
#include "Student.hpp"

// why we need typename
template <typename T, typename U>
void display(MutantStack<T, U> & mstack)
{
	typename MutantStack<T, std::deque <T> >::iterator it = mstack.begin();
	typename MutantStack<T, std::deque <T> >::iterator ite = mstack.end();
	std::cout << "[";
	while (it != ite)
	{
		std::cout << *it << " ";
		it++;
	}
	std::cout << "]" << std::endl;
}

template <typename T, typename U>
void clear(MutantStack<T, U> &mstack)
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
	MutantStack<int, std::deque<int> > mstack;
	for (int i = 0; i < 10; i++)
		mstack.push(i);
	display(mstack);

	std::cout << "\n\n=====  member function test =====\n\n";
	clear(mstack);
	display(mstack);
	return(0);

	std::cout << "\n\n=====  complex data type =====\n\n";
	Student s1 = Student("John", 1.1);
	//MutantStack<Student, std::vector<Student> > s1;
	//s1.emplace("John", 1.1);
	//s1.emplace("Cake", 2.2);
	//s1.emplace("April", 3.3);
	//display(s1);

}

	//std::cout << mstack.top() << std::endl;
	//mstack.pop();
	//std::cout << mstack.size() << std::endl;
	//mstack.push(3);
	//mstack.push(5);
	//mstack.push(737);
	////[...]
	//mstack.push(0);
	//std::cout << "top=" << mstack.top() << std::endl;
	//MutantStack<int>::reverse_iterator it = mstack.rbegin();
	//MutantStack<int>::reverse_iterator ite = mstack.rend();
	//++it;
	//--it;
	//while (it != ite)
	//{
	//	std::cout << *it << std::endl;
	//	++it;
	//}
	//std::stack<int> s(mstack);

