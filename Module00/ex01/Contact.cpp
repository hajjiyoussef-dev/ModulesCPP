/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhajji <yhajji@student.42.fr>              #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-08-13 09:34:26 by yhajji            #+#    #+#             */
/*   Updated: 2025-08-13 09:34:26 by yhajji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.h"


void Contact::setFirstName(std::string value){
    firstName = value;
}
void Contact::setLastName(std::string value){
    lastName = value;
}
void Contact::setNickName(std::string value){
    nickName = value;
}
void Contact::setPhoneNumber(std::string value){
    phoneNumber = value;
}
void Contact::setDarkestSecret(std::string value){
    darkestSecret = value;
}

std::string Contact::getFirstName() const{
    return firstName;
}

std::string Contact::getLastName() const{
    return lastName;
}

std::string Contact::getNickName() const{
    return nickName;
}
std::string Contact::getPhoneNumber() const{
    return phoneNumber;
}

std::string Contact::getDarkestSecret() const{
    return darkestSecret;
}