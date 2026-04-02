#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <map>
#include <stdexcept>
#include <cstdlib>
#include <cctype>

class BitcoinExchange
{
private:
	std::map<std::string, double> _db;

public:
	BitcoinExchange();
	BitcoinExchange(const BitcoinExchange& other);
	BitcoinExchange& operator=(const BitcoinExchange& other);
	~BitcoinExchange();

	void	loadDatabase(const std::string& filename);
	void	processInputFile(const std::string& filename);

private:
	std::string	trim(const std::string& str) const;
	bool		isValidDateFormat(const std::string& date) const;
	bool		isLeapYear(int year) const;
	bool		isValidDate(const std::string& date) const;
	bool		parseNumber(const std::string& str, double& value) const;
	double		findRateForDate(const std::string& date) const;
	void		processLine(const std::string& line) const;
};

#endif