/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdeniz <Discord:@teomandeniz>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 18:00:03 by hdeniz            #+#    #+#             */
/*   Updated: 2024/02/01 18:00:29 by hdeniz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* **************************** [v] INCLUDES [v] **************************** */
#include "Account.hpp" /*
#  class Account;
#*/
#include <ctime> /*
#    ??? std::time(std::time_t*);
#     tm *localtime(std::time_t*);
#*/
#include <iostream> /*
#namespc std;
#*/
# include <iomanip> /*
#     ??? std::setw(int);
#    char std::setfill(char);
#*/
/* **************************** [^] INCLUDES [^] **************************** */

/* ***************************** [v] USING [v] ****************************** */
using std::cout;
using std::flush;
using std::endl;
/* ***************************** [^] USING [^] ****************************** */

int	Account::_nbAccounts = 0;
int	Account::_totalAmount= 0;
int	Account::_totalNbDeposits= 0;
int	Account::_totalNbWithdrawals = 0;

/******************************************************************************\
|*                                                                            *|
|* We need to remove the "static" keyword                                     *|
|* because: https://stackoverflow.com/questions/15725922/                     *|
|*                                                                            *|
\******************************************************************************/

void
	Account::_displayTimestamp(void)
{
	std::time_t	result;

	result = std::time(NULL);
	cout << std::setfill('0') << "[" \
		<< 1900 + std::localtime(&result)->tm_year \
		<< std::setw(2) << 1 + std::localtime(&result)->tm_mon \
		<<  std::setw(2) << std::localtime(&result)->tm_mday \
		<<  "_" \
		<<  std::setw(2) << std::localtime(&result)->tm_hour \
		<<  std::setw(2) << std::localtime(&result)->tm_min \
		<<  std::setw(2) << std::localtime(&result)->tm_sec \
		<< "] " << flush;
}

Account::Account(int initial_deposit) /* CONSTRUCTOR */
{
	++_nbAccounts;
	_accountIndex = _nbAccounts - 1;
	_amount = initial_deposit;
	_totalAmount += _amount;
	_nbDeposits = 0;
	_nbWithdrawals = 0;
	this->_displayTimestamp();
	cout << "index:" << _accountIndex << ";" \
		<< "amount:" << _amount << ";" \
		<< "created" << endl;
}

Account::~Account(void) /* DESTRUCTOR */
{
	--_nbAccounts;
	this->_displayTimestamp();
	cout << "index:" << _accountIndex << ";" \
		<< "amount:" << _amount << ";" \
		<< "closed" << endl;
}

/* *************** [v] ACCESSING PRIVATE CLASS VARAIBLES [v] **************** */
int
	Account::getNbAccounts(void)
{
	return (_nbAccounts);
}

int
	Account::getTotalAmount(void)
{
	return (_totalAmount);
}

int
	Account::getNbDeposits(void)
{
	return (_totalNbDeposits);
}

int
	Account::getNbWithdrawals(void)
{
	return (_totalNbWithdrawals);
}
/* *************** [^] ACCESSING PRIVATE CLASS VARAIBLES [^] **************** */

void
	Account::displayAccountsInfos(void)
{
	_displayTimestamp();
	cout << "accounts:" << getNbAccounts() << ";" \
		<< "total:" << getTotalAmount() << ";" \
		<< "deposits:" << getNbDeposits() << ";" \
		<< "withdrawals:" << getNbWithdrawals() << endl;
}

// Accessing account detail private info
void
	Account::makeDeposit(int deposit)
{
	this->_displayTimestamp();
	++_nbDeposits;
	++_totalNbDeposits;
	_totalAmount += deposit;
	cout << "index:" << _accountIndex << ";" \
		<< "p_amount:" << _amount << ";" << flush;
	_amount += deposit;
	cout << "deposit:" << deposit << ";" \
		<< "amount:" << _amount << ";" \
		<< "nb_deposit:" << _nbDeposits << endl;
}

bool
	Account::makeWithdrawal(int withdrawal)
{
	this->_displayTimestamp();
	cout << "index:" << _accountIndex << ";" \
		<< "p_amount:" << _amount << ";" \
		<< "withdrawal:" << flush;
	if (withdrawal > checkAmount())
	{
		cout << "refused" << endl;
		return (false);
	}
	cout << withdrawal << ";" << flush;
	++_nbWithdrawals;
	++_totalNbWithdrawals;
	_totalAmount -= withdrawal;
	_amount -= withdrawal;
	cout << "amount:" << _amount << ";" \
		<< "nb_deposit:" << _nbDeposits << endl;
	return (true);
}

int
	Account::checkAmount(void) const
{
	return (_amount);
}

void
	Account::displayStatus(void) const
{
	this->_displayTimestamp();
	cout << "index:" << _accountIndex << ";" \
		<< "amount:" << _amount << ";" \
		<< "deposits:" << _nbDeposits << ";" \
		<< "withdrawals:" << _nbWithdrawals << endl;
}