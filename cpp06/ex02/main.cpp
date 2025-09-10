#include "Identify.hpp"
#include <iostream>
#include <cstdlib>
#include "ctime"

int main()
{
	std::srand(std::time(NULL));

	Base* b1 = generate();

	Base* b2 = generate();

	Base* b3 = generate();

	std::cout << "Using pointer identify:" << std::endl;
	identify(b1);
	identify(b2);
	identify(b3);

	std::cout << "Using reference identify:" << std::endl;
	identify(*b1);
	identify(*b2);
	identify(*b3);

	delete b1;
	delete b2;
	delete b3;

	return 0;
}
