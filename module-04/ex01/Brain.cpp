#include "Brain.hpp"
#include <sstream>

/**
 * ss.str() is to retrive the contents of the
 * stringstream object as a stardard std::string
 */
Brain::Brain()
{
	std::cout << "Brain default constructor called\n";
	for (size_t i = 0; i < _brainSize; i++)
	{
		std::stringstream ss;
		ss << "food" << i;
		_ideas[i] = ss.str();
	}
}

Brain::Brain(Brain &other)
{
	std::cout << "Brain copy constructor called\n";
	*this = other;
}

Brain::~Brain()
{
	std::cout << "Brain destructor called\n";
}

Brain& Brain::operator=(Brain &other)
{
	for (size_t i = 0; i < _brainSize; i++)
	{
		_ideas[i] = other._ideas[i];
	}
	return(*this);
}

std::string Brain::getIdeas(size_t i)
{
	if (i >= _brainSize)
		return ("");
	return (_ideas[i]);
}

void Brain::setIdeas(size_t i, std::string& str)
{
	if (i >= _brainSize)
		return;
	_ideas[i] = str;
}
