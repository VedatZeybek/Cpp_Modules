#include "Span.hpp"

Span::Span() : _maxSize(0) {}

Span::Span(unsigned int N) : _maxSize(N) {}

Span::Span(const Span& other) : _maxSize(other._maxSize), _numbers(other._numbers) {}

Span& Span::operator=(const Span& other)
{
	if (this != &other)
	{
		_maxSize = other._maxSize;
		_numbers = other._numbers;
	}
	return *this;
}

Span::~Span() {}

void Span::addNumber(int number)
{
	if (_numbers.size() >= _maxSize)
		throw FullSpanException();
	_numbers.push_back(number);
}

int Span::shortestSpan() const
{
	if (_numbers.size() < 2)
		throw NoSpanException();

	std::vector<int> temp(_numbers);
	std::sort(temp.begin(), temp.end());

	int shortest = INT_MAX;
	for (size_t i = 1; i < temp.size(); i++)
	{
		int diff = temp[i] - temp[i - 1];
		if (diff < shortest)
			shortest = diff;
	}
	return shortest;
}

int Span::longestSpan() const
{
	if (_numbers.size() < 2)
		throw NoSpanException();

	int minVal = *std::min_element(_numbers.begin(), _numbers.end());
	int maxVal = *std::max_element(_numbers.begin(), _numbers.end());

	return maxVal - minVal;
}

const char* Span::FullSpanException::what() const throw()
{
	return "Span is full";
}

const char* Span::NoSpanException::what() const throw()
{
	return "Not enough elements to find a span";
}
