#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"
# include <iostream>

# define MAX_CONTACT 8

class PhoneBook
{
  private:
	int			_index;
	int			_count;
	Contact		_record[MAX_CONTACT];
	Contact*	_getContact(void);
	void		_add(void);
	void		_search(void) const;
	int			getTotal(void);

  public:
	PhoneBook(void);
	~PhoneBook(void);
	void		op(std::string op);
};

#endif
