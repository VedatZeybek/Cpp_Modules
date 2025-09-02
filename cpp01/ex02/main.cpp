#include <iostream>


int main()
{
	std::string str = "HI THIS IS BRAIN";
	std::string *strPTR = &(str);
	std::string &strREF = str;

	std::cout << "The memory address of the string variable:	" << &str << "\n";
	std::cout << "The memory address held by stringPTR:		" << strPTR << "\n";
	std::cout << "The memory address held by stringREF:		" << &strREF << "\n";

	std::cout << "-------------------------------\n" ;

	std::cout << "The value of the string variable:		" << str << "\n";
	std::cout << "The value pointed to by stringPTR:		" << *strPTR << "\n";
	std::cout << "The value pointed to by stringREF:		" << strREF << "\n";

}