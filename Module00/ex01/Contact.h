/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrami <hrami@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 09:32:32 by yhajji            #+#    #+#             */
/*   Updated: 2025/08/15 06:40:40 by hrami            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_H
#define CONTACT_H

#include <iostream>
#include <cctype>

class Contact
{
private:
    std::string firstName;
    std::string lastName;
    std::string nickName;
    std::string phoneNumber;
    std::string darkestSecret;
public:
    
   void setFirstName(std::string  value);
   void setLastName(std::string  value);
   void setNickName(std::string  value);
   void setPhoneNumber(std::string  value);
   void setDarkestSecret(std::string  value);


   std::string getFirstName() const;
   std::string getLastName() const;
   std::string getNickName() const;
   std::string getPhoneNumber() const;
   std::string getDarkestSecret() const;
    
};



#endif