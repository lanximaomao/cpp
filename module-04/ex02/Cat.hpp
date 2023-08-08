#ifndef CAT_HPP
# define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat: public Animal
{
	private:
		Brain* _tinyBrain;

	public:
		Cat();
		Cat(const std::string name);
		Cat(const Cat &other);
		virtual ~Cat();
		Cat& operator=(const Cat &other);

		virtual void makeSound() const;
		Brain* getBrain() const;
};

# endif

