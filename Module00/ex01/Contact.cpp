/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhajji <yhajji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 09:34:26 by yhajji            #+#    #+#             */
/*   Updated: 2025/10/07 18:16:16 by yhajji           ###   ########.fr       */
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

std::string Contact::getFirstName() {
    return firstName;
}

std::string Contact::getLastName() {
    return lastName;
}

std::string Contact::getNickName() {
    return nickName;
}
std::string Contact::getPhoneNumber() {
    return phoneNumber;
}

std::string Contact::getDarkestSecret(){
    return darkestSecret;
}