#include "ScalarConverter.hpp"
#include <string>
#include <limits>
#include <cmath>
#include <cstdlib>
#include <cerrno>
#include <iomanip>

ScalarConverter::ScalarConverter() {}
ScalarConverter::ScalarConverter(ScalarConverter const& other) { *this = other; }
ScalarConverter & ScalarConverter::operator=(ScalarConverter const& other) {  if (this != &other) {}  return (*this); }
ScalarConverter::~ScalarConverter() {}

static bool isChar(const std::string& str)  {     return str.length() == 3 && str[0] == '\'' && str[2] == '\'';}

static bool isInt(const std::string& str) 
{
	char* end;
	long val = std::strtol(str.c_str(), &end, 10);
	return *end == '\0'
		&& val <= std::numeric_limits<int>::max()
		&& val >= std::numeric_limits<int>::min();
}

static bool isFloat(const std::string& str) {
	if (str == "nanf" || str == "+inff" || str == "-inff")
		return true;
	char* end;
	std::strtod(str.c_str(), &end);
	return *end == 'f' && *(end + 1) == '\0';
}

static bool isDouble(const std::string& str) {
	if (str == "nan" || str == "+inf" || str == "-inf")
		return true;
	char* end;
	std::strtod(str.c_str(), &end);
	return *end == '\0';
}

static void printConversions(char c)
{
	std::cout << "char: '" << c << "'\n";
	std::cout << "int: " << static_cast<int>(c) << "\n";
	std::cout << "float: " << static_cast<float>(c) << "f\n";
	std::cout << "double: " << static_cast<double>(c) << "\n";
}

static void printConversions(int i)
{
	if (i >= 32 && i <= 126)
		std::cout << "char: '" << static_cast<char>(i) << "'\n";
	else
		std::cout << "char: Non displayable\n";
	std::cout << "int: " << i << "\n";
	std::cout << "float: " << static_cast<float>(i) << "f\n";
	std::cout << "double: " << static_cast<double>(i) << "\n";
}

static void printConversions(float f)
{
	if (std::isnan(f) || std::isinf(f))
		std::cout << "char: impossible\nint: impossible\n";
	else if (f >= 32 && f <= 126)
		std::cout << "char: '" << static_cast<char>(f) << "'\n";
	else
		std::cout << "char: Non displayable\n";

	if (f > std::numeric_limits<int>::max() || f < std::numeric_limits<int>::min())
		std::cout << "int: impossible\n";
	else
		std::cout << "int: " << static_cast<int>(f) << "\n";

	std::cout << "float: " << f << "f\n";
	std::cout << "double: " << static_cast<double>(f) << "\n";
}

static void printConversions(double d)
{
	if (std::isnan(d) || std::isinf(d))
		std::cout << "char: impossible\nint: impossible\n";
	else if (d >= 32 && d <= 126)
		std::cout << "char: '" << static_cast<char>(d) << "'\n";
	else
		std::cout << "char: Non displayable\n";

	if (d > std::numeric_limits<int>::max() || d < std::numeric_limits<int>::min())
		std::cout << "int: impossible\n";
	else
		std::cout << "int: " << static_cast<int>(d) << "\n";

	if (d > std::numeric_limits<float>::max() || d < -std::numeric_limits<float>::max())
		std::cout << "float: impossible\n";
	else
		std::cout << "float: " << static_cast<float>(d) << "f\n";

	std::cout << "double: " << d << "\n";
}

void ScalarConverter::convert(const std::string& literal) 
{
	std::cout << std::fixed << std::setprecision(1);

	if (isChar(literal))
	{
		char c = literal[1];
		printConversions(c);
	}
	else if (isInt(literal))
	{
		char* end;
		long val = std::strtol(literal.c_str(), &end, 10);
		if (*end != '\0' || val > std::numeric_limits<int>::max() || val < std::numeric_limits<int>::min())
			throw std::runtime_error("Invalid int");
		printConversions(static_cast<int>(val));
	}
	else if (isFloat(literal))
	{
		float f;
		if (literal == "nanf") f = std::numeric_limits<float>::quiet_NaN();
		else if (literal == "+inff") f = std::numeric_limits<float>::infinity();
		else if (literal == "-inff") f = -std::numeric_limits<float>::infinity();
		else {
			char* end;
			f = std::strtof(literal.c_str(), &end);
			if (*end != 'f' || *(end + 1) != '\0')
				throw std::runtime_error("Invalid float");
		}
		printConversions(f);
	}
	else if (isDouble(literal))
	{
		double d;
		if (literal == "nan") d = std::numeric_limits<double>::quiet_NaN();
		else if (literal == "+inf") d = std::numeric_limits<double>::infinity();
		else if (literal == "-inf") d = -std::numeric_limits<double>::infinity();
		else {
			char* end;
			d = std::strtod(literal.c_str(), &end);
			if (*end != '\0')
				throw std::runtime_error("Invalid double");
		}
		printConversions(d);
	}

	else 
	{
		std::cout << "Error: Unknown literal type.\n";
	}
}
