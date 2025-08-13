/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhajji <yhajji@student.42.fr>              #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-08-13 09:32:32 by yhajji            #+#    #+#             */
/*   Updated: 2025-08-13 09:32:32 by yhajji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_H
#define CONTACT_H

#include <iostream>

class Contact
{
private:
    std::string firstName;
    std::string lastName;
    std::string nickName;
    std::string phoneNumber;
    std::string darkestSecret;
public:
    
   void Contact::setFirstName(std::string value);
   void Contact::setLastName(std::string value);
   void Contact::setNickName(std::string value);
   void Contact::setPhoneNumber(std::string value);
   void Contact::setDarkestSecret(std::string value);


   std::string getFirstName() const;
   std::string getLastName() const;
   std::string getNickName() const;
   std::string getPhoneNumber() const;
   std::string getDarkestSecret() const;
    
};



#endif