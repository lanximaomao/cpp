#ifndef BRAIN_HPP
# define BRAIN_HPP
#include <iostream>
#include <string>

class Brain
{
	private:
		static const size_t _brainSize = 100;
		std::string _ideas[_brainSize];

	public:
		Brain();
		Brain(Brain &other);
		~Brain();
		Brain& operator=(Brain &other);

		std::string getIdeas(size_t i);
		void setIdeas(size_t i, std::string &str);
};

#endif

