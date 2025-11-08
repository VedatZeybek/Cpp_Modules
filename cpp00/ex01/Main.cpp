#include "PhoneBook.hpp"
#include "Contact.hpp"
#include <cstdlib>
#include <string>

int	main()
{
	PhoneBook	phoneBook;
	std::string	command;

	while (1)
	{
		std::cout << "Enter	command	(ADD, SEARCH, EXIT): ";
		if (!std::getline(std::cin,	command))
			break ;

		if (command	== "ADD") 
		{
			std::string	fn,	ln,	nn,	pn,	ds;
			std::cout << "First	Name: ";
			std::getline(std::cin, fn);
			std::cout << "Last Name: ";
			std::getline(std::cin, ln);
			std::cout << "Nickname:	";
			std::getline(std::cin, nn);
			std::cout << "Phone	Number:	";
			std::getline(std::cin, pn);
			std::cout << "Darkest Secret: ";
			std::getline(std::cin, ds);

			if (fn.empty() || ln.empty() || nn.empty() || pn.empty() || ds.empty())
			{
				std::cout << "All fields must be filled!\n";
				continue;
			}

			Contact	c;
			c.setContact(fn, ln, nn, pn, ds);
			phoneBook.addContact(c);
		}
		else if (command == "SEARCH")
		{
			if (phoneBook.getCount() == 0) {
				std::cout << "PhoneBook	is empty!\n";
				continue;
			}
			phoneBook.displayContacts();

			std::cout << "Enter	index to view details: ";
			std::string	idxStr;
			std::getline(std::cin, idxStr);
			if (idxStr.empty())	continue;

			int	idx	= atoi(idxStr.c_str());
			phoneBook.searchContact(idx);
		}
		else if (command == "EXIT")	{
			exit(EXIT_SUCCESS);
		}
	}
	return 0;
}
