/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrami <hrami@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/16 01:19:41 by yhajji            #+#    #+#             */
/*   Updated: 2025/08/17 06:27:00 by hrami            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"


int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;


Account::Account( int initial_deposit ) :

    _accountIndex(_nbAccounts),
    _amount(_totalAmount),
    _nbDeposits(_totalNbDeposits),
    _nbWithdrawals(_totalNbWithdrawals)

    {
        _nbAccounts++;
        _totalAmount += initial_deposit;

        _displayTimestamp();
        std::cout   << " index:" << _accountIndex <<  ";"
                    << "amount:" << _amount << ";"
                    << "created" << std::endl;
    }

Account::~Account( void ){
    _displayTimestamp();
    std::cout   << "index:" << _accountIndex << ";"
                << "amount:" << _amount << ";"
                << "closed" << std::endl;
}


void Account::_displayTimestamp( void ){
    
    std::time_t currentTime  = std::time(nullptr);
    std::tm *localTime = std::localtime(&currentTime);
    std::cout   << "["
                << ( 1900 + localTime->tm_year )
                << localTime->tm_mon + 1
                << localTime->tm_mday << "_"
                << localTime->tm_hour
                << localTime->tm_min
                << localTime->tm_sec
                << "]";
}

void Account::makeDeposit(int deposit){
    _displayTimestamp();
    std::cout   << " index:" <<  _accountIndex << ";"
                << "p_amount:" << _amount;

    _amount += deposit;
    _nbDeposits += 1;
    _totalAmount += deposit;
    _totalNbDeposits += 1;
    std::cout   << ";deposit:" << deposit << ";"
                << "amount:" << _amount << "; "
                << "nb_deposits:" << _nbDeposits 
                << std::endl;
}

bool Account::makeWithdrawal( int withdrawal ){
    _displayTimestamp();
    std::cout   << " index:" << _accountIndex << ";"
                << "p_amount:" << _amount;
    if ( _amount < withdrawal){
        std::cout << ";withdrawal:refused" << std::endl;
        return (false);
    }
    
    _amount -= withdrawal;
    _nbWithdrawals += 1;
    _nbWithdrawals += 1;
    std::cout   << ";withdrawal:" << withdrawal
                << ";amount:" << _amount
                << ";nb_withdrawals:" << _nbWithdrawals
                << std::endl;
    return (true);
}

int Account::checkAmount(void) const {
    
    return (_amount);
}

void Account::displayStatus(void ) const {
    _displayTimestamp();
    std::cout   << " index:" << _accountIndex << ";"
                << "amount:" << _amount << ";"
                << "deposits:" << _nbDeposits <<  ";"
                << "withdrawals:" << _nbWithdrawals
                << std::endl;
}


void Account::displayAccountsInfos( void ) {
    _displayTimestamp();
    std::cout   << " accounts:" << _nbAccounts << ";"
                << "total:" << _totalAmount << ";"
                << "deposits:" << _totalNbDeposits << ";"
                << "withdrawals:" << _totalNbWithdrawals 
                << std::endl;
    return ;
}

int Account::getNbAccounts(void ){

    return (_nbAccounts);
}

int Account::getTotalAmount(void ){

    return (_totalAmount);
}

int Account::getNbDeposits(void ){

    return (_totalNbDeposits);
}

int Account::getNbWithdrawals(void ){

    return (_totalNbWithdrawals);
}

