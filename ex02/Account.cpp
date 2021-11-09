#include "Account.hpp"
#include <iostream>
#include <iomanip>

int	Account::getNbAccounts() { return _nbAccounts; }
int Account::getTotalAmount() { return _totalAmount; }
int Account::getNbDeposits(){ return _totalNbDeposits; }
int Account::getNbWithdrawals(){ return _totalNbWithdrawals; }

void	Account::displayAccountsInfos()
{
	_displayTimestamp();
	std::cout	<< "accounts:" << getNbAccounts() << ";"
				<< "total:" << getTotalAmount() << ";"
				<< "deposits:" << getNbDeposits() << ";"
				<< "withdrawals:" << getNbWithdrawals()
				<< std::endl;
}

Account::Account(int initial_deposit)	:	_accountIndex(_nbAccounts++), 
											_amount(initial_deposit),
											_nbDeposits(0),	
											_nbWithdrawals(0)
{
	_displayTimestamp();
	std::cout	<< "index:" << _accountIndex << ";"
				<< "amount:" << _amount << ";"
				<< "created"
				<< std::endl;
	_totalAmount += _amount;
}

Account::~Account()
{
	_displayTimestamp();
	std::cout	<< "index:" << _accountIndex << ";"
				<< "amount:" << _amount << ";"
				<< "closed"
				<< std::endl;
}

void	Account::makeDeposit(int deposit)
{
	_displayTimestamp();
	std::cout	<< "index:" << _accountIndex << ";"
				<< "p_amount:" << _amount << ";"
				<< "deposit:" << deposit << ";";
	_amount += deposit;
	_totalAmount += deposit;
	_nbDeposits++;
	_totalNbDeposits++;
	std::cout	<< "amount:" << _amount << ";"
				<< "nb_deposits:" << _nbDeposits
				<< std::endl;
}

bool	Account::makeWithdrawal(int withdrawal)
{
	_displayTimestamp();
		std::cout	<< "index:" << _accountIndex << ";"
					<< "p_amount:" << _amount << ";"
					<< "withdrawal:";
	if (_amount < withdrawal)
	{
		std::cout	<< "refused" << std::endl;
		return false;
	}
	else
	{
		_amount -= withdrawal;
		_totalAmount -= withdrawal;
		_nbWithdrawals++;
		_totalNbWithdrawals++;
		std::cout	<< withdrawal << ";"
					<< "amount:" << _amount << ";"
					<< "nb_withdrawals:" << _nbWithdrawals
					<< std::endl;
		return true;
	}
}

int	Account::checkAmount() const
{
	return _amount;
}

void	Account::displayStatus() const
{
	_displayTimestamp();
	std::cout	<< "index:" << _accountIndex << ";"
				<< "amount:" << _amount << ";"
				<< "deposits:" << _nbDeposits << ";"
				<< "withdrawals:" << _nbWithdrawals
				<< std::endl;
}

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

void	Account::_displayTimestamp()
{
	time_t		current = time(0);
	const tm*	local = localtime(&current);
	std::cout	<< "["
				<< local->tm_year + 1900
				<< std::setw(2) << std::setfill('0')
				<< local->tm_mon + 1
				<< std::setw(2) << std::setfill('0')
				<< local->tm_mday
				<< "_"
				<< std::setw(2) << std::setfill('0')
				<< local->tm_hour
				<< std::setw(2) << std::setfill('0')
				<< local->tm_min
				<< std::setw(2) << std::setfill('0')
				<< local->tm_sec
				<< "] ";
}

Account::Account()	:	_accountIndex(_nbAccounts++), _amount(0),
						_nbDeposits(0),	_nbWithdrawals(0)
{
	_displayTimestamp();
	std::cout	<< "index:" << _accountIndex << ";"
				<< "amount:" << _amount << ";"
				<< "created"
				<< std::endl;
	_totalAmount += _amount;
}
