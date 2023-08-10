#ifndef ANIMAL_HPP
# define ANIMAL_HPP
# include <string>

class Animal
{
	protected:
		std::string _type;
		std::string _name;

	public:
		Animal();
		Animal(const std::string name);
		Animal(const Animal &other);
		virtual ~Animal();
		Animal& operator=(const Animal &other);

		std::string getName() const;
		std::string getType() const;

		virtual void makeSound() const;
};

# endif
