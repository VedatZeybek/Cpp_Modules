#include "Identify.hpp"
#include <cstdlib>
#include <ctime>

Base* generate() 
{
	int r = std::rand() % 3; 
	if (r == 0)
		return new A;
	else if (r == 1)
		return new B;
	else
		return new C;
}

void identify(Base* p)
{
	if (!p) return;
	if (dynamic_cast<A*>(p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "C" << std::endl;
}

// Identify type using reference and dynamic_cast
void identify(Base& p)
{
	try {
		A& a = dynamic_cast<A&>(p);
		(void)a;
		std::cout << "A" << std::endl;
		return;
	} catch (...) {}

	try {
		B& b = dynamic_cast<B&>(p);
		(void)b;
		std::cout << "B" << std::endl;
		return;
	} catch (...) {}

	try {
		C& c = dynamic_cast<C&>(p);
		(void)c;
		std::cout << "C" << std::endl;
		return;
	} catch (...) {}
}
