#ifndef ARRAY_HPP
#define ARRAY_HPP


#include <cstdlib>
#include <ctime> 
#include "exception"


template <typename T>
class Array
{
private:
	T*			array;
	unsigned int size;
public:
	Array();
	Array(unsigned int n);
	Array(const Array &a);
	Array &operator=(const Array &a);
	~Array();

	class	IndexOutOfBounds: public std::exception
	{
		public:
			virtual const char *	what() const throw();
	};

	T &operator[](unsigned int n);
	unsigned int getSize();
};


#include "Array.tpp"


#endif