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
		Student(std::string name, float score);
		~Student();
		Student(Student& other);
		Student& operator=(Student& other);

		std::string&	getName();
		float			getScore();
		bool			operator>(Student& other);
		bool			operator<(Student& other);
		bool			operator==(Student& other);
};

std::ostream& operator<<(std::ostream& out, Student &s);

#endif
