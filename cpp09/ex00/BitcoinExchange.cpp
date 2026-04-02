#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other) : _db(other._db) {}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other)
{
	if (this != &other)
		_db = other._db;
	return *this;
}

BitcoinExchange::~BitcoinExchange() {}

std::string BitcoinExchange::trim(const std::string& str) const
{
	size_t start = 0;
	size_t end = str.length();

	while (start < end && std::isspace(static_cast<unsigned char>(str[start])))
		start++;
	while (end > start && std::isspace(static_cast<unsigned char>(str[end - 1])))
		end--;

	return str.substr(start, end - start);
}

bool BitcoinExchange::isValidDateFormat(const std::string& date) const
{
	if (date.length() != 10)
		return false;
	if (date[4] != '-' || date[7] != '-')
		return false;

	for (size_t i = 0; i < date.length(); i++)
	{
		if (i == 4 || i == 7)
			continue;
		if (!std::isdigit(static_cast<unsigned char>(date[i])))
			return false;
	}
	return true;
}

bool BitcoinExchange::isLeapYear(int year) const
{
	return ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0));
}

bool BitcoinExchange::isValidDate(const std::string& date) const
{
	int year;
	int month;
	int day;
	int daysInMonth[12] = {31,28,31,30,31,30,31,31,30,31,30,31};

	if (!isValidDateFormat(date))
		return false;

	year = std::atoi(date.substr(0, 4).c_str());
	month = std::atoi(date.substr(5, 2).c_str());
	day = std::atoi(date.substr(8, 2).c_str());

	if (month < 1 || month > 12)
		return false;
	if (day < 1)
		return false;

	if (month == 2 && isLeapYear(year))
	{
		if (day > 29)
			return false;
	}
	else if (day > daysInMonth[month - 1])
		return false;

	return true;
}

bool BitcoinExchange::parseNumber(const std::string& str, double& value) const
{
	std::stringstream ss(str);
	ss >> value;
	if (ss.fail())
		return false;

	ss >> std::ws;
	if (!ss.eof())
		return false;

	return true;
}

void BitcoinExchange::loadDatabase(const std::string& filename)
{
	std::ifstream file(filename.c_str());
	std::string line;

	if (!file.is_open())
		throw std::runtime_error("Error: could not open file.");

	if (!std::getline(file, line))
		throw std::runtime_error("Error: empty database.");

	while (std::getline(file, line))
	{
		size_t commaPos;
		std::string date;
		std::string rateStr;
		double rate;

		if (line.empty())
			continue;

		commaPos = line.find(',');
		if (commaPos == std::string::npos)
			continue;

		date = trim(line.substr(0, commaPos));
		rateStr = trim(line.substr(commaPos + 1));

		if (!isValidDate(date))
			continue;
		if (!parseNumber(rateStr, rate))
			continue;

		_db[date] = rate;
	}

	if (_db.empty())
		throw std::runtime_error("Error: database is empty.");
}

double BitcoinExchange::findRateForDate(const std::string& date) const
{
	std::map<std::string, double>::const_iterator it = _db.lower_bound(date);

	if (it != _db.end() && it->first == date)
		return it->second;

	if (it == _db.begin())
		throw std::runtime_error("Error: no earlier date available.");

	--it;
	return it->second;
}

void BitcoinExchange::processLine(const std::string& line) const
{
	size_t pipePos;
	std::string date;
	std::string valueStr;
	double value;
	double rate;

	if (line.empty())
		return;

	pipePos = line.find('|');
	if (pipePos == std::string::npos)
	{
		std::cout << "Error: bad input => " << line << std::endl;
		return;
	}

	date = trim(line.substr(0, pipePos));
	valueStr = trim(line.substr(pipePos + 1));

	if (!isValidDate(date))
	{
		std::cout << "Error: bad input => " << line << std::endl;
		return;
	}

	if (!parseNumber(valueStr, value))
	{
		std::cout << "Error: bad input => " << line << std::endl;
		return;
	}

	if (value < 0)
	{
		std::cout << "Error: not a positive number." << std::endl;
		return;
	}

	if (value > 1000)
	{
		std::cout << "Error: too large a number." << std::endl;
		return;
	}

	try
	{
		rate = findRateForDate(date);
		std::cout << date << " => " << value << " = " << (value * rate) << std::endl;
	}
	catch (const std::exception&)
	{
		std::cout << "Error: bad input => " << line << std::endl;
	}
}

void BitcoinExchange::processInputFile(const std::string& filename)
{
	std::ifstream file(filename.c_str());
	std::string line;

	if (!file.is_open())
		throw std::runtime_error("Error: could not open file.");

	if (!std::getline(file, line))
		return;

	while (std::getline(file, line))
		processLine(line);
}
