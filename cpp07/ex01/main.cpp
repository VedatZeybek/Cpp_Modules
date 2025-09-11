#include "Iter.hpp"

static void	upperCase(std::string &str)
{
	for (size_t i = 0; i < str.length(); i++)
	{
		if (str[i] >= 'a' && str[i] <= 'z')
		str[i] -= 32;
	}
}

static void	increment(int &a) { a++; }


int main()
{
	int numbers[5] = {1, 2, 3, 4, 5};

	std::cout << "Before increment: ";
	for (int i = 0; i < 5; i++) std::cout << numbers[i] << " ";
	std::cout << std::endl;
	
	iter(numbers, 5, increment);
	std::cout << "After increment:  ";
	for (int i = 0; i < 5; i++) std::cout << numbers[i] << " ";
	std::cout << std::endl;

	std::string words[3] = {"hello", "world", "cpp"};

	std::cout << "Before upperCase: ";
	for (int i = 0; i < 3; i++) std::cout << words[i] << " ";
	std::cout << std::endl;

	iter(words, 3, upperCase);
	std::cout << "After upperCase:  ";
	for (int i = 0; i < 3; i++) std::cout << words[i] << " ";
	std::cout << std::endl;

	return 0;
}