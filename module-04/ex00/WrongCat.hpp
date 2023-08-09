#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP
#include "WrongCat.hpp"

class WrongCat: public WrongAnimal
{
	public:
		WrongCat();
		WrongCat(const std::string name);
		WrongCat(const WrongCat &other);
		~WrongCat();
		WrongCat& operator=(const WrongCat &other);

		void makeSound() const;
};

# endif

