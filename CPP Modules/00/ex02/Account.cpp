/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcollar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 14:05:06 by flcollar          #+#    #+#             */
/*   Updated: 2022/05/21 15:20:19 by flcollar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <ctime>

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

Account::Account(void) {}

Account::Account(int initial_deposit)
{
	this->_amount = initial_deposit;
	this->_accountIndex = _nbAccounts;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;
	_nbAccounts++;
	_totalAmount += initial_deposit;
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";amount:" << this->_amount << ";created\n";
}

Account::~Account()
{
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";amount:" << this->_amount << ";closed\n";
}

void	Account::_displayTimestamp(void)
{
	char			buff[100];
	std::time_t		time = std::time(nullptr);
	std::tm			*timeinfo = std::localtime(&time);

	std::strftime(buff, 100, "%Y%m%d_%H%M%S", timeinfo);
	std::cout << "[" << buff << "] ";
}

int		Account::getNbAccounts(void)
{
	return _nbAccounts;
}

int		Account::getTotalAmount(void)
{
	return _totalAmount;
}

int		Account::getNbDeposits(void)
{
	return _totalNbDeposits;
}

int		Account::getNbWithdrawals(void)
{
	return _totalNbWithdrawals;
}

void	Account::displayAccountsInfos(void)
{
	Account::_displayTimestamp();
	std::cout << "accounts:" << _nbAccounts << ";total:" << _totalAmount << ";deposits:"
		<< _totalNbDeposits << ";withdrawals" << _totalNbWithdrawals << "\n";
}

void	Account::makeDeposit(int deposit)
{
	this->_amount += deposit;
	this->_nbDeposits++;
	Account::_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";p_amount:" << this->_amount - deposit << ";deposit:"
		<< deposit << ";amount:" << this->_amount << ";nb_deposits:" << this->_nbDeposits << "\n";
}

bool	Account::makeWithdrawal(int withdrawal)
{
	if (this->_amount - withdrawal < 0) {
		Account::_displayTimestamp();
		std::cout << "index:" << _accountIndex << ";p_amount:" << this->_amount << ";withdrawal:refused\n";
		return (false);
	}

	else {
		this->_amount -= withdrawal;
		this->_nbWithdrawals++;
		Account::_displayTimestamp();
		std::cout << "index:" << _accountIndex << ";p_amount:" << this->_amount - withdrawal << ";withdrawal:"
			<< withdrawal << ";amount:" << this->_amount << ";nb_withdrawal:" << this->_nbWithdrawals << "\n";
		return (true);
	}
}

int		Account::checkAmount(void) const
{
	return this->_amount;
}

void	Account::displayStatus(void) const
{
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";amount:" << this->_amount << ";deposits:"
		<< this->_nbDeposits << ";withdrawals:" << this->_nbWithdrawals << "\n";
}