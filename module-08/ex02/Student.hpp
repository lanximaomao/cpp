#ifndef STUDENT_HPP
# define STUDENT_HPP

#include <string>

class Student
{
	private:
		std::string		_name;
		float			_score;
	public:
		Student();
		~Student();
		Student(const std::string name, const float score);
		Student(const Student& other);
		Student& operator=(const Student& other);

		std::string&	getName();
		float			getScore();
		bool			operator>(const Student& other);
		bool			operator<(const Student& other);
		bool			operator==(const Student& other);
};

std::ostream& operator<<(std::ostream& out, Student &s);

#endif
