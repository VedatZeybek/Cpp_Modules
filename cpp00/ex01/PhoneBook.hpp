#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "iostream"
#include "Contact.hpp"

class PhoneBook
{
private:
	Contact contacts[8];
	int		count;

public:

	PhoneBook();
	
	std::string		formatColumn(const std::string &str) const;
	void			incrementCount(int &count);
	int				getCount() const;
	void			displayContacts() const;
	void			searchContact(int idx) const;
	void			addContact(Contact &contact);
};


#endif