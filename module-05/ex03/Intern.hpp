#ifndef INTERN_HPP
# define INTERN_HPP

#include <string>
#include "AForm.hpp"

class Intern
{
	private:
		AForm* makePresidentialPardonForm(const std::string& target) const;
		AForm* makeRobotomyRequestForm(const std::string& target) const;
		AForm* makeShrubberyCreationForm(const std::string& target) const;

	public:
		Intern();
		Intern(const Intern& other);
		Intern& operator=(const Intern& other);
		virtual ~Intern();

		AForm* makeForm(const std::string& form, const std::string& target) const;
};

// define member function pointer
typedef AForm* (Intern::*createNewForm)(const std::string& target) const;

# endif
