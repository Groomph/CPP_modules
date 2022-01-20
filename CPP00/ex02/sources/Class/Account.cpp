/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsanchez <rsanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 17:18:07 by rsanchez          #+#    #+#             */
/*   Updated: 2022/01/16 19:46:01 by rsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <ctime>
#include <iomanip>

using	std::cout;
using	std::endl;

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

/*************   PRIVATE   *************/ 

/*
void	Account::_displayTimestamp()
{
	std::cout << "[19920104_091532] ";
}

void	Account::_displayTimestamp()
{
	std::time_t	t;
	struct tm	*t_format;
	char		buffer[19];

	t = std::time(0);
	t_format = localtime(&t);
	strftime(buffer, 19, "[%Y%d%m_%H%M%S] ", t_format);
	cout << buffer;
}
*/

void	Account::_displayTimestamp()
{
	std::time_t	t;
	struct tm	*t_format;

	t = std::time(0);
	t_format = localtime(&t);
	cout << std::setfill('0') << '['
	<< std::setw(4) << 1900 + t_format->tm_year
	<< std::setw(2) << t_format->tm_mday
	<< std::setw(2)	<< t_format->tm_mon + 1 << '_'
	<< std::setw(2)	<< t_format->tm_hour
	<< std::setw(2)	<< t_format->tm_min
	<< std::setw(2)	<< t_format->tm_sec << "] " << std::setfill(' ');
}

/*************   PUBLIC   *************/ 

Account::Account(int initial_deposit) : _accountIndex(_nbAccounts),
					_amount(initial_deposit),
					_nbDeposits(0),
					_nbWithdrawals(0)
{
	_nbAccounts++;
	_totalAmount += initial_deposit;
	_displayTimestamp();
	cout << "index:" << _accountIndex
	<< ";amount:" << _amount
	<< ";created" << endl;
}

int	Account::getNbAccounts()
{
	return (_nbAccounts);
}

int	Account::getTotalAmount()
{
	return (_totalAmount);
}

int	Account::getNbDeposits()
{
	return (_totalNbDeposits);
}

int	Account::getNbWithdrawals()
{
	return (_totalNbWithdrawals);
}

void	Account::displayAccountsInfos()
{
	_displayTimestamp();
	cout << "accounts:" << _nbAccounts
	<< ";total:" << _totalAmount
	<< ";deposits:" << _totalNbDeposits
	<< ";withdrawals:" << _totalNbWithdrawals << endl;
}

void	Account::makeDeposit(int deposit)	
{
	_displayTimestamp();
	cout << "index:" << _accountIndex
	<< ";p_amount:" << _amount
	<< ";deposit:" << deposit;
	_amount += deposit;
	_totalAmount += deposit;
	_totalNbDeposits++;
	_nbDeposits++;
	cout << ";amount:" << _amount
	<< ";nb_deposits:" << _nbDeposits << endl;
}

bool	Account::makeWithdrawal(int withdrawal)
{
	_displayTimestamp();
	cout << "index:" << _accountIndex
	<< ";p_amount:" << _amount;
	if (withdrawal <= _amount)
	{
		_amount -= withdrawal;
		_totalAmount -= withdrawal;
		_totalNbWithdrawals++;
		_nbWithdrawals++;
		cout << ";withdrawal:" << withdrawal
		<< ";amount:" << _amount
		<< ";nb_withdrawals:" << _nbWithdrawals << endl;
		return (true);
	}
	cout << ";withdrawal:refused" << endl;
	return (false);
}

int	Account::checkAmount() const
{
	return (_amount);
}

void	Account::displayStatus() const
{
	_displayTimestamp();
	cout << "index:" << _accountIndex
	<< ";amount:" << _amount
	<< ";deposits:" << _nbDeposits
	<< ";withdrawals:" << _nbWithdrawals << endl;
}

Account::~Account()
{
	_nbAccounts--;
	_displayTimestamp();
	cout << "index:" << _accountIndex
	<< ";amount:" << _amount
	<< ";closed" << endl;
}
