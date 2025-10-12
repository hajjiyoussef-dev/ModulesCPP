/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhajji <yhajji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/12 10:34:34 by yhajji            #+#    #+#             */
/*   Updated: 2025/10/12 11:19:12 by yhajji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"


HumanA::HumanA(std::string name, Weapon& Weapon): name(name), weapon(Weapon){}

void HumanA::attack(void){
    std::cout << name << " attacks with their " << weapon.getType() << std::endl;
}