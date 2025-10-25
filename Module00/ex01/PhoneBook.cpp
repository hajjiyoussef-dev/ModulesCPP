
#include "PhoneBook.h"

PhoneBook::PhoneBook(){
    countContact = 0;
    index = 0;
};


bool is_all_digits(const std::string &s){

    for (size_t i = 0; i < s.size(); i++){
        if (s[i] == '+')
            i++;
        if (!std::isdigit((unsigned char)(s[i])))
            return (false);
    }
    return (true);
}

bool is_print(std::string str){
    
    for (size_t i = 0; i < str.size(); i++){
        if (!std::isprint(str[i]))
            return (false);
    }
    return (true);
}

void PhoneBook::addContact(){
    
    Contact newcontact ;

    std::string firstname,  lastname,   phonenumber, nickname, darkesecret;
    std::cout << "Enter first name: " ;
    if (!std::getline(std::cin, firstname)){
        std::cout << std::endl;
        return ;
    }
    while (firstname.empty() || !is_print(firstname)){
        std::cout << "Enter first name: " ;
        if (!std::getline(std::cin, firstname) || !is_print(firstname))
        {
            std::cout << std::endl;
            return ;
        }
    }
    
    std::cout << "Enter last name: " ;
    if (!std::getline(std::cin, lastname)){
        std::cout << std::endl;
        return ;
    }
    while (lastname.empty() || !is_print(lastname)){
        std::cout << "Enter last name: " ;
        if (!std::getline(std::cin, lastname) || !is_print(lastname)){
            std::cout << std::endl;
            return ;
        }
    }
    std::cout << "Enter nickname: ";
    if (!std::getline(std::cin, nickname) ){
        std::cout << std::endl;
        return ;
    }
    while (nickname.empty() || !is_print(nickname)){
        std::cout << "Enter nickname: ";
        if (!std::getline(std::cin, nickname) || !is_print(nickname)){
            std::cout << std::endl;
            return ;
        }
    }
    std::cout << "Enter phone number: ";
    if (!std::getline(std::cin, phonenumber) ){
        std::cout << std::endl;
        return ;
    }
    while (phonenumber.empty() || !is_all_digits(phonenumber) || !is_print(phonenumber)) {
        std::cout << "Enter phone number: ";
        if (!std::getline(std::cin, phonenumber) || !is_print(phonenumber)){
            std::cout << std::endl;
            return ;
        }
    }
    std::cout  << "Enter darkes Secret: ";
    if (!std::getline(std::cin, darkesecret)){
        std::cout << std::endl;
        return ;
    }
    if (darkesecret.empty() || !is_print(darkesecret)){
        while (darkesecret.empty() || !is_print(darkesecret)){
            std::cout  << "Enter darkes Secret: ";
            if (!std::getline(std::cin, darkesecret) || !is_print(darkesecret)){
                std::cout << std::endl;
                return ;
            }
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

void PhoneBook::searchContacts(){


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
    if (E_Index.empty() || !is_all_digits(E_Index)){
        std::cout << "the index is in wrong format" << std::endl;
        return;
    }
    int num = atoi(E_Index.c_str()); 
    if ( num > 8 || num < 1 || num > countContact){
        std::cout << "the index is out of range " << std::endl;
        return ;
    }
    else{
        std::cout   <<  "Index: " << contact[num - 1].getNickName() << std::endl ;
        std::cout   <<  "First Name: " << contact[num - 1].getFirstName() << std::endl ;
        std::cout   << "Last Name: " << contact[num - 1].getLastName() << std::endl ;
        std::cout   << "NicKname: "  << contact[num - 1].getNickName() << std::endl ;
        std::cout   << "phone number: "  << contact[num - 1].getPhoneNumber() << std::endl ;
        std::cout   << "darkes Secret: "  << contact[num - 1].getDarkestSecret() << std::endl ;
    }
    
}

std::string PhoneBook::stringCat(const std::string &str){
    
    if (str.length() > 10){
        return (str.substr(0, 9) + ".");
    }
    return (str);
}

