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




void Account::_displayTimestamp( void ){
    
    std::time_t currentTime  = std::time(nullptr);
    std::tm *localTime = std::localtime(&currentTime);
    std::cout   << "["
                << localTime->tm_yday
                << localTime->tm_mon
                << localTime->tm_mday << "_"
                << localTime->tm_hour
                << localTime->tm_min
                << localTime->tm_sec
                << "]";
}

void Account::makeDeposit(int deposit){
    _displayTimestamp();
    std::cout   << "index:" <<  _accountIndex << ";"
                << "p_amount:" << _amount;

    _amount += deposit;
    _nbDeposits += 1;
    _totalAmount += deposit;
    _totalNbDeposits += 1;
    std::cout   << ";deposit:" << deposit << ";"
                << "amount:" << _amount
                << "nb_deposits" << _nbDeposits 
                << std::endl;
}

bool Account::makeWithdrawal( int withdrawal ){
    _displayTimestamp();
    std::cout   << "index:" << _accountIndex << ";"
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

void Account::displayStatus(void ){
    _displayTimestamp();
    std::cout   << "index:" << _accountIndex << ";"
                << "amount:" << _amount << ";"
                << "deposits:" << _nbDeposits <<  ";"
                << "withdrawals:" << _nbWithdrawals
                << std::endl;
}


int Account::getNbAccounts(void ){

    return (_nbAccounts);
}

int Account::getTotalAmount(void ){

    return (_totalAmount);
}

int Account::getNbDeposits(void ){

    return (_nbDeposits);
}

int Account::getNbWithdrawals(void ){

    return (_totalNbWithdrawals);
}

void Account::displayAccountsInfos(void ){
    _displayTimestamp();
    std::cout   << "index:" << _accountIndex << ";"
                << "amount:" << _amount << ";"
                << "deposits:" << _nbDeposits << ";"
                << "withdrawals:" << _nbWithdrawals 
                << std::endl;
    return ;
}