#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <iostream>

class Contact
{
	private:
		std::string	_first_name;
		std::string	_last_name;
		std::string	_nick_name;
		std::string	_secret;
		std::string	_number;

	public:
		Contact();
		~Contact();

		void setFirstName(std::string _first_name);
		void setLastName(std::string _last_name);
		void setNickName(std::string _nick_name);
		void setSecret(std::string _secret);
		void setNumber(std::string _number);

		std::string	getFirstName() const;
		std::string getLastName() const;
		std::string getNickName() const;
		std::string getSecret() const;
		std::string getNumber() const;
};


#endif
