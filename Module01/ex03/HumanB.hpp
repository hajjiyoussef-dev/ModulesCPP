/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhajji <yhajji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/12 11:01:42 by yhajji            #+#    #+#             */
/*   Updated: 2025/10/12 11:05:37 by yhajji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
#define HUMANB_HPP


#include <iostream>
#include "Weapon.hpp"

class HumanB
{
private:
    std::string name;
    Weapon* weapon;
public:
    HumanB(std::string name);
    void setWeapon(Weapon &weapon);
    void attack(void);
};



#endif