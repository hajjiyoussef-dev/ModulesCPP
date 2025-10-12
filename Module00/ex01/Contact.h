/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhajji <yhajji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 09:32:32 by yhajji            #+#    #+#             */
/*   Updated: 2025/10/07 18:16:01 by yhajji           ###   ########.fr       */
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


   std::string getFirstName() ;
   std::string getLastName() ;
   std::string getNickName() ;
   std::string getPhoneNumber() ;
   std::string getDarkestSecret() ;
    
};



#endif