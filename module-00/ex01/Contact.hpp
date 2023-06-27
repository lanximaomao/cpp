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
		Contact(void);
		~Contact(void);

		void setFirstName(std::string _first_name);
		void setLastName(std::string _last_name);
		void setNickName(std::string _nick_name);
		void setSecret(std::string _secret);
		void setNumber(std::string _number);

		std::string	getFirstName(void) const;
		std::string getLastName(void) const;
		std::string getNickName(void) const;
		std::string getSecret(void) const;
		std::string getNumber(void) const;
};


#endif
