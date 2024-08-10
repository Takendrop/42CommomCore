/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwozniak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 20:26:52 by jwozniak          #+#    #+#             */
/*   Updated: 2024/08/10 20:26:53 by jwozniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include <ctime>
#include "Account.hpp"

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

void	Account::_displayTimestamp()
{
	char buffer[20];
	std::time_t t = std::time(0);
	std::tm* now = std::localtime(&t);
	std::strftime(buffer, sizeof(buffer), "[%Y%m%d_%H%M%S]", now);
	std::cout << buffer << " ";
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
    std::cout << "accounts:" << _nbAccounts 
	      << ";total:" << _totalAmount 
	      << ";deposits:" << _totalNbDeposits 
	      << ";withdrawals:" << _totalNbWithdrawals 
	      << std::endl;
}

Account::Account(int initial_deposit) : 
    _amount(initial_deposit), 
    _nbDeposits(0), 
    _nbWithdrawals(0) 
{
    _accountIndex = _nbAccounts;
    _nbAccounts++;
    _totalAmount += initial_deposit;
    _displayTimestamp();
    std::cout << "index:" << _accountIndex 
	      << ";amount:" << _amount 
	      << ";created" 
	      << std::endl;
}

Account::~Account()
{
    _displayTimestamp();
    std::cout << "index:" << _accountIndex 
	      << ";amount:" << _amount 
	      << ";closed" 
	      << std::endl;
}

void	Account::makeDeposit(int deposit)
{
    _displayTimestamp();
    std::cout << "index:" << _accountIndex 
	      << ";p_amount:" << _amount 
	      << ";deposit:" << deposit;
    _amount += deposit;
    _nbDeposits++;
    _totalAmount += deposit;
    _totalNbDeposits++;
    std::cout << ";amount:" << _amount 
	      << ";nb_deposits:" << _nbDeposits 
	      << std::endl;
}

bool	Account::makeWithdrawal(int withdrawal)
{
    _displayTimestamp();
    std::cout << "index:" << _accountIndex 
	      << ";p_amount:" << _amount;
    if (withdrawal > _amount) {
	std::cout << ";withdrawal:refused" << std::endl;
	return (false);
    }
    _amount -= withdrawal;
    _nbWithdrawals++;
    _totalAmount -= withdrawal;
    _totalNbWithdrawals++;
    std::cout << ";withdrawal:" << withdrawal 
	      << ";amount:" << _amount 
	      << ";nb_withdrawals:" << _nbWithdrawals 
	      << std::endl;
    return (true);
}

int	Account::checkAmount() const
{
    return (_amount);
}

void	Account::displayStatus() const
{
    _displayTimestamp();
    std::cout << "index:" << _accountIndex 
	      << ";amount:" << _amount 
	      << ";deposits:" << _nbDeposits 
	      << ";withdrawals:" << _nbWithdrawals 
	      << std::endl;
}
