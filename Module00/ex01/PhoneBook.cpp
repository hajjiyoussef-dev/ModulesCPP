/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrami <hrami@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 08:20:18 by yhajji            #+#    #+#             */
/*   Updated: 2025/08/17 06:22:56 by hrami            ###   ########.fr       */
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
    std::cout << "Enter first name: " ;
    if (!std::getline(std::cin, firstname)){
        std::cout << std::endl;
        return ;
    }
    while (firstname.empty()){
        std::cout << "Enter first name: " ;
        std::getline(std::cin, firstname);
    }
    std::cout << "Enter last name: " ;
    if (!std::getline(std::cin, lastname)){
        std::cout << std::endl;
        return ;
    }
    while (lastname.empty()){
        std::cout << "Enter last name: " ;
        std::getline(std::cin, lastname);
    }
    std::cout << "Enter nickname: ";
    if (!std::getline(std::cin, nickname)){
        std::cout << std::endl;
        return ;
    }
    while (nickname.empty()){
        std::cout << "Enter nickname: ";
        std::getline(std::cin, nickname);
    }
    std::cout << "Enter phone number: ";
    if (!std::getline(std::cin, phonenumber)){
        std::cout << std::endl;
        return ;
    }
    while (phonenumber.empty() || !std::all_of(phonenumber.begin(), phonenumber.end(), ::isdigit)) {
        std::cout << "Enter phone number: ";
        std::getline(std::cin, phonenumber);
    }
    std::cout  << "Enter darkes Secret: ";
    if (!std::getline(std::cin, darkesecret)){
        std::cout << std::endl;
        return ;
    }
    if (darkesecret.empty()){
        while (darkesecret.empty()){
            std::cout  << "Enter darkes Secret: ";
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


    std::string E_Index;

    if (countContact == 0){
        std::cout << "Phone Book is empty " << std::endl;
        return;
    }
    std::cout   << std::setw(10) << "Index" << "|"
                << std::setw(10) << "First Name" << "|"
                << std::setw(10) << "Last Name" << "|"
                << std::setw(10) << "NicName" << "\n";
    for (int i = 0; i < countContact && i < 8; i++){
        std::cout   << std::setw(10) << i + 1 <<  "|"
                    << std::setw(10) << stringCat(contact[i].getFirstName()) << "|"
                    << std::setw(10) << stringCat(contact[i].getLastName()) << "|"
                    << std::setw(10) << stringCat(contact[i].getNickName()) << "\n";
    }

    std::cout << "Enter Index: ";
    std::getline(std::cin, E_Index);
    if (E_Index.empty() || !std::all_of(E_Index.begin(), E_Index.end(), ::isdigit)){
        std::cout << "the index is in wrong format" << std::endl;
        return;
    }
    int num = atoi(E_Index.c_str()); 
    if ( num > 8 || num < 1 || num > countContact){
        std::cout << "the index is out of range " << std::endl;
        return ;
    }
    else{
        std::cout   <<  "First Name: " << contact[num - 1].getFirstName() << std::endl ;
        std::cout   << "Last Name: " << contact[num - 1].getLastName() << std::endl ;
        std::cout   << "NicKname: "  << contact[num - 1].getNickName() << std::endl ;
    }
    
}

std::string PhoneBook::stringCat(const std::string &str) const{
    
    if (str.length() > 10){
        return (str.substr(0, 9) + ".");
    }
    return (str);
}

