#include "MutantStack.hpp"

int main()
{
	std::cout << "\n\n=====  basic functionality test =====\n\n";
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << mstack.top() << std::endl;
	mstack.pop();
	std::cout << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	//[...]
	mstack.push(0);
	std::cout << "top=" << mstack.top() << std::endl;
	MutantStack<int>::iterator it = mstack.rbegin();
	MutantStack<int>::iterator ite = mstack.rend();
	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::stack<int> s(mstack);

	return(0);
}
