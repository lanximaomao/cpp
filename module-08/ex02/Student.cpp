#include "Student.hpp"
#include <iostream>

Student::Student(): _name("unknown"), _score(0) {};
Student::~Student() {};

Student::Student(std::string name, float score)
:_name(name), _score(score)
{

}

Student::Student(Student& other)
{
	*this = other;
}

Student& Student::operator=(Student& other)
{
	_name = other._name;
	_score = other._score;
	return(*this);
}

std::string& Student::getName()
{
	return (_name);
}

float Student::getScore()
{
	return (_score);
}

bool Student::operator<(Student& other)
{
	return(_score < other._score);
}

bool Student::operator>(Student& other)
{
	return(_score > other._score);
}

bool Student::operator==(Student& other)
{
	return(_score == other._score);
}

std::ostream& operator<<(std::ostream& out, Student &s)
{
	std::cout << s.getName() << s.getScore() << std::endl;
	return (out);
}

