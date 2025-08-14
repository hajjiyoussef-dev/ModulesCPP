/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhajji <yhajji@student.42.fr>              #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-08-13 07:56:54 by yhajji            #+#    #+#             */
/*   Updated: 2025-08-13 07:56:54 by yhajji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_H
#define PHONEBOOK_H


#include <iostream>
#include <iomanip>
#include "Contact.h"

class PhoneBook
{
    private:
        Contact contact[8];
        int countContact; 
        int index;
    
    public:
        PhoneBook();

        void addContact();
        void searchContacts() const;
        std::string stringCat(std::string &str) const;
};


#endif