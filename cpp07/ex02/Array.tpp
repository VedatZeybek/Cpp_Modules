#include "Array.hpp"

template <typename T>
Array<T>::Array()
{
	size = 0;
	array = new T[0];
}

template <typename T>	
Array<T>::Array(unsigned int n)
{
	array = new T[n];
	size = n;
	
	for (unsigned int i = 0; i < size; i++)
	{
		array[i] = T();
	}
		//arr[i] = T(); ifadesi, her elemanı T tipinin default değeriyle doldurur.
		//int = 0
		//double = 0.0
		//bool = false
		//std::string = ""
		//user-defined class = default constructor ile yaratılır.
}

template <typename T>
Array<T>::Array(const Array &a)
{
	//if (this != &a)
	//	*this = a; // shallow copy

	size = a.size;
    array = new T[size];
    for (unsigned int i = 0; i < size; i++)
        array[i] = a.array[i];
}

template <typename T>
Array<T>& Array<T>::operator=(const Array &a)
{
    if (this != &a)
    {
		delete[] array;
		size = a.size;
		array = new T[size];
		for (unsigned int i = 0; i < size; i++)
			array[i] = a.array[i];
    }
	return (*this);
}

template <typename T>
Array<T>::~Array()
{
	delete[] array;
}

template <typename T>
T& Array<T>::operator[](unsigned int n)
{
	if (n >= size)
	{
		throw IndexOutOfBounds();
	}
	return (array[n]);

}

template <typename T>
unsigned int Array<T>::getSize(void)
{
	return (size);
}

template <typename T>
const char *Array<T>::IndexOutOfBounds::what() const throw()
{
	return ("Index is out of bounds");
}