#ifndef RPN_HPP
# define RPN_HPP

#include <iostream>
#include <stack>

class RPN
{
	private:

	public:
		RPN();
		RPN(RPN const & other);
		RPN & operator=(RPN const & other);

		static std::stack<int> _rpn;
		static bool	calculateRPN(std::string input);
};

# endif
