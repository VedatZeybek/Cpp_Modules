#include "MutantStack.hpp"
#include <iostream>

int main()
{
	MutantStack<int> mstack;

	mstack.push(5);
	mstack.push(17);
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);

	std::cout << "top: " << mstack.top() << std::endl;
	std::cout << "size: " << mstack.size() << std::endl;

	std::cout << "\n--- begin() / end() with iterator ---" << std::endl;
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();

	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}

	std::cout << "\n--- const begin() / const end() with const_iterator ---" << std::endl;
	const MutantStack<int> constStack = mstack;
	MutantStack<int>::const_iterator cit = constStack.begin();
	MutantStack<int>::const_iterator cite = constStack.end();

	while (cit != cite)
	{
		std::cout << *cit << std::endl;
		++cit;
	}

	std::cout << "\n--- rbegin() / rend() with reverse_iterator ---" << std::endl;
	MutantStack<int>::reverse_iterator rit = mstack.rbegin();
	MutantStack<int>::reverse_iterator rite = mstack.rend();

	while (rit != rite)
	{
		std::cout << *rit << std::endl;
		++rit;
	}

	std::cout << "\n--- const rbegin() / const rend() with const_reverse_iterator ---" << std::endl;
	MutantStack<int>::const_reverse_iterator crit = constStack.rbegin();
	MutantStack<int>::const_reverse_iterator crite = constStack.rend();

	while (crit != crite)
	{
		std::cout << *crit << std::endl;
		++crit;
	}

	return 0;
}