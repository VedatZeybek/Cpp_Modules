#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <exception>
#include <algorithm>
#include <iterator>
#include <climits>

class Span
{
private:
	unsigned int		_maxSize;
	std::vector<int>	_numbers;

public:
	Span();
	Span(unsigned int N);
	Span(const Span& other);
	Span& operator=(const Span& other);
	~Span();

	void addNumber(int number);

	template <typename Iterator>
	void addRange(Iterator begin, Iterator end)
	{
		unsigned int distance = static_cast<unsigned int>(std::distance(begin, end));
		if (_numbers.size() + distance > _maxSize)
			throw FullSpanException();
		_numbers.insert(_numbers.end(), begin, end);
	}

	int shortestSpan() const;
	int longestSpan() const;

	class FullSpanException : public std::exception
	{
	public:
		virtual const char* what() const throw();
	};

	class NoSpanException : public std::exception
	{
	public:
		virtual const char* what() const throw();
	};
};

#endif