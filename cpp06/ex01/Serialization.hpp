#ifndef SERIALIZATION_HPP
#define SERIALIZATION_HPP

#include <iostream>

#include <stdint.h>

struct Data	{
std::string data_string;
int data_int;
};

class Serialization
{
private:

	Serialization();
	Serialization(Serialization const & src);
	Serialization & operator=(Serialization const & rhs);
	~Serialization();

public:
		static uintptr_t serialize(Data* ptr); // takes a pointer andd converts it to the unsgined integer imteger type uintptr_t
		static Data* deserialize(uintptr_t raw); // unsigned integer parameter and converts it to a pointer of type Data
};



#endif