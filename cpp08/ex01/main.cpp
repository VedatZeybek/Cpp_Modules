#include "Span.hpp"
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

int main()
{
	try
	{
		std::cout << "----- Subject Test -----" << std::endl;
		Span sp(5);

		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);

		std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
		std::cout << "Longest span : " << sp.longestSpan() << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}

	std::cout << std::endl;

	try
	{
		std::cout << "----- Full Span Test -----" << std::endl;
		Span sp(2);

		sp.addNumber(1);
		sp.addNumber(2);
		sp.addNumber(3);
	}
	catch (std::exception& e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}

	std::cout << std::endl;

	try
	{
		std::cout << "----- No Span Test -----" << std::endl;
		Span sp(5);

		sp.addNumber(42);
		std::cout << sp.shortestSpan() << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}

	std::cout << std::endl;

	try
	{
		std::cout << "----- Range Add Test -----" << std::endl;
		Span sp(10);
		std::vector<int> values;

		values.push_back(100);
		values.push_back(104);
		values.push_back(108);
		values.push_back(109);
		values.push_back(110);

		sp.addRange(values.begin(), values.end());

		std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
		std::cout << "Longest span : " << sp.longestSpan() << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}

	std::cout << std::endl;

	try
	{
		std::cout << "----- 10000 Numbers Test -----" << std::endl;
		Span bigSpan(10000);
		std::vector<int> bigVec;

		std::srand(std::time(NULL));
		for (int i = 0; i < 10000; i++)
			bigVec.push_back(std::rand());

		bigSpan.addRange(bigVec.begin(), bigVec.end());

		std::cout << "Shortest span: " << bigSpan.shortestSpan() << std::endl;
		std::cout << "Longest span : " << bigSpan.longestSpan() << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}

	return 0;
}