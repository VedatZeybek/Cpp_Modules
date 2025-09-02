#include "PhoneBook.hpp"
#include <iomanip>

std::string	PhoneBook::formatColumn(const std::string &str) const
{
	if (str.length() > 10)
		return str.substr(0, 9) + ".";
	return str;
}

void	PhoneBook::displayContacts() const
{
	std::cout << "|";
	std::cout << std::setw(10) << "Index" << "|";
	std::cout << std::setw(10) << "First Name" << "|";
	std::cout << std::setw(10) << "Last Name" << "|";
	std::cout << std::setw(10) << "Nickname" << "|" << std::endl;
	std::cout << "---------------------------------------------" << std::endl;

	for (int i = 0; i < count; i++)
	{
		std::cout << "|";
		std::cout << std::setw(10) << i << "|";
		std::cout << std::setw(10) << formatColumn(contacts[i].getFirstName()) << "|";
		std::cout << std::setw(10) << formatColumn(contacts[i].getLastName()) << "|";
		std::cout << std::setw(10) << formatColumn(contacts[i].getNickname()) << "|" << std::endl;
	}
}

void	PhoneBook::searchContact(int idx) const
{
	if (idx < 0 || idx >= count)
	{
		std::cout << "Error: Invalid index." << std::endl;
		return;
	}

	const Contact &c = contacts[idx];

	std::cout << "First Name:     " << c.getFirstName() << std::endl;
	std::cout << "Last Name:      " << c.getLastName() << std::endl;
	std::cout << "Nickname:       " << c.getNickname() << std::endl;
	std::cout << "Phone Number:   " << c.getPhoneNumber() << std::endl;
	std::cout << "Darkest Secret: " << c.getDarkestSecret() << std::endl;
}

int		PhoneBook::getCount() const { return (count); }

void	PhoneBook::incrementCount(int &count) { count++; }

void	PhoneBook::addContact(Contact &contact)
{
	if (count < 8)
	{
		contacts[count] = contact;
		count++;
	}
}
