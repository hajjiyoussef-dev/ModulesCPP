/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrami <hrami@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 08:25:15 by yhajji            #+#    #+#             */
/*   Updated: 2025/08/15 06:43:06 by hrami            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "PhoneBook.h"



int main(void){

    PhoneBook pb;

    std::string cmd;

    while(true){
        std::cout << "enter one of three commands (ADD, SEARCH and EXIT): ";
        std::getline(std::cin, cmd);
        if (strcmp(cmd.c_str(), "ADD") == 0){
            pb.addContact();
        }
        else if (strcmp(cmd.c_str(), "SEARCH") == 0){
            pb.searchContacts();
        }
        else if (strcmp(cmd.c_str(), "EXIT") == 0){
            break;
        }
    }
    return (0);
}