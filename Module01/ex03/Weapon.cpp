/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhajji <yhajji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 12:02:05 by yhajji            #+#    #+#             */
/*   Updated: 2025/10/12 10:12:08 by yhajji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"


Weapon::Weapon(std::string type) : type(type){}


std::string Weapon::getType(void){
    return (type);
}

void Weapon::setType(std::string value){
    this->type = value;
}









