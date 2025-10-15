
#ifndef PHONEBOOK_H
#define PHONEBOOK_H


#include <iostream>
#include <iomanip>
#include "Contact.h"
#include <string.h>

#include <cstdlib>

class PhoneBook
{
    private:
        Contact contact[8];
        int countContact; 
        int index;
    
    public:
        PhoneBook();

        void addContact();
        void searchContacts();
        std::string stringCat(const std::string &str);
};


#endif