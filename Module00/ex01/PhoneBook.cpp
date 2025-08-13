/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhajji <yhajji@student.42.fr>              #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-08-13 08:20:18 by yhajji            #+#    #+#             */
/*   Updated: 2025-08-13 08:20:18 by yhajji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.h"



PhoneBook::PhoneBook(){
    countContact = 0;
    index = 0;
};

void PhoneBook::addContact(){
    
    Contact newcontact ;

    std::string firstname,  lastname,   phonenumber;
    std::cout << "Enter first name " ;
    std::getline(std::cin, firstname);
    std::cout << "Enter last name " ;
    std::cin >> lastname;
    std::getline(std::cin, lastname);
    std::cout << "Enter phone number ";
    std::getline(std::cin, phonenumber);

    newcontact.setFirstName(firstname);
    newcontact.setLastName(lastname);
    newcontact.setPhoneNumber(phonenumber);

    contact[newcontact]

}

