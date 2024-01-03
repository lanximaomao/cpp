#include "RPN.hpp"
#include <stack>
#include <sstream>

std::stack<int> RPN::_rpn;

RPN::RPN()
{
	//
}

RPN::RPN(RPN const & other)
{
	*this = other;
}

RPN & RPN::operator=(RPN const & other)
{
	_rpn = other._rpn;
	return (*this);
}

bool	RPN::calculateRPN(std::string input)
{
	std::istringstream ss(input);
	char token;

	while (ss >> token)
	{
		if (isdigit(token))
			RPN::_rpn.push(token - '0');
		else if ((token == '+' || token == '-' || token == '*' || token == '/') && RPN::_rpn.size() >= 2)
		{
			int top = RPN::_rpn.top();
			RPN::_rpn.pop();
			if (token == '+')
				top += RPN::_rpn.top();
			else if (token == '-')
				top = RPN::_rpn.top() - top;
			else if (token == '*')
				top *= RPN::_rpn.top();
			else if (token == '/' && top == 0)
				return (false);
			else if (token == '/')
				top = RPN::_rpn.top() / top;
			RPN::_rpn.pop();
			RPN::_rpn.push(top);
		}
		else
			return (false);
	}
	if (RPN::_rpn.size() == 1)
		return (true);
	else
		return (false);
}
