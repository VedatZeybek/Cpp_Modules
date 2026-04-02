#include <iostream>
#include <string>
#include "Array.hpp"

int main()
{
	std::cout << "===== Empty array test =====" << std::endl;
	Array<int> empty;
	std::cout << "empty.size() = " << empty.size() << std::endl;

	std::cout << "\n===== Int array test =====" << std::endl;
	Array<int> numbers(5);

	for (unsigned int i = 0; i < numbers.size(); i++)
		numbers[i] = i * 10;

	for (unsigned int i = 0; i < numbers.size(); i++)
		std::cout << "numbers[" << i << "] = " << numbers[i] << std::endl;

	std::cout << "\n===== String array test =====" << std::endl;
	Array<std::string> words(3);
	words[0] = "hello";
	words[1] = "42";
	words[2] = "istanbul";

	for (unsigned int i = 0; i < words.size(); i++)
		std::cout << "words[" << i << "] = " << words[i] << std::endl;

	std::cout << "\n===== Copy constructor test =====" << std::endl;
	Array<int> copy(numbers);
	copy[0] = 999;

	std::cout << "Original numbers[0] = " << numbers[0] << std::endl;
	std::cout << "Copy copy[0] = " << copy[0] << std::endl;

	std::cout << "\n===== Assignment operator test =====" << std::endl;
	Array<int> assigned;
	assigned = numbers;
	assigned[1] = 555;

	std::cout << "Original numbers[1] = " << numbers[1] << std::endl;
	std::cout << "Assigned assigned[1] = " << assigned[1] << std::endl;

	std::cout << "\n===== Out of bounds test =====" << std::endl;
	try
	{
		std::cout << numbers[100] << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << "Exception caught: " << e.what() << std::endl;
	}

	std::cout << "\n===== Const array test =====" << std::endl;
	const Array<int> constArr(3);
	std::cout << "constArr.size() = " << constArr.size() << std::endl;
	std::cout << "constArr[0] = " << constArr[0] << std::endl;

	return 0;
}