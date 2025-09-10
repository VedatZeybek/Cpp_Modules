#include "ScalarConverter.hpp"

int main()
{
	//ScalarConverter::convert("abc");
	ScalarConverter::convert("42");
	std::cout << "------\n";
	ScalarConverter::convert("a");
	std::cout << "------\n";
	ScalarConverter::convert("4.2f");
	std::cout << "------\n";
	ScalarConverter::convert("nan");
	return 0;
}
