#include "Contact.hpp"

Contact::Contact(void)
{
	//std::cout << "constructor for contact is called " << std::endl;
}

Contact::~Contact(void)
{
	//std::cout << "destructor for Contact call is called" << std::endl;
}

void Contact::setFirstName(std::string first_name)
{
	this->_first_name = first_name;
}

void Contact::setLastName(std::string last_name)
{
	this->_last_name = last_name;
}

void Contact::setNickName(std::string nick_name)
{
	this->_nick_name = nick_name;
}

void Contact::setSecret(std::string secret)
{
	this->_secret = secret;
}

void Contact::setNumber(std::string number)
{
	this->_number = number;
}

std::string	Contact::getFirstName(void) const
{
	return (this->_first_name);
}

std::string Contact::getLastName(void) const
{
	return(this->_last_name);
}

std::string Contact::getNickName(void) const
{
	return(this->_nick_name);
}

std::string Contact::getSecret(void) const
{
	return(this->_secret);
}

std::string Contact::getNumber(void) const
{
	return(this->_number);
}
