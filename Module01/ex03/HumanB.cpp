/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhajji <yhajji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/12 11:05:49 by yhajji            #+#    #+#             */
/*   Updated: 2025/11/18 02:01:37 by yhajji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"



HumanB::HumanB(std::string name) : name(name), weapon(NULL){
    
    weapon
}


void HumanB::setWeapon(Weapon &weapon){
    this->weapon =  &weapon;
}

void HumanB::attack(void){
 
    if (weapon)
        std::cout << name << " attacks with their " << weapon->getType() << std::endl;
    else 
        std::cout << name <<  " has no weapon" << std::endl;
}