#include "Account.hpp"
#include "iostream"
#include <ctime>

int	Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

// constructor

Account::Account( int initial_deposit )
:	_accountIndex(_nbAccounts),
	_amount(initial_deposit),
	_nbDeposits(0),
	_nbWithdrawals(0)
{
	_nbAccounts++;
	_totalAmount += initial_deposit;

	_displayTimestamp();
	std::cout	<< "index:" << _accountIndex;
	std::cout	<< ";amount:" << _amount;
	std::cout	<< ";created" << std::endl;
}

//destructor

Account::~Account( void )
{
	_displayTimestamp();
	std::cout	<< "index:" << _accountIndex;
	std::cout	<< ";amount:" << _amount;
	std::cout	<< ";closed" << std::endl;
}


//getters

int	Account::getNbAccounts()
{
	return (_nbAccounts);
}

int	Account::getTotalAmount( void )
{
	return (_totalAmount);
}

int	Account::getNbDeposits( void )
{
	return (_totalNbDeposits);
}
int	Account::getNbWithdrawals( void )
{
	return (_totalNbWithdrawals);
}

//member functions

void	Account::displayAccountsInfos( void )
{
	_displayTimestamp();
	std::cout << "accounts:" << _nbAccounts << ";";
	std::cout << "total:" << _totalAmount << ";";
	std::cout << "deposits:" << _totalNbDeposits << ";";
	std::cout << "witdrawals:" << _totalNbWithdrawals << std::endl;
}


void	Account::makeDeposit( int deposit )
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex;
	std::cout << ";p_amount:" << _amount;
	std::cout << ";deposit:" << deposit;

	_amount += deposit;
	_nbDeposits++;
	_totalAmount += deposit;
	_totalNbDeposits++;

	std::cout << ";amount:" << _amount;
	std::cout << ";nb_deposits:" << _nbDeposits;
	std::cout << std::endl;
}

bool	Account::makeWithdrawal( int withdrawal )
{
	_displayTimestamp();
	std::cout	<< "index:" << _accountIndex
				<< ";p_amount:" << _amount
				<< ";withdrawal:";

	if (withdrawal > _amount)
	{
		std::cout << "refused" << std::endl;
		return (false);
	}

	_amount -= withdrawal;
	_nbWithdrawals++;
	_totalAmount -= withdrawal;
	_totalNbWithdrawals++;

	std::cout	<< withdrawal
				<< ";amount:" << _amount
				<< ";nb_withdrawals:" << _nbWithdrawals
				<< std::endl;

	return (true);
}

int		Account::checkAmount( void ) const
{
	return (_amount);
}

void	Account::displayStatus( void ) const
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex
			  << ";amount:" << _amount
			  << ";deposits:" << _nbDeposits
			  << ";withdrawals:" << _nbWithdrawals
			  << std::endl;
}

void	Account::_displayTimestamp()
{
	time_t	time_now = std::time(NULL);
	tm		*ltm = std::localtime(&time_now);
	std::cout	<< "[" 
				<< 1900 + ltm->tm_year
				<< (ltm->tm_mon + 1 < 10 ? "0" : "") << ltm->tm_mon + 1
				<< (ltm->tm_mday < 10 ? "0" : "") << ltm->tm_mday
				<< "_"
				<< (ltm->tm_hour < 10 ? "0" : "") << ltm->tm_hour
				<< (ltm->tm_min < 10 ? "0" : "") << ltm->tm_min
				<< (ltm->tm_sec < 10 ? "0" : "") << ltm->tm_sec
				<< "] ";
}
