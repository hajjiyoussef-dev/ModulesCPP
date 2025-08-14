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

    std::string firstname,  lastname,   phonenumber, nickname, darkesecret;
    std::cout << "Enter first name " ;
    std::getline(std::cin, firstname);
    if (firstname.empty()){
        while (firstname.empty()){
            std::cout << "Enter first name " ;
            std::getline(std::cin, firstname);
        }
    }
    std::cout << "Enter last name " ;
    std::getline(std::cin, lastname);
    if (lastname.empty()){
        while (lastname.empty()){
            std::cout << "Enter last name " ;
            std::getline(std::cin, lastname);
        }
    }
    std::cout << "Enter nickname ";
    std::getline(std::cin, nickname);
    if (nickname.empty()){
        while (nickname.empty()){
            std::cout << "Enter nickname ";
            std::getline(std::cin, nickname);
        }
    }
    std::cout << "Enter phone number ";
    std::getline(std::cin, phonenumber);
    if (phonenumber.empty()){
        while (phonenumber.empty()){
            std::cout << "Enter phone number ";
            std::getline(std::cin, phonenumber);
        }
    }
    std::cout  << "Enter darkes Secret ";
    std::getline(std::cin, darkesecret);
    if (darkesecret.empty()){
        while (darkesecret.empty()){
            std::cout  << "Enter darkes Secret ";
            std::getline(std::cin, darkesecret);
        }
    }
    newcontact.setFirstName(firstname);
    newcontact.setLastName(lastname);
    newcontact.setNickName(nickname);
    newcontact.setPhoneNumber(phonenumber);
    newcontact.setDarkestSecret(darkesecret);

    contact[index] = newcontact;

    index = (index + 1) % 8;
    if (countContact < 8)
        countContact++;
    
}

void PhoneBook::searchContacts() const{

    if (countContact == 0 )
        return;
    

    std::cout << "Index | First Name | last Name | NicName " << std::endl;
    for (int i = 0; i < countContact && i < 8; i++){
        std::cout   << std::setw(10) << i + 1 <<  "|"
                    << std::setw(10) << stringCat(contact[i].getFirstName())
    }
    

}


std::string PhoneBook::stringCat(std::string &str) const{
    
    if (str.length() > 10){
        return (str.substr(0, 9) + ".");
    }
    return (str);
}

