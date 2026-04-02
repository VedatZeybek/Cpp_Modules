#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include "easyfind.hpp"

static void testVector()
{
	std::vector<int> v;

	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	v.push_back(40);

	std::cout << "Vector test:" << std::endl;
	try
	{
		std::vector<int>::iterator it = easyfind(v, 30);
		std::cout << "Found in vector: " << *it << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	try
	{
		std::vector<int>::iterator it = easyfind(v, 99);
		std::cout << "Found in vector: " << *it << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << "Vector error: " << e.what() << std::endl;
	}
}

static void testList()
{
	std::list<int> l;

	l.push_back(1);
	l.push_back(2);
	l.push_back(3);
	l.push_back(4);

	std::cout << "\nList test:" << std::endl;
	try
	{
		std::list<int>::iterator it = easyfind(l, 2);
		std::cout << "Found in list: " << *it << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	try
	{
		std::list<int>::iterator it = easyfind(l, 42);
		std::cout << "Found in list: " << *it << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << "List error: " << e.what() << std::endl;
	}
}

static void testDeque()
{
	std::deque<int> d;

	d.push_back(7);
	d.push_back(14);
	d.push_back(21);
	d.push_back(28);

	std::cout << "\nDeque test:" << std::endl;
	try
	{
		std::deque<int>::iterator it = easyfind(d, 21);
		std::cout << "Found in deque: " << *it << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	try
	{
		std::deque<int>::iterator it = easyfind(d, -5);
		std::cout << "Found in deque: " << *it << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << "Deque error: " << e.what() << std::endl;
	}
}

static void testConstContainer()
{
	const std::vector<int> v(3, 5);

	std::cout << "\nConst container test:" << std::endl;
	try
	{
		std::vector<int>::const_iterator it = easyfind(v, 5);
		std::cout << "Found in const vector: " << *it << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << "Const vector error: " << e.what() << std::endl;
	}
}

int main()
{
	testVector();
	testList();
	testDeque();
	testConstContainer();
	return (0);
}